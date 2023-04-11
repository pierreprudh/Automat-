#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define TAILLE_MAX 255 //afin de pouvoir rapidement modifier la valeur en cas de probleme
#define SIZE 100

/*
requires: un fichier 
assigns : fichier
ensures : lis le fichier et renvoie 1 en cas de probleme 0 si tout s est bien passe
*/
int Read_file_test(char  chaine[]) {
    FILE* fichier = NULL ; 
    char caracActuel ;              //je cherche juste a parcourir le fichier rapidement pour tester l'automate
    fichier = fopen(chaine, "rb");
    if ( fichier != NULL ){
        do 
        {
            caracActuel = fgetc(fichier) ;    // on lit tout le fichier on s arrete a la fin de ce dernier 
        } while (caracActuel != EOF); 
        fclose(fichier); 
        return 1 ; 
    }
    else {
        fclose(fichier); 
        return 0 ; 
    }
}

/*
requires: un fichier 
assigns : Tableauoctet
ensures : lis le fichier et le stocke dans un tableau
*/
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

/*
requires: l'automate
assigns : ComptEtat
ensures : renvoie le nombre d'etat de cet automate soit le 3eme octet
*/
int nb_etat(char chaine[]){
    int ComptEtat ; 
    int ComptEtat2 ; 
    int ComptEtat3 ; 
    int nbrtotaletat ; 

    if(chaine[3]==10){ //je regarde si on a un retour a la ligne a la 4eme place dans ce cas la on a un seul chiffre compris entre 1-9 a la 3eme place en oubliant de compter la 0eme place
        switch(chaine[2]){   
        case 48:           //je test une valeur par une afin de la convertir apres 
            ComptEtat=0;
            break;
        case 49:
            ComptEtat=1;
            break;
        case 50:
            ComptEtat=2;
            break;
        case 51:
            ComptEtat=3;
            break;
        case 52:
            ComptEtat=4;
            break;
        case 53:
            ComptEtat=5;
            break;
        case 54:
            ComptEtat=6;
            break;
        case 55:
            ComptEtat=7;
            break; 
        case 56:
            ComptEtat=8;
            break;
        case 57:
            ComptEtat=9;
            break;
        }
        return ComptEtat ; 
    }

    if (chaine[4]==10 ){ // je regarde cette fois a 5eme place dans ce cas la on aurait un nombre entre 1 et 99 etats
        switch(chaine[2]){   
        case 48:          
            ComptEtat2=0;
            break;
        case 49:
            ComptEtat2=10;
            break;
        case 50:
            ComptEtat2=20;
            break;
        case 51:
            ComptEtat2=30;
            break;
        case 52:
            ComptEtat2=40;
            break;
        case 53:
            ComptEtat2=50;
            break;
        case 54:
            ComptEtat2=60;
            break;
        case 55:
            ComptEtat2=70;
            break; 
        case 56:
            ComptEtat2=80;
            break;
        case 57:
            ComptEtat2=90;
            break;
        }
        switch(chaine[3]){    // le bloc des unités 
        case 48:          
            ComptEtat=0;
            break;
        case 49:
            ComptEtat=1;
            break;
        case 50:
            ComptEtat=2;
            break;
        case 51:
            ComptEtat=3;
            break;
        case 52:
            ComptEtat=4;
            break;
        case 53:
            ComptEtat=5;
            break;
        case 54:
            ComptEtat=6;
            break;
        case 55:
            ComptEtat=7;
            break; 
        case 56:
            ComptEtat=8;
            break;
        case 57:
            ComptEtat=9;
            break;
        }
        nbrtotaletat = ComptEtat + ComptEtat2 ; // j'additionne le resultat pour pouvoir recuperer le nombre d'etats
        return nbrtotaletat ;
    }

    if (chaine[5]==10 ){ // je regarde cette fois a 5eme place dans ce cas la on aurait un nombre entre 1 et 99 etats
        switch(chaine[2]){   //les centaines
        case 48:          
            ComptEtat3=0;
            break;
        case 49:
            ComptEtat3=100;
            break;
        case 50:
            ComptEtat3=200; //on a un maximum de 255 etats 
            break;
        }

        switch(chaine[3]){    // le bloc des dizaines
        case 48:          
            ComptEtat2=0;
            break;
        case 49:
            ComptEtat2=10;
            break;
        case 50:
            ComptEtat2=20;
            break;
        case 51:
            ComptEtat2=30;
            break;
        case 52:
            ComptEtat2=40;
            break;
        case 53:
            ComptEtat2=50;
            break;
        case 54:
            ComptEtat2=60;
            break;
        case 55:
            ComptEtat2=70;
            break; 
        case 56:
            ComptEtat2=80;
            break;
        case 57:
            ComptEtat2=90;
            break;
        }

        switch(chaine[4]){    // le bloc des unités 
        case 48:          
            ComptEtat=0;
            break;
        case 49:
            ComptEtat=1;
            break;
        case 50:
            ComptEtat=2;
            break;
        case 51:
            ComptEtat=3;
            break;
        case 52:
            ComptEtat=4;
            break;
        case 53:
            ComptEtat=5;
            break;
        case 54:
            ComptEtat=6;
            break;
        case 55:
            ComptEtat=7;
            break; 
        case 56:
            ComptEtat=8;
            break;
        case 57:
            ComptEtat=9;
            break;
        }
        nbrtotaletat = ComptEtat + ComptEtat2 + ComptEtat3; // j'additionne le resultat pour pouvoir recuperer le nombre d'etats
        return nbrtotaletat ;
    }
    else {return 0 ;} //dans le cas d'un eventuel probleme
}

