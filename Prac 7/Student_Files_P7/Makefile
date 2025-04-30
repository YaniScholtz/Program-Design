SUBMITSRC = Calendar.cpp Calendar.h Event.cpp Event.h Utils.h
BUILDSRC = $(wildcard *.cpp)
SUBMIT = u22630946.tar

CC = g++
CFLAGS = -Wall -Wextra -g# -Werror (commented for testing, uncomment after)
TESTFLAGS = --leak-check=full --track-origins=yes -s

all: main

main: $(BUILDSRC)
	$(CC) $^ $(CFLAGS) -o $@

test: main
	valgrind $(TESTFLAGS) ./$<

submit: $(SUBMITSRC)
	tar cvz $^ -f $(SUBMIT)

clean:
	rm $(SUBMIT) main