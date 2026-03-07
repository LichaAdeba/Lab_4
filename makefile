CC = gcc
CFLAGS = -Wall -Wextra -O0 -g

all: lab4

lab4: main.o sum_array.o
	$(CC) $(CFLAGS) -o lab4 main.o sum_array.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

sum_array.o: sum_array.s
	$(CC) $(CFLAGS) -c sum_array.s

clean:
	rm -f *.o lab4