/*
requires: Les donnees de l automate
assigns : DonneeDecale
ensures : on renvoie un pointeur vers un tableau remplis des donnees de decale dans dans un tableau 
*/
int* Obtain_decale(char chaine[] ){
    int i= 0 ; 
    int k = 0 ;  
    int ComptDecale=0 ; 
    while(chaine[i]!=EOF){
        if(chaine[i]== 10){  //je compte les retours a la ligne
            k+=1; 
        }
        if(k == 4 ){ //je m'arrete au 4eme 
            break ; 
        }
        i+=1 ;
    }
    i= i+1 ; //Je me decale d un cran car j'etais sur le retour a la ligne 

    int marqueur ; // on doit retenir le debut de la ligne 
    marqueur= i ; 

    while(chaine[i]!= -83){ //173 correspond à AD en hexadecimal correspondant a la fin des donnes de decale
        ComptDecale+=1; //Je compte la taille de decale afin d allouer la bonne taille a la memoire
        i+=1 ; 
    }
    ComptDecale +=1; // Je me decale car j etais toujours sur le dernier octet
    int * DonneeDecale = malloc(ComptDecale * sizeof(int)); 
    
    ComptDecale = 0 ;
    while(chaine[marqueur]!= -83){
        DonneeDecale[ComptDecale] = chaine[marqueur]; 
        ComptDecale=+1 ; 
        marqueur+=1 ; 
    }
    return DonneeDecale ; 
}

/*
requires:les donnees de l automate et le nombre d etat de l automate obtenu 
assigns :  partie1reduit
ensures : renvoie un pointeur vers les donnes de la premiere partie de reduit  dans un tableau 
*/
int* Obtain_reduit_part1(int Etats , char chaine[]) {
    int i, j , k ; 
    int * partie1reduit = malloc( Etats* sizeof(int) ) ; //on alloue la memoire de la taille du nombre d etats recuperes
    i=0 ; 
    k= 0 ; 

    while(chaine[i] !=10){
        i+=1 ; 
    }   
    i+=1 ; 
    while(chaine[i] !=10){
        i+=1 ; 
    }   
    i+=1 ; 
    while(chaine[i]!=EOF){
        if(chaine[i]== 10){  //je compte les retours a la ligne
            k+=1; 
        }
        if(k == 2 ){ //je m'arrete au 2eme retour a la ligne pour obtenir la premiere partie des composantes de reduit
            break ; 
        }
        i+=1 ;
    } 

    i= i+1 ;
    j=0 ; 
    do {
        partie1reduit[j] = chaine[i]; 
        i+= 1 ; 
        j+= 1 ; 
    }while(chaine[i]!= 10) ;  //on s arrete au prochain retour a la ligne 
    return partie1reduit ;
}

/*
requires:les donnees de l automate et le nombre d etat de l automate obtenu 
assigns :  partie1reduit
ensures : renvoie un pointeur vers les donnes de la premiere partie de reduit  dans un tableau
*/
int* Obtain_reduit_part2(int Etats , char chaine[]) {
    int i, j , k ; 
    int * partie2reduit = malloc( Etats* sizeof(int) ) ; //on alloue la memoire de la taille du nombre d etats recuperes
    i=0 ; 
    k= 0 ; 

    while(chaine[i]!=EOF){
        if(chaine[i]== 10){  //je compte les retours a la ligne
            k+=1; 
        }
        if(k == 3 ){ //je m'arrete au 3eme retour a la ligne pour obtenir la deuxieme partie des composantes de reduit
            break ; 
        }
        i+=1 ;
    }

    i= i+1 ; // On se remet a la bonne place 
    j=0 ; 
    while(chaine[i] != 10 ){         // on remplir jusqu au prochain retour a la ligne
        partie2reduit[j] = chaine[i]; 
        i+=1 ; 
        j+=1 ; 
    }
    return partie2reduit ;
}

