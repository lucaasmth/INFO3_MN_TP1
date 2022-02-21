#include <stdio.h>
#include <stdlib.h>

#include "abr.h"

int main (int argc, char**argv)
{
  Arbre_t a ;

  if (argc != 2)
    {
      fprintf (stderr, "il manque le parametre nom de fichier\n") ;
      exit (-1) ;
    }

  a = lire_arbre (argv[1]) ;
  
  afficher_arbre (a,0) ;

  
  printf("trouver_cle_min: %d\n", trouver_cle_min(a));
  printf("nombre_cles_arbre_r: %d\n", nombre_cles_arbre_r(a));
  printf("rechercher_cle_sup_arbre(7): %d\n", rechercher_cle_sup_arbre(a, 7)->cle);
  printf("rechercher_cle_inf_arbre(7): %d\n", rechercher_cle_inf_arbre(a, 7)->cle);
}
