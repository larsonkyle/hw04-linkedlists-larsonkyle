CC=g++


all: hw04

hw04: main_menu.cpp artistList.o artist.o artistList.h artist.h
	$(CC) main_menu.cpp -o hw04 artistList.o artist.o

artistList.o: artistList.cpp artistList.h
	$(CC) -c artistList.cpp -o artistList.o

artist.o: artist.cpp artist.h
	$(CC) -c artist.cpp -o artist.o

clean:
	rm -f *.o all
