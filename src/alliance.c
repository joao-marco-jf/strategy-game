#include <stdio.h>
#include <string.h>

#include "alliance.h"

alliance_t *allocate_alliance(char name[15]){
    alliance_t *new_alliance = NULL;
    new_alliance = (alliance_t *) malloc(sizeof(alliance_t));
    if(new_alliance == NULL) return NULL;
    strcpy(new_alliance->name, name);
    new_alliance->next = NULL;
    return new_alliance;
}

void insert_alliance(alliance_t **alliances, char name[15]){

}

void remove_alliance(alliance_t **alliances, char name[15]){

}