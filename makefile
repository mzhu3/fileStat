main.o: main.c
	gcc main.c -o main.o 

run: main.o
	./main.o

clean: 
	rm main.o
	rm *~
	rm *#
