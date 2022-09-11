

CC = gcc

CFLAGS = -Wall

CFILES = main.c

OUTPUT = cut
all:
	$(CC) $(CFILES) $(CFLAGS) -o $(OUTPUT)

clean:
	rm $(OUTPUT)