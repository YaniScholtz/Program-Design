main: main.o RandomGenerator.h RandomGenerator.o Chromosome.h Chromosome.o GA.h GA.o FitnessFunction.h FitnessFunction.o  
	g++  RandomGenerator.o Chromosome.o FitnessFunction.o GA.o main.o -o main

main.o: main.cpp
	g++ -c -g main.cpp
	
RandomGenerator.o: RandomGenerator.h RandomGenerator.cpp  
	g++ -c -g RandomGenerator.cpp
	
Chromosome.o: Chromosome.h Chromosome.cpp  
	 g++ -c -g Chromosome.cpp

FitnessFunction.o: FitnessFunction.h FitnessFunction.cpp  
	 g++ -c -g FitnessFunction.cpp

GA.o: GA.h GA.cpp  
	 g++ -c -g GA.cpp

run:
	  ./main 
	
clean:
	rm -f RandomGenerator.o Chromosome.o FitnessFunction.o GA.o main.o main