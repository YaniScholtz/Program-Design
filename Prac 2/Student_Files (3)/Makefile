studentmain: studentmain.o matrix.h matrix.o  
	g++  matrix.o studentmain.o -o studentmain

studentmain.o: studentmain.cpp
	g++ -c -g studentmain.cpp

matrix.o: matrix.h matrix.cpp  
	 g++ -c -g matrix.cpp

run:
	  ./studentmain 
	
clean:
	rm -f matrix.o studentmain.o studentmain