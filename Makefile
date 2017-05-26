CC=gcc
#INCLUDE_PATH=/usr/lib/modules/4.9.11-1-ARCH/build/arch/x86/include/asm/
CFLAGS=-g -Wall -O3
LDLIBS=
OBJECT=
FILE=
THREAD=


$(FILE): $(FILE).o $(OBJECT)
ifeq ($(THREAD), true)
	$(CC) $(LDLIBS) -lpthread -o $(FILE) $(FILE).o
else
	$(CC) $(LDLIBS) -o $(FILE) $(FILE).o
endif

$(FILE).o: $(FILE).c
ifeq ($(THREAD), true)
		$(CC) -D_REENTRANT -c $(CFLAGS) $(FILE).c
else
		$(CC) -c $(CFLAGS) $(FILE).c
endif

clean:
	rm -rf $(FILE) $(FILE).o
