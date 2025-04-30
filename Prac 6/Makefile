TEMPLATESRC = Plane Controller Exceptions
NONTEMPLATESRC = Cargo Passenger SecretCargo 

SUBMITSRC = $(addsuffix .cpp, $(TEMPLATESRC)) $(addsuffix .h, $(TEMPLATESRC)) \
$(addsuffix .cpp, $(NONTEMPLATESRC)) $(addsuffix .h, $(NONTEMPLATESRC))

BUILDSRC = $(addsuffix .cpp, $(NONTEMPLATESRC)) main.cpp

SUBMIT = u22510657.tar

CC = g++
CFLAGS = -Wall -Werror -g --std=c++98
TESTFLAGS = --leak-check=full --track-origins=yes -s

all: main

main: $(BUILDSRC)
	$(CC) $^ $(CFLAGS) -o $@

run: main
	./$<

test: main
	valgrind $(TESTFLAGS) ./$<

clean:
	rm main $(SUBMIT)

submit: $(SUBMITSRC)
	tar -cvz @^ -f $(SUBMIT)