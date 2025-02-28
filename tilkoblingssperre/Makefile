TARGETNAME = tilkoblingssperre

CFLAGS = -Wall `pkg-config --cflags gtk4`
LDFLAGS = -Wall `pkg-config --libs gtk4`

OBJS = main.o

default: $(TARGETNAME)

$(TARGETNAME): $(OBJS)
	gcc -o $(TARGETNAME) $(OBJS) $(LDFLAGS)

clean:
	rm -f $(TARGETNAME)
	rm -f $(OBJS)

main.o:
	gcc -c main.c $(CFLAGS)
