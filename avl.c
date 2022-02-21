#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "avl.h"
#include "pile.h"
#include "file.h"


#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))


int feuille (Arbre_AVL_t a)
{
  if (a == NULL)
    return 0 ;
  else
    {
      if ((a->fgauche == NULL) && (a->fdroite == NULL))
	return 1 ;
      else
	return 0 ;
    }
}

Arbre_AVL_t ajouter_noeud (Arbre_AVL_t a, Arbre_AVL_t n)
{
  /* ajouter le noeud n dans l'arbre a */
  
  if (a == NULL)
    return n ;
  else if (n->cle < a->cle)
	a->fgauche = ajouter_noeud (a->fgauche, n) ;
  else
	a->fdroite = ajouter_noeud (a->fdroite, n) ;
  return a ;
  
}  

Arbre_AVL_t rechercher_cle_arbre (Arbre_AVL_t a, int valeur)
{
  if (a == NULL)
    return NULL ;
  else
    {
      if (a->cle == valeur)
	return a ;
      else
	{
	  if (a->cle < valeur)
	    return rechercher_cle_arbre (a->fdroite, valeur) ;
	  else
	    return rechercher_cle_arbre (a->fgauche, valeur) ;
	}
    }
}

Arbre_AVL_t ajouter_cle (Arbre_AVL_t a, int cle)
{
  Arbre_AVL_t n ;
  Arbre_AVL_t ptrouve ;
  
  /* 
     ajout de la clé. Creation du noeud n qu'on insere 
    dans l'arbre a
  */

  ptrouve = rechercher_cle_arbre (a, cle) ;

  if (ptrouve == NULL)
    {
      n = (Arbre_AVL_t) malloc (sizeof(noeud_t)) ;
      n->cle = cle;
      n->fgauche = NULL ;
      n->fdroite = NULL ;

      a = ajouter_noeud (a, n) ;
      return a ;
    }
  else
    return a ;
}


Arbre_AVL_t lire_arbre (char *nom_fichier)
{
  FILE *f ;
  int cle;
  Arbre_AVL_t a = NULL;
  
  f = fopen (nom_fichier, "r") ;

  while (fscanf (f, "%d", &cle) != EOF)
    {
      a = ajouter_cle (a, cle) ;
    }
    
  fclose (f) ;

  return a ;
}

void afficher_arbre (Arbre_AVL_t a, int niveau)
{
  /*
    affichage de l'arbre a
    on l'affiche en le penchant sur sa gauche
    la partie droite (haute) se retrouve en l'air
  */
  
  int i ;
  
  if (a != NULL)
      {
	afficher_arbre (a->fdroite,niveau+1) ;
	
	for (i = 0; i < niveau; i++)
	  printf ("\t") ;
	printf (" %d (%d)\n\n", a->cle, niveau) ;

	afficher_arbre (a->fgauche, niveau+1) ;
      }
  return ;
}


int hauteur_arbre_r (Arbre_AVL_t a)
{
 if (a == NULL){    //si a est l'arbre vide sa hauteur vaut -1
  return -1 ;
 }
 
 if (feuille(a->fdroite) && feuille(a->fdroite)){ //si a est une feuille on ajoute 1 à sa hauteur
  return 1;
 }
  
  else {    // sinon on incrémente la hauteur de 1 et on calcule le max de la hauteur des sous arbres
    return (1 + max(hauteur_arbre_r(a->fgauche), hauteur_arbre_r(a->fdroite)));
  }  

}

int hauteur_arbre_nr (Arbre_AVL_t a)
{
  pfile_t file = creer_file();
  pfile_t temp = creer_file();
  enfiler(file, a);
  int niveau = -1;
  while (!file_vide(file))
  {
    int count = 0;
    while (!file_vide(file))
    {
      Arbre_AVL_t fd, fg;
      Arbre_AVL_t noeud = defiler(file);
      fg = noeud->fgauche;
      fd = noeud->fdroite;
      if (fg != NULL)
        enfiler(temp, fg);
      if (fd != NULL)
        enfiler(temp, fd);
      count++;
    }
    while (!file_vide(temp))
      enfiler(file, defiler(temp));
    niveau++;
  }
  return niveau;
}


void parcourir_arbre_largeur (Arbre_AVL_t a)
{
  pfile_t f = creer_file();
  enfiler(f, a);
  while(f != NULL)
  {
    Arbre_AVL_t a = defiler(f);
    printf("%i \n", a->cle);

    if (a->fgauche != NULL)
    {
      enfiler(f, a->fgauche);
    }
    if (a->fdroite != NULL)
    {
      enfiler(f, a->fdroite);
    }
  }
  return ;
}

