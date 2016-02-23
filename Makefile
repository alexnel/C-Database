driver: database.o driver.o
	g++ -o driver database.o

driver.o: driver.cpp database.h
	g++ -c -o driver.o database.cpp

database.o: database.cpp database.h
	g++ -c -o database.o database.cpp




