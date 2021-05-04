play.out : othello.o Game.o
	g++ othello.o Game.o -o play.out

othello.o : othello.cpp Game.h
	g++ -c -g othello.cpp

Game.o : Game.cpp Game.h 
	g++ -c -g Game.cpp

clean :
	rm *.o *.out Game[12].[ch]*