/*
requires: les donnees de l automate 
assigns : DonneesBranchement
ensures : renvoie un pointeur vers les donnees de Branchement dans un tableau 
*/
int * Obtain_Branchement(char chaine[]){
    int i ,j , k ; 
    i = 0 ; 
    k= 0 ; 
    
    while(chaine[i]!=EOF){
        if(chaine[i]== 10){  //je compte les retours a la ligne
            k+=1; 
        }
        if(k == 4 ){ //je m'arrete au 4eme retour a la ligne 
            break ; 
        }
        i+=1 ; 
    }
    
    int ComptBranchement= 0;
    while (chaine[i]!= -83){ //on regarde la premiere fois qu on vas atteindre le \255 soit AD en hexadecimal 
        i+=1 ; 
        ComptBranchement +=1 ;  //on retient aussi le nombre d octets
    }
    i= i+ 3 ; // on doit passer les 3 octets occupés par les \255

    int marqueur ;  // on doit retenir le debut de la ligne pour allouer la bonne taille d espace memoire
    marqueur = i ; 

    int * DonneesBranchement = malloc(ComptBranchement * sizeof(int)) ;

    j = 0 ; 
    while(chaine[marqueur]!=-83){ 
        DonneesBranchement[j] = chaine[marqueur] ; 
        j+=1 ; 
        marqueur+= 1 ; 
    }
    return DonneesBranchement ; 
}


/*
requires: le nombre d etats et les donnees de l automate
assigns :  DonneesAction
ensures :  renvoie un pointeur vers les donnees de action dans un tableau 
*/
int* Obtain_Action(int Etats , char chaine[]) {
    int i, j ; 
    i=0 ; 
    while (chaine[i] != 10 ){ //je m arrete au premier retour de ligne
       i+=1 ; 
    }
    i+=1 ; //je me decale pour etre a la bonne place 

    int * DonneesAction = malloc(Etats * 128* sizeof(int )); // le 128 est le nombre demande dans le sujet 

    j= 0 ; 
    while(chaine[i]!= 10){ //jusqu au prochain retour a la ligne 
        DonneesAction[j] = chaine[i]; 
        i+=1 ; 
        j+=1 ; 
    }
    return DonneesAction ; 
}
/* 
requires : 
assigns : 
ensures : 

int length( char * s[]){
    int i = 0 ; 
    while (s[i] != '\0'){
        i+=1; 
    }
    return i ; 
} */

/* 
ensures : 
assigns : 
ensures : 

int * Branchement(int s , char A){    printf("TOUT VAS BIEN");
    int i ,newS ; 




}
 */

/* 
assigns : 
assigns : 
ensures : 

int  Decale(int s , char c , int pile[]){
    int i , newS ; 




} */




int main (int argc , char* argv[]) {

    char * Tableauoctet ; 
    Tableauoctet = Read_file(argv[1]); 

    //int i ; 
    //for(i=0 ; i<10000 ; i+=1){
    //  printf("%c",Tableauoctet[i]);
    //} 

    int nb_etat1 = nb_etat(Tableauoctet); 
    printf("Il y a %i etat\n", nb_etat1 ); 

    int * actions = Obtain_Action(nb_etat1, Tableauoctet);
    printf("COUCOU c bn action\n");

    int i =0 ; 
    for (i=0 ; i<100 ; i+=1){
        printf("%c", actions[i]); 
        i+=1 ; 
    }
    printf("\n"); 

    int * reduit1 = Obtain_reduit_part1(nb_etat1 , Tableauoctet);
    printf("COUCOU c bon reduit1\n");

    i =0 ; 
    for (i=0 ; i<10 ; i+=1){
        printf("%c", reduit1[i]); 
        i+=1 ; 
    }
    printf("\n"); 


    int * reduit2 = Obtain_reduit_part2(nb_etat1 , Tableauoctet);
    printf("COUCOU c bon reduit2\n");
    i =0 ; 
    for (i=0 ; i<10 ; i+=1){
        printf("%c", reduit2[i]); 
        i+=1 ; 
    }
    printf("\n"); 

    int * decale = Obtain_decale(Tableauoctet);
    printf("COUCOU c bon decale\n");

    i =0 ; 
    for (i=0 ; i<10 ; i+=1){
        printf("%c", decale[i]); 
        i+=1 ; 
    }
    printf("\n"); 

    int * branchement = Obtain_Branchement(Tableauoctet);
    printf("COUCOU c bon branchements\n"); 

    i =0 ; 
    for (i=0 ; i<10 ; i+=1){
        printf("%c", branchement[i]); 
        i+=1 ; 
    }
    printf("\n"); 

    printf("Tout les fichiers ont ete lus !\n");

    
    



    if (Read_file_test(argv[1]) == 0){
        printf("Le fichier a ete mal lu !"); 
        return 0 ; 
    } 

    printf("file %s correctly read. Please enter your inputs. \n", argv[1]); 

    
    return 0 ; 
}