main: main.o student.o
	g++ student.o main.o -o main

main.o: main.cpp student.h 
	g++ -c -g main.cpp

student.o: student.h student.cpp  
	 g++ -c -g student.cpp

run: main
	  ./main 
	
clean:
	rm *.o main