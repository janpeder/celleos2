#include <IPCClient.hpp>
#include <Rule.hpp>
#include <Exception.hpp>
#include <iostream>

int main(int argc, char* argv[]){
  int status = 0;
  usbguard::USBInterfaceType hid(0x03, 0, 0, usbguard::USBInterfaceType::MatchClass);
  usbguard::USBInterfaceType hub(0x09, 0, 0, usbguard::USBInterfaceType::MatchClass);
  std::vector<usbguard::USBInterfaceType> allowed_interfaces;
  allowed_interfaces.push_back(hid);
  allowed_interfaces.push_back(hub);
  usbguard::IPCClient client;
  try{
    client.connect();
  } catch(usbguard::Exception const& e) {
    std::cerr << "ERROR: Could not connect to usbguard. Context: " << e.context() << ". Object: " << e.object() << ". Reason: " << e.reason() << ".\n";
  }
      
  if(!client.isConnected()){
    status = 1;
    std::cerr << "ERROR: IPC connection to USBGuard failed.\n";
  }
  else{
    std::vector<usbguard::Rule> devices;
    try{
      devices = client.listDevices();
    } catch(usbguard::Exception const& e) {
      std::cerr << "ERROR: Could not list connected devices. Context: " << e.context() << ". Object: " << e.object() << ". Reason: " << e.reason() << ".\n";
    }
    for(size_t i = 0; i < devices.size(); i++) {
      bool allow_device = true;
      const usbguard::Rule::Attribute<usbguard::USBInterfaceType> interfaces = devices[i].attributeWithInterface();
      for(size_t j = 0; j < interfaces.count(); j++){
	bool allow_interface = false;
	for(size_t k = 0; k < allowed_interfaces.size(); k++){
	  if(allowed_interfaces[k].appliesTo(interfaces.get(j))){
	    // Interface is in list of allowed interfaces.
	    allow_interface = true;
	  }
	}
	// At least one interface on the device was not in the list of allowed interfaces.
	if(!allow_interface) allow_device = false;
      }
      if(allow_device){
	usbguard::Rule allow_rule(devices[i]);
	allow_rule.setTarget(usbguard::Rule::Target::Allow);
	// Remove the "via port" attribute, as we don't want that in our rule:
	allow_rule.attributeViaPort().clear();
	std::cout << allow_rule.toString() << "\n";
      }
    } //end for devices
    client.disconnect();
  } // end else (connection check)
  client.wait();
  return status;
}
