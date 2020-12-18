#include <stdlib.h>
#include "tdnote.h"
#include "liste.h"

Liste_t *fusion(Liste_t *premierList, Liste_t *deuxiemeList)
{
    while (!Liste_vide(deuxiemeList))
    {
       Liste_inserer(premierList,Liste_supprimerTete(deuxiemeList));
    }
    
    return(premierList);
}

bool
sousList(Liste_t *List, Liste_t *sousList)
{
    return false;
}