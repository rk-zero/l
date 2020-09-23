CC = gcc
CFLAGS=-Wall -g -DNDEBUG

fbrenderer.o: %.c $(DEPS)

l: fbrenderer.c l.c
	$(CC) ${CFLAGS} -c fbrenderer.c -o fbrenderer.o
	$(CC) ${CFLAGS} l.c fbrenderer.o -o l