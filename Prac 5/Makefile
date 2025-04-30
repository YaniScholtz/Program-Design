test:*.o
	g++ -o test *.o

*.o: *.cpp
	g++ -c -g *.cpp

run:
	./test

clean:
	rm *.o test *.tar

debug:
	gdb test

tar:
	tar -cvf u22523538.tar makefile *.cpp *.h