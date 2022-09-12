

CC = gcc

CFLAGS = -Wall -Wextra --std=c99

CFILES = main.c reader.c analyser.c printer.c

LDINCLUDES = -pthread

OUTPUT = cut
all:
	$(CC) $(CFILES) $(CFLAGS) $(LDINCLUDES) -o $(OUTPUT)

clean:
	rm $(OUTPUT)