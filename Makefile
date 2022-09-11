

CC = gcc

CFLAGS = -Wall

CFILES = main.c

LDINCLUDES = -pthread

OUTPUT = cut
all:
	$(CC) $(CFILES) $(CFLAGS) $(LDINCLUDES) -o $(OUTPUT)

clean:
	rm $(OUTPUT)