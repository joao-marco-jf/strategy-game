#include <stdlib.h>
#include "unit.h"

unit_t *allocate_unit(int x, int y, unit_e type){
    unit_t *new_unit = NULL;
    new_unit = (unit_t *) malloc(sizeof(unit_t));
    if(new_unit == NULL) return NULL;
    new_unit->x = x;
    new_unit->y = y;
    new_unit->type = type;
    new_unit->next = NULL;
    return new_unit;
}

void insert_unit(unit_t **units, int x, int y, unit_e type){
    unit_t *new_unit = NULL;
    new_unit = allocate_unit(x, y, type);
    if(new_unit == NULL) return;
    new_unit->next = *units;
    *units = new_unit;
}

void remove_unit(unit_t **units, int x, int y){
    unit_t *aux = *units;
    *units = (*units)->next;
    free(aux);
}
