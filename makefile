OBJS	= PQdemo.o
SOURCE	= PQdemo.cpp
HEADER	= dsexceptions.h avlClass.h binaryHeapClass.h PQ.h
OUT	= pq
CC	 = g++
FLAGS	 = -g -c 
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

PQdemo.o: PQdemo.cpp
	$(CC) $(FLAGS) PQdemo.cpp 


clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	./$(OUT)