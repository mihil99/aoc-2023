CC = gcc
CFLAGS = -Wall -Wextra -g

all: my_program

my_program: 1.c
	$(CC) $(CFLAGS) -o my_program 1.c

run: my_program
	./my_program

clean:
	rm -f my_program

