CC = gcc
CFLAGS = -Wall -Wextra -g
NUMBER = 1

all: my_program

my_program: $(NUMBER).c
	$(CC) $(CFLAGS) -o my_program $(NUMBER).c

run: my_program
	./my_program $(NUMBER).input

clean:
	rm -f my_program
