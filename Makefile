#Corey Parks
#CS 240
#Makefile for final project

BankAccount: main.o MenuSelector.o account.o
	g++ main.o MenuSelector.o account.o -o BankAccount

main.o: main.cpp MenuSelector.h account.h
	g++ -c main.cpp

MenuSelector.o: MenuSelector.cpp MenuSelector.h
	g++ -c MenuSelector.cpp

account.o: account.cpp account.h
	g++ -c account.cpp

clean:
	rm -f *.o
	rm BankAccount
