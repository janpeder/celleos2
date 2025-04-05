#include <IPCClient.hpp>
#include <Rule.hpp>
#include <iostream>

int main(int argc, char* argv[]){
  int status = 0;
  std::string allowed_interfaces = "03 09";
  usbguard::IPCClient client;
  client.connect();
  if(!client.isConnected()){
    status = 1;
    std::cerr << "ERROR: IPC connection to USBGuard failed.";
  }
  else{
    std::vector<usbguard::Rule> rules = client.listDevices();
    for(long unsigned int i = 0; i < rules.size(); i++) {
      bool allow = true;
      const usbguard::Rule::Attribute<usbguard::USBInterfaceType> interface = rules[i].attributeWithInterface();
      // Because the bClass member variable is private, we have to
      // Parse the string, which is a lot uglier than just 'getting' it:
      std::string s = interface.toRuleString();
      if(s.find("{") != std::string::npos){
	// it's a list of interfaces
	size_t pos = 17;
	while(pos+1 < s.size()){
	  std::string usbclass_str = s.substr(pos, 2);
	  if(allowed_interfaces.find(usbclass_str) == std::string::npos){
	    // interface class type not in list of allowed interfaces:
	    allow = false;
	  }
	  pos += 9;
	}
	std::cout << "\n";
      }
      else{
	// a single interface
	std::string usbclass_str = s.substr(15, 2);
	if(allowed_interfaces.find(usbclass_str) == std::string::npos){
	  // interface class type not in list of allowed interfaces:
	  allow = false;
	}
      }
      if(allow) std::cout << "allow " << rules[i].toString().substr(6) << "\n";
    } //end for
  }// end else (connected)
  return status;
}

