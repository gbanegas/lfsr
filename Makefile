OBJS = main.o lfsr257.o lfsr4.o
CC = g++ -O3
DEBUG = -g
LIBS = -lgmp -lgmpxx
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: $(OBJS)
	$(CC) $(LIBS) $(LFLAGS) $(OBJS) -o lfsr

main.o: main.cpp lfsr.h lfsr257.h 
	$(CC) $(LIBS) $(CFLAGS) main.cpp

lfsr257.o: lfsr.h lfsr257.h lfsr257.cpp 
	$(CC) $(LIBS) $(CFLAGS) lfsr257.cpp

lfsr4.o: lfsr.h lfsr4.h lfsr4.cpp
	$(CC) $(LIBS) $(CFLAGS) lfsr4.cpp
clean:
	\rm *.o lfsr
