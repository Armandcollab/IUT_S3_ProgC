#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "liste.h"

struct Element_s {
    gpointer          valeur;
    struct Element_s *succ;
    struct Element_s *pred;
};

struct Liste_s {
    struct Element_s *       tete;
    struct Element_s *       queue;
    unsigned int             taille;
    ptr_fonction_liberation  myfree;
    ptr_fonction_comparaison mycomp;
    ptr_fonction_affichage   myprint;
};

typedef struct Element_s Element_t;

Liste_t *
Liste_creer( ptr_fonction_liberation  myfree,
             ptr_fonction_comparaison mycomp,
             ptr_fonction_affichage   myprint )
{
    Liste_t *l = malloc( sizeof( Liste_t ) );
    l->tete    = NULL;
    l->queue   = NULL;
    l->taille  = 0;
    l->myfree  = myfree;
    l->mycomp  = mycomp;
    l->myprint = myprint;
    return l;
}

void
Liste_insererTete( Liste_t *l, gpointer v )
{
    assert( NULL != l );
    Element_t *e = malloc( sizeof( Element_t ) );
    e->valeur    = v;
    e->pred      = NULL;
    e->succ      = l->tete;
    if ( NULL == l->tete )  // on ajoute le premier element de la liste
        l->queue = e;
    else
        l->tete->pred = e;
    l->tete = e;
    l->taille++;
}

void
Liste_insererApres( Liste_t *l, gpointer v, Element_t *e_pred )
{
    assert( NULL != l );
    Element_t *e = malloc( sizeof( Element_t ) );
    assert( NULL != e );
    e->valeur = v;
    e->pred   = e_pred;
    e->succ   = e_pred->succ;
    if ( NULL == e_pred->succ )  // insertion en queue de liste
        l->queue = e;
    else
        e_pred->succ->pred = e;
    e_pred->succ = e;
    l->taille++;
}

Element_t *
Liste_rechercherPos( Liste_t *l, gpointer v )
{
    assert( NULL != l );
    if ( Liste_vide( l ) )
        return NULL;
    Element_t *e      = l->tete;
    Element_t *e_pred = NULL;
    bool       trouve = false;
    while ( ( !trouve ) && ( NULL != e ) ) {
        if ( +1 == l->mycomp( e->valeur, v ) )  // stop si e->valeur > v
            trouve = true;
        else {
            e_pred = e;
            e      = e->succ;
        }
    }
    return e_pred;
}

void
Liste_inserer( Liste_t *l, gpointer v )
{
    assert( NULL != l );
    Element_t *e = Liste_rechercherPos( l, v );
    if ( NULL == e )
        Liste_insererTete( l, v );
    else
        Liste_insererApres( l, v, e );
}

Element_t *
Liste_rechercherElement( Liste_t *l, gpointer v )
{
    assert( NULL != l );
    Element_t *e      = l->tete;
    bool       trouve = false;
    bool       fini   = false;  // stop si les elements restants sont plus grands
    while ( ( !trouve ) && ( !fini ) && ( NULL != e ) ) {
        if ( l->mycomp( e->valeur, v ) == 0 )  // ( e->valeur == v ) comparaison
            trouve = true;
        else if ( l->mycomp( e->valeur, v ) == +1 ) {  // liste triee
            fini = true;
        }
        else {
            e = e->succ;
        }
    }
    if ( trouve )
        return e;
    else
        return NULL;
}

gpointer
Liste_supprimer( Liste_t *l, gpointer v )
{
    assert( NULL != l );
    Element_t *e = Liste_rechercherElement( l, v );
    if ( NULL == e )  // element non trouve
        return NULL;
    if ( NULL != e->pred )
        e->pred->succ = e->succ;
    else
        l->tete = e->succ;  // tete liste
    if ( NULL != e->succ )
        e->succ->pred = e->pred;
    else
        l->queue = e->pred;  // queue liste
    gpointer vv = e->valeur;
    assert( l->mycomp( v, vv ) == 0 );
    free( e );
    l->taille--;
    return vv;
}

gpointer
Liste_supprimerQueue( Liste_t *l )
{
    assert( NULL != l );
    assert( NULL != l->queue );
    gpointer   v    = l->queue->valeur;
    Element_t *pred = l->queue->pred;
    if ( NULL == pred )  // 1 seul element dans la file
        l->tete = NULL;
    free( l->queue );
    l->queue = pred;
    l->taille--;
    return v;
}

int
Liste_taille( const Liste_t *l )
{
    assert( NULL != l );
    return l->taille;
}

bool
Liste_vide( const Liste_t *l )
{
    assert( NULL != l );
    if ( 0 == l->taille ) {
        assert( NULL == l->tete );
        assert( NULL == l->queue );
    }
    return 0 == l->taille;
}

gpointer
Liste_premier( const Liste_t *l )
{
    assert( NULL != l );
    assert( NULL != l->tete );
    return l->tete->valeur;
}

gpointer
Liste_dernier( const Liste_t *l )
{
    assert( NULL != l );
    assert( NULL != l->queue );
    return l->queue->valeur;
}

void
Liste_afficher( const Liste_t *l )
{
    assert( NULL != l );
    if ( Liste_vide( l ) )
        return;
    printf( "LISTE: " );
    Element_t *e = l->tete;
    gpointer   v = e->valeur;
    l->myprint( v );
    while ( NULL != e->succ ) {
        e = e->succ;
        v = e->valeur;
        l->myprint( v );
    }
    printf( "\n" );
}

void
Liste_liberer( Liste_t *l )
{
    while ( !Liste_vide( l ) ) {
        gpointer v = Liste_supprimerQueue( l );
        l->myfree( v );
    }
    assert( NULL != l );
    free( l );
}

void
Liste_insererQueue( Liste_t *l, gpointer v )
{
    assert( NULL != l );
    Element_t *e = malloc( sizeof( Element_t ) );
    assert( NULL != e );
    e->valeur = v;
    e->succ   = NULL;
    e->pred   = l->queue;
    if ( NULL != l->queue )
        l->queue->succ = e;
    l->queue = e;
    if ( NULL == l->tete )
        l->tete = e;
    l->taille++;
}

gpointer
Liste_supprimerTete( Liste_t *l )
{
    assert( NULL != l );
    assert( l->taille > 0 );
    assert( l->tete );
    gpointer   v    = l->tete->valeur;
    Element_t *succ = l->tete->succ;
    if ( NULL != succ )
        succ->pred = NULL;
    free( l->tete );
    l->tete = succ;
    if ( NULL == succ )
        l->queue = NULL;
    l->taille--;
    return v;
}