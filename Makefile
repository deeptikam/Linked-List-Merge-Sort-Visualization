
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

OBJS = main.o list.o sort.o

all: sort

sort: $(OBJS)
	$(CC) $(CFLAGS) -o sort $(OBJS)

main.o: main.c list.h sort.h
list.o: list.c list.h
sort.o: sort.c list.h sort.h

clean:
	rm -f *.o sort
