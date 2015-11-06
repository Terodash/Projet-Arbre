//
//  B46 Projet.c
//  
//
//  Created by Guillaume Ricard on 04/11/2015.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main(){
    Cinematheque c1 = creer_cinematheque() ;
        
    c1 = inserer(c1, "a", 2001, "Tibo", "Un bon film") ;
    c1 = inserer(c1, "b", 2002, "Michel", "Un mauvais film") ;
    c1 = inserer(c1, "c", 2003, "Tibo", "Un moyen film") ;
    c1 = inserer(c1, "d", 2004, "Guillaume", "Un super film") ;
    c1 = inserer(c1, "e", 2005, "Guillaume", "Un film") ;
    
    afficher_cinematheque(c1) ;
    printf("\n");
    
    c1 = supprimer(c1, "a") ;
    afficher_cinematheque(c1) ;

    
    return 0;
}