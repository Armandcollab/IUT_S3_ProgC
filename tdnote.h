#ifndef TDNOTE_H
#define TDNOTE

#include <stdbool.h>
#include "liste.h"

typedef struct Liste_s Liste_t;

Liste_t *fusion(Liste_t *premierList, Liste_t *deuxiemeList);
bool sousList(Liste_t *List, Liste_t *sousList);

#endif