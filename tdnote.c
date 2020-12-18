#include <stdlib.h>
#include "tdnote.h"
#include "liste.h"

Liste_t *fusion(const Liste_t *premierList, const Liste_t *deuxiemeList)
{
    while (!Liste_vide(deuxiemeList))
    {
        Liste_inserer(premierList, Liste_supprimerTete(deuxiemeList));
    }

    return (premierList);
}

bool sousList(const Liste_t *List, const Liste_t *sousList)
{
    //Il faudrait copier List mais nous n'avons pas le temps
    Liste_t *sousListCopie = malloc(sizeof(Liste_s));
    Liste_Copie(sousListCopie, sousList);
    Liste_t *listeCopie;
    Liste_Copie(listeCopie, sousList);
    Liste_t *sousListTmp;
    bool trouve = false;

    while (trouve || !Liste_vide(List))
    {
        if (Liste_premier(List) != Liste_Premier(sousListCopie))
        {
            Liste_supprimerTete(List);
            while (!Liste_vide(sousListCopie))
            {
                sousListCopie = Liste_supprimerTete(sousListCopie);
            }
            Liste_Copie(sousListTmp, sousList);
        }
        if (Liste_premier(List) == Liste_Premier(sousList))
        {
            Liste_inserer(sousListCopie, Liste_Premier(List));
        }
        if (sousListCopie == sousList)
        {
            trouve = true;
        }
    }
    free(sousListCopie);
    free(sousList);
    return trouve;
}