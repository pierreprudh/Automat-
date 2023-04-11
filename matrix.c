#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

struct matrix {
    int size ; 
    int ** cells;
}; 

matrix  matrix_create ( int size ){
    matrix m ; 
    m.size = size; 
    m.cells = malloc( size * sizeof(int*));
    int i ; 
    for ( i=0 ; i < size ; i++ ) {
        m.cells[i] = malloc( size * sizeof(int * ));
    }
return m ; 
}



