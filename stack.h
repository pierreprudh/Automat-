
typedef struct stack stack;

/*
requires: 
assigns: s.stack , s.top
ensures: met e au dessus de la pile
*/
void push(stack *s , int e ) ;

/*
requires: une pile
assigns: rien
ensures: verifie que le stack est vide 
*/
int vide(stack s) ; 

/*
requires: 
assigns: s.stack , s.top
ensures: met e au dessus de la pile
*/
void push(stack *s , int e ) ;

/*
requires: 
assigns: s.top
ensures: renvoie sommet de la pile et le supprime
*/
int delete(stack *s) ; 

/*
requires: 
assigns: s.top
ensures: supprime sommet de la pile
*/
void delete_top(stack *s) ;

/*
requires: 
assigns :
ensures: affiche S
*/
void printStack(stack s) ;
