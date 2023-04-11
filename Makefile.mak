automaton : Projet.o stack.o matrix.o
	gcc -o automaton $^ -Wall 

stack.o : stack.c 
	gcc -o stack.o -c stack.c -Wall 

matrix.o : matrix.c 
	gcc -o matrix.o -c matrix.c -Wall 

clear : 
	rm -rf 
	
