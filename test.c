#include <stdio.h>
#include <stdlib.h>


char* Read_file(char chaine[]){
    FILE * fichier = NULL ; 
    int taillefichier ; //on veur trouver la taille pour pouvoir allouer la bonne taille 
    char * Tableauoctet ; 

    fichier = fopen(chaine , "rb"); 
    fseek(fichier , 0 , SEEK_END); //on met le pointeur à la fin du fichier pour trouver son emplacement et la taille de cet automate
    taillefichier = ftell(fichier); 

    rewind(fichier); //Je me replace au debut du fichier sinon je ne pourrai rien lire 


    Tableauoctet = malloc(taillefichier* sizeof(char)); // je prepare ma memoire pour recuperer les donnes de l automate
    
    fread(Tableauoctet, taillefichier, 1 , fichier); //J utilise fread pour recuperer les donnees sous la bonne forme et ainsi remplir Tableauoctet

    fclose(fichier);  // on referme le fichier 
    return Tableauoctet ; 
}

int main (int argc , char* argv[]) {
    char * Tableauoctet ; 
    Tableauoctet = Read_file(argv[1]) ; 

    int i ; 
    for(i=0 ; i<10000 ; i+=1){
      printf("%c",Tableauoctet[i]);
    } 
    printf("\n"); 


    return 0 ; 
}