CC=g++
CFLAGS= -g -Wall -Werror -std=gnu99 -Iinclude

encode: encode.c
	$(CC) $(CFLAGS) -o $@ $<
