CC = gcc

CFLAGS = -Wall
LDFLAGS = -lbtk -lglfw

SRC = $(wildcard *.c)

EXEC = $(SRC:.c=)

all: $(EXEC)


%: %.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f $(EXEC)
