/**
 * @file alliance.c
 * @brief Implementação das funções relacionadas às alianças do jogo.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "game/alliance.h"

/**
 * @brief Aloca memória para uma nova aliança e inicializa seus atributos.
 * 
 * @param name O nome da aliança.
 * @return Um ponteiro para a nova aliança alocada.
 */
alliance_t *allocate_alliance(char name[15]){
    alliance_t *new_alliance = NULL;
    new_alliance = (alliance_t *) malloc(sizeof(alliance_t));
    if(new_alliance == NULL) return NULL;
    strcpy(new_alliance->name, name);
    new_alliance->next = NULL;
    return new_alliance;
}

/**
 * @brief Insere uma nova aliança no início da lista de alianças.
 * 
 * @param alliances Um ponteiro para o ponteiro da lista de alianças.
 * @param name O nome da aliança a ser inserida.
 */
void insert_alliance(alliance_t **alliances, char name[15]){
    alliance_t *new_alliance = NULL;
    new_alliance = allocate_alliance(name);
    if(new_alliance == NULL) return;
    new_alliance->next = *alliances;
    *alliances = new_alliance;
}

/**
 * @brief Remove uma aliança da lista de alianças.
 * 
 * @param alliances Um ponteiro para o ponteiro da lista de alianças.
 * @param name O nome da aliança a ser removida.
 */
void remove_alliance(alliance_t **alliances, char name[15]){
    
}