void afficher_nombre_noeuds_par_niveau (Arbre_AVL_t a)
{
  pfile_t file = creer_file();
  pfile_t temp = creer_file();
  enfiler(file, a);
  int niveau = 0;
  while (!file_vide(file))
  {
    int count = 0;
    while (!file_vide(file))
    {
      Arbre_AVL_t fd, fg;
      Arbre_AVL_t noeud = defiler(file);
      fg = noeud->fgauche;
      fd = noeud->fdroite;
      if (fg != NULL)
        enfiler(temp, fg);
      if (fd != NULL)
        enfiler(temp, fd);
      count++;
    }
    while (!file_vide(temp))
      enfiler(file, defiler(temp));

    printf("Niveau %i > %i noeuds\n", niveau, count);
    niveau++;
  }
  return ;
}


int nombre_cles_arbre_r (Arbre_AVL_t a)
{
  int out = 1;
  if(a->fgauche != NULL) {
    out += nombre_cles_arbre_r(a->fgauche);
  }
  if(a->fdroite != NULL) {
    out += nombre_cles_arbre_r(a->fdroite);
  }
  return out; 
}

int nombre_cles_arbre_nr (Arbre_AVL_t a)
{
  int count = 0;
  pfile_t f = creer_file();
  enfiler(f, a);
  while(f != NULL)
  {
    Arbre_AVL_t a = defiler(f);
    count++;

    if (file_vide(f))
    {
      enfiler(f, a->fgauche);
    }
    if (file_vide(f))
    {
      enfiler(f, a->fdroite);
    }
  }
  return count;
}

int trouver_cle_min (Arbre_AVL_t a)
{
  int out = a->cle;
  if(a->fgauche != NULL) {
    out = min(out, trouver_cle_min(a->fgauche));
  }
  if(a->fdroite != NULL) {
    out = min(out, trouver_cle_min(a->fdroite));
  }
  return out; 
}

 
//Fonction auxiliaire pour la fonction "imprimer_liste_cle_triee_r"
void AuxCleTriees(Arbre_AVL_t a, int cle)
{
  printf("> %i ", cle);

  Arbre_AVL_t nouvelleCle = rechercher_cle_sup_arbre(a, cle);
  if (nouvelleCle == NULL)
  {
    printf("\n\n");
    return;
  }
  AuxCleTriees(a, nouvelleCle->cle);
}
void imprimer_liste_cle_triee_r (Arbre_AVL_t a)
{
  int cleMin = trouver_cle_min(a);
  AuxCleTriees(a, cleMin);  
  return ;
}

void imprimer_liste_cle_triee_nr (Arbre_AVL_t a)
{
  int cle = trouver_cle_min(a);
  Arbre_AVL_t NouvelleCle;
  while (1)
  {
    printf("> %i ", cle);
    NouvelleCle = rechercher_cle_sup_arbre(a, cle);
    if (NouvelleCle == NULL)
      break;
    cle = NouvelleCle->cle;
  }
  printf("\n\n");
  return ;
}

//Un arbre binaire est plein si chaque nœud a 0 ou 2 enfants.

int arbre_plein (Arbre_AVL_t a)
{
  if (feuille(a)) 
    return 1;

  if (a->fdroite != NULL){
    if (a->fgauche == NULL){
      return 0;
    }
    if (!arbre_plein(a->fdroite))
      return 0;
  }

  if (a->fgauche != NULL){
    if (a->fdroite == NULL){
      return 0;
    }
    if (!arbre_plein(a->fgauche))
      return 0;
  }
  return 1;
} 
  

/*
Un arbre binaire parfait est un arbre binaire strict dans lequel toutes les feuilles (nœuds n'ayant aucun fils) 
sont à la même distance de la racine (c'est-à-dire à la même profondeur). Il s'agit d'un arbre dont tous les 
niveaux sont remplis : où tous les noeuds internes ont deux fils et où tous les noeuds externes ont la même hauteur.
*/

int arbre_parfait (Arbre_AVL_t a)
{
  if (!arbre_plein(a))
    return 0;
  int h = hauteur_arbre_r(a);

//---------------------------------
  pfile_t file = creer_file();
  pfile_t temp = creer_file();
  enfiler(file, a);
  int niveau = 0;
  int nbfeuille;
  while (!file_vide(file))
  {
    int count = 0;
    while (!file_vide(file))
    {
      Arbre_AVL_t fd, fg;
      Arbre_AVL_t noeud = defiler(file);
      fg = noeud->fgauche;
      fd = noeud->fdroite;
      if (fg != NULL)
        enfiler(temp, fg);
      if (fd != NULL)
        enfiler(temp, fd);
      count++;
    }
    while (!file_vide(temp))
      enfiler(file, defiler(temp));
     if (niveau == h){
      nbfeuille = count;
      }
    //printf("Niveau %i > %i noeuds\n", niveau, count);
    niveau++;
  }
//----------------------------------- 
  int nbFeuille = (int) pow (2,h);
  printf ("attendue %i \n", nbFeuille);
  printf ("resultat %i \n", nbfeuille);
  if (nbfeuille != nbFeuille)
    return 0;
  return 1;
}




