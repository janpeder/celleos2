TARGETNAME = tilkoblingssperre

CFLAGS = -Wall `pkg-config --cflags gtk4`
LDFLAGS = -Wall `pkg-config --libs gtk4`

OBJS = main.o resources.o

default: $(TARGETNAME)

$(TARGETNAME): $(OBJS)
	gcc -o $(TARGETNAME) $(OBJS) $(LDFLAGS)

clean:
	rm -f $(TARGETNAME)
	rm -f $(OBJS)

resources.o: resources.xml resources/tilkoblingssperre.ui
	glib-compile-resources --generate-source resources.xml
	gcc -c resources.c $(CFLAGS)
	rm -f resources.c

main.o: main.c
	gcc -c main.c $(CFLAGS)
