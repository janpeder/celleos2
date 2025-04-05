TARGETNAME = celleos_usbguard_generate_policy_hub_hid

CFLAGS = -Wall `pkg-config --cflags libusbguard`
LDFLAGS = -Wall `pkg-config --libs libusbguard`

OBJS = main.o

default: $(TARGETNAME)

$(TARGETNAME): $(OBJS)
	g++ -o $(TARGETNAME) $(OBJS) $(LDFLAGS)

clean:
	rm -f $(TARGETNAME)
	rm -f $(OBJS)

main.o: main.cpp
	g++ -c main.cpp $(CFLAGS)
