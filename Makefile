CC=g++
CFLAGS= -g -Wall -Werror -std=c++11 -Iinclude

all: encode decode

encode: encode.o
	$(CC) $(CFLAGS) -o $@ $<

decode: decode.o
	$(CC) $(CFLAGS) -o $@ $<

decode.o: decode.cpp tree.h bitvector.h
	$(CC) $(CFLAGS) -c -o $@ $<

encode.o: encode.cpp tree.h bitvector.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm encode.o encode
