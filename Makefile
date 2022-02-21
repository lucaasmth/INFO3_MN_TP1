all : test_pile test_file test_abr

abr.o: abr.c abr.h pile.h file.h
	gcc -Wall -c abr.c

avl.o: avl.c avl.h pile.h file.h
	gcc -Wall -c avl.c

pile.o: pile.c pile.h abr.h
	gcc -Wall -c pile.c

file.o: file.h file.c
	gcc -Wall -c file.c

test_pile.o: test_pile.c abr.h
	gcc -Wall -c test_pile.c

test_file.o: test_file.c abr.h
	gcc -g -Wall -c test_file.c

test_abr.o: test_abr.c abr.h
	gcc -Wall -c test_abr.c

test_avl.o: test_avl.c avl.h
	gcc -Wall -c test_avl.c

test_pile: test_pile.o pile.o
	gcc -o test_pile pile.o test_pile.o

test_file: test_file.o file.o
	gcc -g -o test_file file.o test_file.o

test_abr: test_abr.o pile.o file.o abr.o
	gcc -o test_abr abr.o pile.o file.o test_abr.o

test_avl: test_avl.o pile.o file.o avl.o
	gcc -o test_avl avl.o pile.o file.o test_avl.o

clean:
	rm -f *.o *~ test_pile test_abr


