#include <stdio.h>
#include <stdlib.h>

#include "abr.h"
#include "file.h"

int main (int argc, char**argv)
{
    pfile_t file = creer_file();
    // for(int i = 0; i < 5; i++) {
    //     pnoeud_t noeud = malloc(sizeof(noeud_t));
    //     noeud->cle = i;
    //     enfiler(file, noeud);
    // }
    // for(int i = 0; i < 5; i++) {
    //     pnoeud_t noeud = defiler(file); 
    //     printf("%i\n", noeud->cle);
    //     free(noeud);
    // }

    printf("Vide? %i\n", file_vide(file));

    for(int i = 0; i < 32; i++) {
        pnoeud_t noeud = malloc(sizeof(noeud_t));
        noeud->cle = i;
        //printf("Queue: %i\n", file->queue);
        enfiler(file, noeud);
    }

    printf("Pleine? %i\n", file_pleine(file));

    for(int i = 0; i < 32; i++) {
        //printf("Tete: %i\n", file->tete);
        printf("%i\n", defiler(file)->cle);
    }
    printf("Pleine? %i\n", file_pleine(file));
    printf("Vide? %i\n", file_vide(file));
}