SHELL:=/bin/zsh
CC=gcc
#INCLUDE_PATH=/usr/lib/modules/4.9.11-1-ARCH/build/arch/x86/include/asm/
CFLAGS=-g -DDEBUG -Wall -O0 -I./libjoe/
LDLIBS=
OBJECT=./libjoe/*.o
FILE=$1

all:
	$(CC) -D_REENTRANT -c $(CFLAGS) $$CURR.c
	$(CC) $(LDLIBS) -pthread -o $$CURR $$CURR.o $(OBJECT)

$(FILE): $(FILE).o $(OBJECT)
	$(CC) $(LDLIBS) -lpthread -o $(FILE) $(FILE).o $(OBJECT)

$(FILE).o: $(FILE).c
	$(CC) -D_REENTRANT -c $(CFLAGS) $(FILE).c

$(OBJECT):
	make -C ./libjoe/

clean:
	rm -rf $$CURR.o $$CURR
	rm -rf $(FILE) $(FILE).o
