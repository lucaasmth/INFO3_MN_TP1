
/* structure noeud presentee en cours */

typedef struct n {
  int cle;
  int balance; //balance = 0 ou 1
  struct n *fgauche, *fdroite;
} noeud_t, *pnoeud_t ;

/* type Arbre_AVL, pointeur vers un noeud */

typedef pnoeud_t Arbre_AVL_t;

Arbre_AVL_t lire_arbre (char *nom_fichier) ;

void afficher_arbre (Arbre_AVL_t a, int niveau) ;

int hauteur_arbre_r (Arbre_AVL_t a) ;

int hauteur_arbre_nr (Arbre_AVL_t a) ;

void parcourir_arbre_largeur (Arbre_AVL_t a) ;

void afficher_nombre_noeuds_par_niveau (Arbre_AVL_t a) ;

int nombre_cles_arbre_r (Arbre_AVL_t a) ;

int nombre_cles_arbre_nr (Arbre_AVL_t a) ;

int trouver_cle_min (Arbre_AVL_t a) ;

void imprimer_liste_cle_triee_r (Arbre_AVL_t a) ;

void imprimer_liste_cle_triee_nr (Arbre_AVL_t a) ;

int arbre_plein (Arbre_AVL_t a) ;

int arbre_parfait (Arbre_AVL_t a) ;

Arbre_AVL_t rechercher_cle_sup_arbre (Arbre_AVL_t a, int valeur) ;

Arbre_AVL_t rechercher_cle_inf_arbre (Arbre_AVL_t a, int valeur) ;

Arbre_AVL_t detruire_cle_arbre (Arbre_AVL_t a, int cle) ;

Arbre_AVL_t intersection_deux_arbres (Arbre_AVL_t a1, Arbre_AVL_t a2) ;

Arbre_AVL_t union_deux_arbres (Arbre_AVL_t a1, Arbre_AVL_t a2) ;

Arbre_AVL_t rotation_gauche (Arbre_AVL_t a);

Arbre_AVL_t rotation_droite (Arbre_AVL_t a);

