CC=g++

#target: dependencies
#	build commands

all: main_menu

main_menu: artistList.o artist.o artistList.h artist.h
	$(CC) main_menu.cpp -o main_menu artistList.o artist.o

artistList.o: artistList.cpp artistList.h
	$(CC) artistList.cpp -o artistList.o

artist.o: artist.cpp artist.h
	$(CC) artist.cpp -o artist.o

clean:
	rm -f *.o all