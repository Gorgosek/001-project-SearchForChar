CFLAGS = -std=c11 -Wall -Wextra 
CC = gcc
TARGET = keyfilter
SRC = keyfilter.c
OBJS = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS) $(TARGET)
## CC=gcc
## CFLAGS=-std=c11 -Wall -Wextra -Werror
## keyfilter: keyfilter.c
## 	$(CC) $(CFLAGS) keyfilter.c -o keyfilter
## 
test:
	./test_keyfilter.sh

