BUILDSRC = SortList.h SortList.cpp SortNode.h SortNode.cpp
TESTSRC = main.cpp $(BUILDSRC) #Change this if your test code is a different file
TEST = test #The name of the output test program.

CC = g++
CFLAGS = --std=c++98 -g -Wall -Wextra# -Werror
#Uncomment -Werror to hold yourself to a high standard

SUBMIT = u22510657.tar #Put your student number here

all: $(TEST)

$(TEST): $(TESTSRC)
	$(CC) $(CFLAGS) $< -o $@

run: $(TEST)
	./main

submit: $(BUILDSRC)
	tar -cvz $^ -f $(SUBMIT)

clean:
	rm $(TEST) $(SUBMIT)