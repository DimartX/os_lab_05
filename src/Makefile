CC = gcc

all: at_time_main before_main

before_main: libdeque.so before_main.c
	$(CC) before_main.c -L. -ldeque -o before_main

at_time_main: libdeque.so at_time_main.c
	$(CC) at_time_main.c -ldl -o at_time_main

libdeque.so: deque.o
	$(CC) -shared deque.o -o libdeque.so

deque.o:
	$(CC) -fPIC -c deque.c -o deque.o


clean:
	rm -f deque.o
	rm -f at_time_main
	rm -f before_main