Arbre_AVL_t rechercher_cle_sup_arbre (Arbre_AVL_t a, int valeur)
{
  if(a->cle <= valeur) {
    if(a->fdroite == NULL) {
      return NULL;
    }
    return rechercher_cle_sup_arbre(a->fdroite, valeur);
  } else {
    if(a->fgauche != NULL && a->fgauche->cle > valeur) {
      return rechercher_cle_sup_arbre(a->fgauche, valeur);
    }
    return a;
  }
}

Arbre_AVL_t rechercher_cle_inf_arbre (Arbre_AVL_t a, int valeur)
{
  if(a->cle >= valeur) {
    if(a->fgauche == NULL) {
      return NULL;
    }
    return rechercher_cle_inf_arbre(a->fgauche, valeur);
  } else {
    if(a->fdroite != NULL && a->fdroite->cle < valeur) {
      return rechercher_cle_inf_arbre(a->fdroite, valeur);
    }
    return a;
  }
}


Arbre_AVL_t detruire_cle_arbre (Arbre_AVL_t a, int cle)
{
  if (a == NULL)
          return a;

      if (cle < a->cle)
          a->fgauche = detruire_cle_arbre(a->fgauche, cle);

      else if (cle > a->cle)
          a->fdroite = detruire_cle_arbre(a->fdroite, cle);
      else {
          if (a->fgauche == NULL) {
              Arbre_AVL_t temp = a->fdroite;
              free(a);
              return temp;
          }
          else if (a->fdroite == NULL) {
              Arbre_AVL_t temp = a->fgauche;
              free(a);
              return temp;
          }

          Arbre_AVL_t temp = rechercher_cle_arbre(a->fdroite, trouver_cle_min(a->fdroite));

          a->cle = temp->cle;
          a->fdroite = detruire_cle_arbre(a->fdroite, temp->cle);
      }
      return a;
}



Arbre_AVL_t intersection_deux_arbres (Arbre_AVL_t a1, Arbre_AVL_t a2)
{
  Arbre_AVL_t res = (Arbre_AVL_t) malloc (sizeof(noeud_t)) ;
  pfile_t f = creer_file();
  enfiler(f, a1);
  while(f != NULL)
  {
    Arbre_AVL_t a = defiler(f);

    Arbre_AVL_t noeudCommun = rechercher_cle_arbre(a2, a->cle);
    if (noeudCommun != NULL)
      ajouter_cle(res, a->cle);

    
    if (a->fgauche != NULL)
    {
      enfiler(f, a->fgauche);
    }
    if (a->fdroite != NULL)
    {
      enfiler(f, a->fdroite);
    }
  }
  return res;
}

Arbre_AVL_t union_deux_arbres (Arbre_AVL_t a1, Arbre_AVL_t a2)
{
  //Créer un nouvel arbre
  Arbre_AVL_t res = (Arbre_AVL_t) malloc (sizeof(noeud_t));

  pfile_t f = creer_file();
  enfiler(f, a1);
  while(f != NULL)
  {
    Arbre_AVL_t a = defiler(f);
    ajouter_cle(res, a->cle);
    if (a->fgauche != NULL)
    {
      enfiler(f, a->fgauche);
    }
    if (a->fdroite != NULL)
    {
      enfiler(f, a->fdroite);
    }
  }
  enfiler(f, a2);
  while(f != NULL)
  {
    Arbre_AVL_t a = defiler(f);
    ajouter_cle(res, a->cle);

    if (a->fgauche != NULL)
    {
      enfiler(f, a2->fgauche);
    }
    if (a->fdroite != NULL)
    {
      enfiler(f, a->fdroite);
    }
  }
   return res;
}

Arbre_AVL_t rotation_gauche (Arbre_AVL_t a) {
    Arbre_AVL_t b = a->fdroite;
    a->fdroite = b->fgauche;
    b->fgauche = a;
    return b;
}

Arbre_AVL_t rotation_gauche (Arbre_AVL_t b) {
    Arbre_AVL_t a = b->fgauche;
    b->fgauche = a->fdroite;
    a->fdroite = b;
    return a;
}
