#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "file.h"

File_t *File_creer(ptr_fonction_liberation myfree, ptr_fonction_affichage myprint)
{
    File_t *f = malloc(sizeof(File_t));
    f->tete = NULL;
    f->queue = NULL;
    f->taille = 0;
    f->myfree  = myfree;
    f->myprint = myprint;
    return f;
}
void File_enfiler(File_t *f, int v)
{
    assert(NULL != f);
    Element_t *e = malloc(sizeof(Element_t));
    e->valeur = v;
    e->pred = NULL;
    e->succ = f->tete;
    if (NULL == f->tete)
        f->queue = e;
    else
        f->tete->pred = e;
    f->tete = e;
    f->taille++;
}
int File_defiler(File_t *f)
{
    assert(NULL != f);
    assert(NULL != f->queue);
    int v = f->queue->valeur;
    Element_t *pred = f->queue->pred;
    if (pred == NULL)
        f->tete = NULL;

    free(f->queue);
    f->queue = pred;
    f->taille--;
    return v;
}
void File_afficher(const File_t *f)
{
    assert(f != NULL);
    if (File_vide(f))
        return;
    printf("File : ");
    Element_t *e = f->queue;
    gpointer v = f->queue->valeur;
    f->myprint(v);
    while (NULL != e->pred)
    {
        e = e->pred;
        v = e->valeur;
        f->myprint(v);
    }
    printf("\n");
}
int File_taille(const File_t *f)
{
    assert(NULL != f);
    return f->taille;
}
bool File_vide(const File_t *f)
{
    assert(NULL != f);
    if (0 == f->taille)
    {
        assert(NULL == f->tete);
        assert(NULL == f->queue);
    }
    return (f->taille == 0);
}
int File_premier(const File_t *f)
{
    assert(NULL != f);
    assert(NULL != f->tete);
    return f->tete->valeur;
}
int File_dernier(const File_t *f)
{
    assert(NULL != f);
    assert(NULL != f->queue);
    return f->queue->valeur;
}
void File_liberer(File_t *f)
{
    while (!File_vide(f))
    {
        gpointer v = File_defiler( f );
        f->myfree( v );
    }
    assert(NULL != f);
    free(f);
}