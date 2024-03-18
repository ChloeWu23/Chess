chess:ChessMain.o ChessBoard.o king.o castle.o bishop.o queen.o knight.o pawn.o piece.o
	g++ -Wall -g ChessMain.o ChessBoard.o king.o castle.o bishop.o queen.o knight.o pawn.o piece.o -o chess

ChessMain.o: ChessMain.cpp ChessBoard.h
	g++ -Wall -c ChessMain.cpp 

ChessBoard.o: ChessBoard.cpp ChessBoard.h
	g++ -Wall -g -c  ChessBoard.cpp

piece.o: piece.cpp piece.h
	g++ -Wall -g -c piece.cpp

king.o: king.cpp king.h
	g++ -Wall -g -c king.cpp

castle.o:castle.cpp castle.h
	g++ -Wall -g -c castle.cpp

bishop.o: bishop.cpp bishop.h
	g++ -Wall -g -c bishop.cpp

queen.o: queen.cpp queen.h
	g++ -Wall -g -c queen.cpp

knight.o: knight.cpp knight.h
	g++ -Wall -g -c knight.cpp

pawn.o: pawn.cpp pawn.h
	g++ -Wall -g -c pawn.cpp

clean:
	rm -f *.o chess
