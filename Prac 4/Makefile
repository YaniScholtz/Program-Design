main: main.o TwoDArray.o SumArray.o CountArray.o SortArray.o
	g++ TwoDArray.o SumArray.o CountArray.o SortArray.o main.o -o main

main.o: main.cpp Task1.cpp Task2.cpp 
	g++ -c -g main.cpp

TwoDArray.o: TwoDArray.h TwoDArray.cpp  
	 g++ -c -g TwoDArray.cpp

Task1.o: Task1.cpp TwoDArray.h
	g++ -c -g Task1.cpp

Task.2.o: Task2.cpp CountArray.h SumArray.h SortArray.h
	g++ -c -g Task2.cpp

CountArray.o: CountArray.cpp TwoDArray.h
	g++ -c -g CountArray.cpp

SortArray.o: SortArray.cpp TwoDArray.h
	g++ -c -g SortArray.cpp

SumArray.o: SumArray.cpp TwoDArray.h
	g++ -c -g SumArray.cpp	

run: main
	  ./main 
	
clean:
	rm *.o main