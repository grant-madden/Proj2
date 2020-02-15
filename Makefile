#Variables
CC = g++
CFLAGS = -g -std=c++11

# Linking all the files

## Intro 
a.exe: date.o date.h friend.o friend.h fbfriends.o fbfriends.h main.o
	$(CC) $(CFLAGS) date.o friend.o fbfriends.o main.o -o a.exe


## Body
date.o: date.cc date.h
	$(CC) -c $(CFLAGS) date.cc -o date.o

fbfriends.o: fbfriends.cc fbfriends.h
	$(CC) -c $(CFLAGS) fbfriends.cc -o fbfriends.o

friend.o: friend.cc friend.h
	$(CC) -c $(CFLAGS) friend.cc -o friend.o


## Conclusion
main.o: main.cc date.h 
	$(CC) -c $(CFLAGS) main.cc -o main.o
