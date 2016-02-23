driver: driver.o database.o
	g++ -o driver driver.o database.o

driver.o: driver.cpp database.h
	g++ -c -o driver.o driver.cpp

database.o: database.cpp database.h
	g++ -c -o database.o database.cpp

run:
	./driver

clean:
	rm *.o driver

