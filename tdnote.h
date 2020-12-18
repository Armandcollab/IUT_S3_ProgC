#ifndef TDNOTE_H
#define TDNOTE

#include <stdbool.h>
#include "liste.h"

typedef struct Liste_s Liste_t;

Liste_t *fusion(const Liste_t *premierList,const Liste_t *deuxiemeList);
bool sousList(const Liste_t *List,const Liste_t *sousList);

#endif