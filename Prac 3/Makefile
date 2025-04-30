studentmain: studentmain.o chessboard.h chessboard.o chesspiece.h chesspiece.o  
	g++  chessboard.o chesspiece.o studentmain.o -o studentmain

studentmain.o: studentmain.cpp
	g++ -c -g studentmain.cpp

chessboard.o: chessboard.h chessboard.cpp  
	 g++ -c -g chessboard.cpp

chesspiece.o: chesspiece.h chesspiece.cpp
	g++ -c -g chesspiece.cpp

run:
	  ./studentmain 
	
clean:
	rm -f chessboard.o chesspiece.o studentmain.o studentmain