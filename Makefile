CC=gcc
CFLAGS=-g -Wall -O3 -lpthread
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
