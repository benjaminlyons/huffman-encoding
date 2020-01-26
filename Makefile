CC=g++
CFLAGS= -g -Wall -Werror -std=c++11 -Iinclude

encode: encode.o
	$(CC) $(CFLAGS) -o $@ $<

encode.o: encode.cpp tree.h bitvector.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm encode.o encode
