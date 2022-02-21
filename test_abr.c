//a executer avec les arguments " arbre1 arbre2 arbre3 arbre4"

#include <stdio.h>
#include <stdlib.h>

#include "abr.h"

int main (int argc, char**argv)
{
  Arbre_t a, b, c, d;

  if (argc < 2)
    {
      fprintf (stderr, "il manque le parametre nom de fichier\n") ;
      exit (-1) ;
    }

  a = lire_arbre (argv[1]) ;
  b = lire_arbre (argv[2]) ;
  c = lire_arbre (argv[3]) ;
  d = lire_arbre (argv[4]) ;
  
/*  printf("arbre 1 : \n");
  afficher_arbre (a,0) ;
  printf("arbre 2 : \n");
  afficher_arbre (b,0) ;
  printf("arbre 3 : \n");
  afficher_arbre (c,0) ;
  printf("arbre 4 : \n");
  afficher_arbre (d,0) ;*/

  /*tests fonctions hauteur 
      résultats attendus :
      -arbre 1 : 4
      -arbre 2 : 4
      -arbre 3 : 2
      -arbre 4 : 8
  */

  /*
  for (int i = 1; i<argc; i++ ){
    a = lire_arbre (argv[i]) ;
    printf ("Hauteur arbre %i (fonction recursive) : %i \n", i, hauteur_arbre_r(a));
    printf ("Hauteur arbre %i (fonction non recursive) : %i \n", i, hauteur_arbre_nr(a));
  }
  */

     /*tests fonction parcourir arbre largeur
      résultats attendus :
      -arbre 1 : 4,2,6,1,3,5,8,10,9,15
      -arbre 2 : 12,3,14,2,5,15,23,28
      -arbre 3 : 14,5,18,2,9,15,19
      -arbre 4 : 1,12,3,4,5,6,7,8,9
  */ 

 /*   for (int i = 1; i<argc; i++ ){
      a = lire_arbre (argv[i]) ;
      printf("Arbre %i :\n", i);
      parcourir_arbre_largeur (a) ;
      printf("\n");
  }*/
  //resultat correct mais segmentation fault à la fin de l'execution

  /*tests fonction noeuds par niveau 
      résultats attendus :
      -arbre 1 : 1,2,4,1,2
      -arbre 2 : 1,2,3,1,1
      -arbre 3 : 1,2,4
      -arbre 4 : 1,1,1,1,1,1,1,1,1
  */

/*   for (int i = 1; i<argc; i++ ){
    a = lire_arbre (argv[i]) ;
    printf("Arbre %i :\n", i);
    afficher_nombre_noeuds_par_niveau (a) ;
    printf("\n");
  }*/
  
  /*tests fonctions nombre clefs 
      résultats attendus :
      -arbre 1 : 10 
      -arbre 2 : 8 
      -arbre 3 : 7
      -arbre 4 : 9 
  */  

  /*  for (int i = 1; i<argc; i++ ){
    a = lire_arbre (argv[i]) ;
    printf ("Nombre de clefs arbre %i (fonction recursive) : %i \n", i, nombre_cles_arbre_r(a));
    //printf ("Nombre de clefs arbre %i (fonction non recursive) : %i \n", i, nombre_cles_arbre_nr(a));
  }
  //printf ("Nombre de clefs arbre 1 %i \n", nombre_cles_arbre_nr(a));
  // pb nombre_cles_arbre_nr
*/

  /*tests fonction clef min 
      résultats attendus :
      -arbre 1 : 1 
      -arbre 2 : 2 
      -arbre 3 : 2
      -arbre 4 : 1 
  */  

/*  for (int i = 1; i<argc; i++ ){
    a = lire_arbre (argv[i]) ;
    printf ("Clef minimum arbre %i : %i \n", i, trouver_cle_min(a));
  }*/

    /*tests fonctions liste clef triée 
      résultats attendus :
      -arbre 1 : 1,2,3,4,5,6,8,9,10,15
      -arbre 2 : 2,3,5,12,14,15,23,28
      -arbre 3 : 2,5,9,14,15,18,19
      -arbre 4 : 1,3,4,5,6,7,8,9,12
  */

/*     for (int i = 1; i<argc; i++ ){
    a = lire_arbre (argv[i]) ;
    printf("Arbre %i (version recursive) :\n", i);
    imprimer_liste_cle_triee_r (a) ;
    printf("Arbre %i (version non recursive) :\n", i);
    imprimer_liste_cle_triee_nr (a) ;
    printf("\n");
  }*/
  //pb

     /*tests fonctions arbre plein et arbre parfait
      résultats attendus :
      -arbre 1 : oui, non
      -arbre 2 : non, non
      -arbre 3 : oui, oui
      -arbre 4 : non, non
  */

  // A FINIR ---------------------------------------
/*     for (int i = 1; i<argc; i++ ){
    a = lire_arbre (argv[i]) ;
    
    arbre_parfait (a);
    printf("Arbre %i plein : %i \n", i, arbre_plein (a));
    }
/*
    printf("Arbre %i parfait   :\n", i, arbre_parfait (a));
    printf("\n");
  }*/

      /*      A REFAIRE :(
      tests fonctions rechercher clef sup et inf arbre
      résultats attendus :
      INF
      -arbre 1 : 1->2, 4->5
      -arbre 2 : 2->3, 12->14
      -arbre 3 : 2->5, 14->15
      -arbre 4 : 1->3, 3->4, 9->12
      SUP
      -arbre 1 : 2->1, 6->4
      -arbre 2 : 3->2, 14->12
      -arbre 3 : 5->2, 15->14
      -arbre 4 : 3->1, 4->3, 12->9

  */

  printf (" sup de a pour %d: %d \n", 1,rechercher_cle_sup_arbre (a, 1)->cle );
  printf (" sup de a pour %d: %d \n", 4,rechercher_cle_sup_arbre (a, 4)->cle );
  printf("\n");
  printf (" sup de b pour %d: %d \n", 2,rechercher_cle_sup_arbre (b, 2)->cle );
  printf (" sup de b pour %d: %d \n", 12,rechercher_cle_sup_arbre (b, 12)->cle );
  printf("\n");
  printf (" sup de c pour %d: %d \n", 2,rechercher_cle_sup_arbre (c, 2)->cle );
  printf (" sup de c pour %d: %d \n", 14,rechercher_cle_sup_arbre (c, 14)->cle );
  printf("\n");
  printf (" sup de d pour %d: %d \n", 1,rechercher_cle_sup_arbre (d, 1)->cle );
  printf (" sup de d pour %d: %d \n", 3,rechercher_cle_sup_arbre (d, 3)->cle );
  printf (" sup de d pour %d: %d \n", 9,rechercher_cle_sup_arbre (d, 9)->cle );
  printf("\n");

  printf (" inf de a pour %d: %d \n", 2,rechercher_cle_inf_arbre (a, 2)->cle );
  printf (" inf de a pour %d: %d \n", 6,rechercher_cle_inf_arbre (a, 6)->cle );
  printf("\n");
  printf (" inf de b pour %d: %d \n", 3,rechercher_cle_inf_arbre (b, 3)->cle );
  printf (" inf de b pour %d: %d \n", 14,rechercher_cle_inf_arbre (b, 14)->cle );
  printf("\n");
  printf (" inf de c pour %d: %d \n", 5,rechercher_cle_inf_arbre (c, 5)->cle );
  printf (" inf de c pour %d: %d \n", 15,rechercher_cle_inf_arbre (c, 15)->cle );
  printf("\n");
  printf (" inf de d pour %d: %d \n", 3,rechercher_cle_inf_arbre (d, 3)->cle );
  printf (" inf de d pour %d: %d \n", 4,rechercher_cle_inf_arbre (d, 4)->cle );
  printf (" inf de d pour %d: %d \n", 12,rechercher_cle_inf_arbre (d, 12)->cle);
  printf("\n");

}


 /*



Arbre_t detruire_cle_arbre (Arbre_t a, int cle) ;

Arbre_t intersection_deux_arbres (Arbre_t a1, Arbre_t a2) ;

Arbre_t union_deux_arbres (Arbre_t a1, Arbre_t a2) ;
*/