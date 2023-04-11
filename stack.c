#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define SIZE 100

//On commence par creer les outils avec lesquels on vas travailler les piles
struct stack {
    int content[SIZE];
    int top;
};

stack new() {
    stack s ;
    s.top = -1;
    return s ; 
}; 


int vide(stack s) {
    return (s.top<0);
}


void push(stack *s , int e ){
    if (s->top == SIZE-1 ){
        printf("Le stack est full");
        return;
    }
    s->top +=1 ; 
    s->content[s->top]=e ; 
}

int delete(stack *s) {
    if (vide(*s)) {
        printf("Le stack est vide");
        return 0; 
    }
    int e ;
    e = s->content[s->top] ; 
    s->top -= 1 ;
    return e ;
}


void delete_top(stack *s) {
    if (vide(*s)) {
        printf("Le stack est vide"); 
    }
    s->top -= 1 ;
}

void printStack(stack s) {  
    while(!vide(s)){
        printf("%4d", delete(&s));
    }
}