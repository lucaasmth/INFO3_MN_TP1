#include <stdlib.h>

#include "abr.h"
#include "file.h"

pfile_t creer_file ()
{
  pfile_t file = malloc(sizeof(file_t));
  file->queue = 0;
  file->tete = 0;
  return file;
}

int detruire_file (pfile_t f)
{
  free(f);
  return 1;
}


int file_vide (pfile_t f)
{
  return f->tete == f->queue;
}

int file_pleine (pfile_t f)
{
  return f->tete == (f->queue + 1) % 32;
}

pnoeud_t defiler (pfile_t f)
{
  /*if(file_vide(f)) {
    return NULL;
  }*/
  f->tete = (f->tete + 1) % 32;
  if(f->tete == 0) return f->Tab[31];
  return f->Tab[f->tete - 1];
}

int enfiler (pfile_t f, pnoeud_t p)
{
  /*if(file_pleine(f)) {
    return 0;
  }*/
  f->queue = (f->queue + 1) % 32;
  if(f->queue == 0) f->Tab[31] = p;
  else f->Tab[f->queue - 1] = p;
  return 1;
}
