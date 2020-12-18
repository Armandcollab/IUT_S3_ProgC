#ifndef LISTE_H
#define LISTE_H

#include <stdbool.h>

/* *********************************************************** */
/*                         LISTE                               */
/* *********************************************************** */

typedef struct Liste_s Liste_t;
typedef void *gpointer;
typedef void (*ptr_fonction_liberation)(gpointer data);
typedef void (*ptr_fonction_affichage)(gpointer data);
typedef int (*ptr_fonction_comparaison)(gpointer data1, gpointer data2);

Liste_t *Liste_creer(ptr_fonction_liberation myfree,
                     ptr_fonction_comparaison mycomp,
                     ptr_fonction_affichage myprint);
void Liste_insererTete(Liste_t *l, gpointer v);
void Liste_inserer(Liste_t *l, gpointer v);
gpointer Liste_supprimer(Liste_t *l, gpointer v);
gpointer Liste_supprimerQueue(Liste_t *l);
int Liste_taille(const Liste_t *l);
bool Liste_vide(const Liste_t *l);
gpointer Liste_premier(const Liste_t *l);
gpointer Liste_dernier(const Liste_t *l);
void Liste_afficher(const Liste_t *l);
void Liste_liberer(Liste_t *l);
void Liste_insererQueue(Liste_t *l, gpointer v);
gpointer Liste_supprimerTete(Liste_t *l);

#endif
