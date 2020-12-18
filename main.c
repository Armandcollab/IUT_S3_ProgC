#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "liste.h"
#include "tdnote.h"

void free_int(gpointer data)
{
    free(data);
}

int comp_int(gpointer data1, gpointer data2)
{
    int *ptr_v1 = (int *)data1;
    int *ptr_v2 = (int *)data2;
    if (*ptr_v1 == *ptr_v2)
        return 0;
    if (*ptr_v1 > *ptr_v2)
        return +1;
    return -1;
}

void print_int(gpointer data)
{
    int *ptr_v = (int *)data;
    printf("%d ", *ptr_v);
}

int main(void)
{

    /* *********************************************************** */
    /*                 Test 1 : Listes identiques                  */
    /* *********************************************************** */

    /*
    struct Liste_s *lg = Liste_creer( free_int, comp_int, print_int);
    for ( int i = 0; i < 100; i++ ) {
        int *ptr_v = (int *)malloc( sizeof( int ) );
        *ptr_v     = i;
        Liste_inserer( lg, ptr_v );
    }
    
    struct Liste_s *ld = Liste_creer( free_int, comp_int, print_int);
    for ( int i = 0; i < 100; i++ ) {
        int *ptr_v = (int *)malloc( sizeof( int ) );
        *ptr_v     = i;
        Liste_inserer( ld, ptr_v );
    }
    
*/

    /* *********************************************************** */
    /*       TEST 2 : Liste différentes sur in intervalle proche   */
    /* *********************************************************** */

    /*
    struct Liste_s *lg = Liste_creer(free_int, comp_int, print_int);
    for (int i = 2; i < 100; i++)
    {
        int *ptr_v = (int *)malloc(sizeof(int));
        *ptr_v = i;
        Liste_inserer(lg, ptr_v);
    }

    struct Liste_s *ld = Liste_creer(free_int, comp_int, print_int);
    for (int i = 0; i < 100; i++)
    {
        int *ptr_v = (int *)malloc(sizeof(int));
        *ptr_v = i;
        Liste_inserer(ld, ptr_v);
    }

    Liste_afficher(lg);
    Liste_afficher(ld);

    Liste_afficher(fusion(lg, ld));

*/

    /* *********************************************************** */
    /*       TEST 3 : Listes différentes sur intervalle éloigné    */
    /* *********************************************************** */

/*
    struct Liste_s *lg = Liste_creer(free_int, comp_int, print_int);
    for (int i = 1; i < 100; i++)
    {
        int *ptr_v = (int *)malloc(sizeof(int));
        *ptr_v = i;
        Liste_inserer(lg, ptr_v);
    }

    struct Liste_s *ld = Liste_creer(free_int, comp_int, print_int);
    for (int i = 100; i < 200; i++)
    {
        int *ptr_v = (int *)malloc(sizeof(int));
        *ptr_v = i;
        Liste_inserer(ld, ptr_v);
    }
    */



   /* *********************************************************** */
    /*       TEST 4 : Liste 1 nulle                                */
    /* *********************************************************** */

    /*
    struct Liste_s *lg = Liste_creer(free_int, comp_int, print_int);

    struct Liste_s *ld = Liste_creer(free_int, comp_int, print_int);
    for (int i = 0; i < 100; i++)
    {
        int *ptr_v = (int *)malloc(sizeof(int));
        *ptr_v = i;
        Liste_inserer(ld, ptr_v);
    }
    */



/* *********************************************************** */
    /*       TEST 5 : Liste 2 nulle                                */
    /* *********************************************************** */

    /*
    struct Liste_s *lg = Liste_creer(free_int, comp_int, print_int);
    for (int i = 0; i < 100; i++)
    {
        int *ptr_v = (int *)malloc(sizeof(int));
        *ptr_v = i;
        Liste_inserer(lg, ptr_v);
    }

    struct Liste_s *ld = Liste_creer(free_int, comp_int, print_int);
    */



/* *********************************************************** */
    /*       TEST 6 : Deux listes nulles                           */
    /* *********************************************************** */

    /*
    struct Liste_s *lg = Liste_creer(free_int, comp_int, print_int);


    struct Liste_s *ld = Liste_creer(free_int, comp_int, print_int);
*/


    /* *********************************************************** */
    /*       TEST 7 : Listes identiques                                */
    /* *********************************************************** */

    /*
    struct Liste_s *lg = Liste_creer(free_int, comp_int, print_int);
    for (int i = 2; i < 100; i++)
    {
        int *ptr_v = (int *)malloc(sizeof(int));
        *ptr_v = 6;
        Liste_inserer(lg, ptr_v);
    }

    struct Liste_s *ld = Liste_creer(free_int, comp_int, print_int);
    for (int i = 0; i < 100; i++)
    {
        int *ptr_v = (int *)malloc(sizeof(int));
        *ptr_v = 6;
        Liste_inserer(ld, ptr_v);
    }
    */


    /* *********************************************************** */
    /*       TEST 8 : Listes 1 et 2 avec chiffres constants        */
    /* *********************************************************** */

    /*  
    struct Liste_s *lg = Liste_creer(free_int, comp_int, print_int);
    for (int i = 2; i < 100; i++)
    {
        int *ptr_v = (int *)malloc(sizeof(int));
        *ptr_v = 2;
        Liste_inserer(lg, ptr_v);
    }

    struct Liste_s *ld = Liste_creer(free_int, comp_int, print_int);
    for (int i = 0; i < 100; i++)
    {
        int *ptr_v = (int *)malloc(sizeof(int));
        *ptr_v = 4;
        Liste_inserer(ld, ptr_v);
    }

    printf("%s\n","Liste gauche :" );
    Liste_afficher(lg);
    printf("%s\n","Liste droite :" );
    Liste_afficher(ld);
    printf("%s\n","Liste fusionnée :" );
    Liste_afficher(fusion(lg, ld));
    */


    return EXIT_SUCCESS;
}