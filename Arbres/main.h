#define MAX         30
#define MAX_RESUME  1000

/*
 * @brief   Declaration d'une structure pour le noeud d'un arbre binaire, contenant un film et ses informations     
 * @param   Champs : titre - tableau de caracteres contenant le titre du film
 *          annee_sortie - entier correspondant à l'annee de sortie du film
 *          realisateur - tableau de caracteres contenant le nom du realisateur
 *          resume - tableau de caracteres contenant un resume du film
 *          fils_gauche - pointeur vers un autre film, branche gauche
 *          fils_droit  - pointeur vers un autre film, branche droite
 */
struct Cinematheque_St{
    char titre [MAX] ;
    int annee_sortie ;
    char realisateur [MAX];
    char resume [MAX_RESUME] ;
    
    struct Cinematheque_St * fils_gauche ;
    struct Cinematheque_St * fils_droit  ;
};

/*
 * @brief   Renomme la structure Cinematheque_St en un pointeur Cinematheque
 */
typedef struct Cinematheque_St * Cinematheque;

/*
 * @brief   Cree une nouvelle cinematheque vide
 */
Cinematheque creer_cinematheque() ;

/*
 * @brief   Insere un film dans une cinemathque
 * @param   c - la cinematheque dans laquelle inserer un film
 *          t - le titre du film à inserer
 *          a - l'annee de sortie du film
 *          r1 - le realisateur du film
 *          r2 - le resume du film
 */
Cinematheque inserer  (Cinematheque c, char t [MAX], int a, char r1 [MAX], char r2 [MAX_RESUME]) ;

/*
 * @brief   Supprime un film de la cinematheque
 * @param   c - la cinematheque visee
 *          t - le titre du film a supprimer
 */
Cinematheque supprimer( Cinematheque c, char t [MAX]) ;

/*
 * @brief   Recherche un film dans une cinematheque selon un titre
 * @param   c - la cinematheque visee
 *          t - le titre du film recherche
 */
Cinematheque rechercher_film( Cinematheque c, char t [MAX]) ;

/*
 * @brief   Recherche des films dans une cinematheque selon un nom de realisateur
 * @param   c - la cinemathque visee
 * @param   r - le nom du realisateur recherche
 */
Cinematheque rechercher_film_par_realisateur( Cinematheque c, char r [MAX] ) ;

/*
 * @brief   Detruit une cinematheque existante
 * param    c - la cinematheque a detruire
 */
Cinematheque detruire_cinematheque( Cinematheque c) ;

int est_apres(char a [30], char b [30]) ;

void afficher_cinematheque (Cinematheque c) ;

int est_vide( Cinematheque c);
