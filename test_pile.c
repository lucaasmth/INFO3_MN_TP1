#include <stdio.h>
#include <stdlib.h>

#include "abr.h"
#include "pile.h"

int main (int argc, char**argv)
{
  ppile_t pile = creer_pile();
  pnoeud_t noeud = malloc(sizeof(pnoeud_t));
  pnoeud_t noeud1 = malloc(sizeof(pnoeud_t));
  pnoeud_t noeud2 = malloc(sizeof(pnoeud_t));
  pnoeud_t noeud3 = malloc(sizeof(pnoeud_t));
  pnoeud_t noeud4 = malloc(sizeof(pnoeud_t));
  noeud->cle = 0;
  noeud1->cle = 1;
  noeud2->cle = 2;
  noeud3->cle = 3;
  noeud4->cle = 4;
  
  empiler(pile, noeud);
  empiler(pile, noeud1);
  empiler(pile, noeud2);
  empiler(pile, noeud3);
  empiler(pile, noeud4);

    for (int i = 0; i < 5; i++)
    {
        printf("Valeur %i : %i\n", i, depiler(pile)->cle);
    }
    printf("Est vide ? %i\n", pile_vide(pile));


    for (int i = 0; i < 32; i++)
    {
        empiler(pile, noeud4);
    }
    printf("Est pleine ? %i\n", pile_pleine(pile));
}
