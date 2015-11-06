//
//  B46 Projet_Arbres_Fonctions.c
//  
//
//  Created by Guillaume Ricard on 04/11/2015.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int est_vide( Cinematheque c){
    if (c == NULL || strcmp(c->titre, "") == 0 ) return 1 ;
    else return 0 ;
}

int est_apres(char a[], char b[]){
    if (strcmp(a, b)<0){
        return 0;
    }
    if (strcmp(a, b)>0){
        return 1;
    }
    else return -1;
}

void afficher_film(Cinematheque c){
    printf("%s : par %s, sorti en %d. %s \n", c->titre, c->realisateur, c->annee_sortie, c->resume);
}

void afficher_cinematheque (Cinematheque c){
    if (c != NULL){
        afficher_film(c);
        afficher_cinematheque(c->fils_gauche);
        afficher_cinematheque(c->fils_droit);
    }
}

Cinematheque creer_cinematheque(){
    Cinematheque nouvelle_c ;
    /*
    nouvelle_c = (Cinematheque)malloc( sizeof( struct Cinematheque_St)) ;
    if (nouvelle_c == NULL) {
        fprintf( stderr, "Erreur: impossible d'allouer un nouveau noeud.\n" );
        exit( -1 );
    }
    strcpy (nouvelle_c->titre , "") ;
    strcpy (nouvelle_c->resume , "") ;
    strcpy (nouvelle_c->realisateur , "") ;
    nouvelle_c->fils_gauche = NULL ;
    nouvelle_c->fils_droit = NULL ;*/
    
    nouvelle_c = NULL ;
    
    return nouvelle_c ;
};

Cinematheque inserer (Cinematheque c, char t [], int a, char r1 [], char r2 []) {
    
    //si le noeuf est vide, on le créé
    if (c==NULL){
        c = (Cinematheque)malloc( sizeof( struct Cinematheque_St));
        if (c == NULL) {
            fprintf( stderr, "Erreur: impossible d'allouer un nouveau noeud.\n" );
            exit( -1 );
        }

        strcpy(c->titre, t) ;
        c->annee_sortie = a ;
        strcpy(c->realisateur, r1) ;
        strcpy(c->resume, r2) ;
        c->fils_gauche = NULL ;
        c->fils_droit  = NULL ;
    }
    /*
    //cas ou la cinematheque a deja ete declaree sans etre initialisee
    else if( !strcmp (c->titre , "")){
        strcpy(c->titre, t) ;
        c->annee_sortie = a ;
        strcpy(c->realisateur, r1) ;
        strcpy(c->resume, r2) ;
        c->fils_gauche = NULL ;
        c->fils_droit  = NULL ;
    }*/
    
    //si le titre du film est apres dans l'alphabet, il est place dans une branche a droite
    else if(est_apres(t, c->titre) == 1){
        c->fils_droit = inserer (c->fils_droit, t, a, r1, r2) ;
    }
    
    //si le titre du film est avant dans l'alphabet, il est place dans une branche a gauche
    else if (!est_apres(t, c->titre)){
        c->fils_gauche = inserer (c->fils_gauche, t, a, r1, r2) ;
    }

    return c ;
}

Cinematheque recherche_max_Arbre(Cinematheque c){
    if(c==NULL)                 return NULL   ;
    if(c->fils_droit==NULL)     return c;
    else return recherche_max_Arbre(c->fils_droit);
}

Cinematheque recherche_min_Arbre(Cinematheque c){
    if(c==NULL)                 return NULL   ;
    if(c->fils_gauche==NULL)    return c;
    else return recherche_min_Arbre(c->fils_gauche);
}

Cinematheque supprimer( Cinematheque c, char t []) {
    Cinematheque tmp;
    if(c != NULL)
    {
        if (strcmp(t,c->titre)<0)
        {
            c->fils_gauche=supprimer(c->fils_gauche,t);
        }
        else if(strcmp(t,c->titre)>0)
        {
            c->fils_droit=supprimer(c->fils_droit,t);
        }
        else if(c->fils_gauche && c->fils_droit)
        {
            if (recherche_max_Arbre(c->fils_gauche) != NULL)
            {
                strcpy(c->titre,recherche_max_Arbre(c->fils_gauche)->titre);
                strcpy(c->realisateur,recherche_max_Arbre(c->fils_gauche)->realisateur);
                strcpy(c->titre,recherche_max_Arbre(c->fils_gauche)->titre);
                c->annee_sortie = recherche_max_Arbre(c->fils_gauche)->annee_sortie ;
                
                c->fils_gauche = supprimer(c->fils_gauche,recherche_max_Arbre(c->fils_gauche)->titre);
            }
            else
            {
                strcpy(c->titre,recherche_min_Arbre(c->fils_droit)->titre);
                strcpy(c->realisateur,recherche_min_Arbre(c->fils_droit)->realisateur);
                strcpy(c->titre,recherche_min_Arbre(c->fils_droit)->titre);
                c->annee_sortie = recherche_min_Arbre(c->fils_droit)->annee_sortie ;
                
                c->fils_droit = supprimer(c->fils_droit,recherche_min_Arbre(c->fils_droit)->titre);
            }
        }
        else
        {
            tmp = c;
            if(c->fils_gauche==NULL)  c=c->fils_droit;
            else if(c->fils_droit==NULL)   c=c->fils_gauche;
            free(tmp);
        }
    }
    return c;

}

Cinematheque rechercher_film( Cinematheque c, char t []){
    if (c != NULL){
        if (strcmp (t, c->titre) == 0){
                return c ;
        }
        else{
            rechercher_film(c->fils_gauche, t) ;
            rechercher_film(c->fils_droit, t) ;
        }
    }
    
    return NULL ;
}

Cinematheque rechercher_film_par_realisateur_mere(Cinematheque c, char r [], Cinematheque resultat){
    if (c != NULL){
        if (strcmp (r, c->realisateur) == 0){
            resultat = inserer(resultat, c->titre, c->annee_sortie, c->realisateur, c->resume);
        }

        rechercher_film_par_realisateur_mere(c->fils_gauche, r, resultat) ;
        rechercher_film_par_realisateur_mere(c->fils_droit, r, resultat) ;
    }
    return resultat ;
}

Cinematheque rechercher_film_par_realisateur( Cinematheque c, char r []){
    Cinematheque c_realisateur ;
    c_realisateur = rechercher_film_par_realisateur_mere(c, r, creer_cinematheque()) ;
    
    if (est_vide(c_realisateur)) return NULL ;
    else return c_realisateur ;
}

Cinematheque detruire_cinematheque( Cinematheque c){
    if (c != NULL){
        
        c->fils_gauche = detruire_cinematheque(c->fils_gauche);
        c->fils_droit = detruire_cinematheque(c->fils_droit) ;
    
        free (c) ;
    }
    return NULL ;
}