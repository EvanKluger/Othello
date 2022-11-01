othello.exe: main.o othelloBoard.o 
	g++ -o othello.exe main.o othelloBoard.o

main.o: main.cpp othelloBoard.h create_boards.h game_loop.h
	g++ -c main.cpp

othelloBoard.o: othelloBoard.cpp othelloBoard.h
	g++ -c othelloBoard.cpp

game_loop.o: game_loop.cpp game_loop.h othelloBoard.h computer_move.h user_move.h game_loop.h
	g++ -c game_loop.cpp

create_boards.o: create_boards.cpp create_boards.h "othelloBoard.h"
	g++ -c create_boards.cpp

iterative_deeping.cpp: iterative_deepning.cpp iterative_deepaning.h alpha_beta.h

debug:
	g++ -g -o othelloDebug.exe main.cpp othelloBoard.cpp

clean:
	rm -f *.exe *.o *.stackdump *~

backup:
	test -d backups || mkdir backups
	cp *.cpp backups
	cp *.h backups
	cp Makefile backups