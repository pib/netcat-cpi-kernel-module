CFLAGS=-I$(PWD)/tracks 

all: netcat

netcat: netcat.c
	gcc $(CFLAGS) netcat.c -o netcat

clean:
	rm netcat
