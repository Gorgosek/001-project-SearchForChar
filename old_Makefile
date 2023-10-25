# Compiler and its options
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror
SRC = keyfilter.c
OUT = keyfilter

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
