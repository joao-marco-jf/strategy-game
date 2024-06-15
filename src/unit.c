/**
 * @file unit.c
 * @brief Implementação das funções relacionadas às unidades.
 */

#include <stdlib.h>
#include "game/unit.h"

/**
 * @brief Aloca memória para uma nova unidade e inicializa suas propriedades.
 * 
 * @param x A coordenada x da unidade.
 * @param y A coordenada y da unidade.
 * @param type O tipo da unidade.
 * @return Um ponteiro para a unidade recém-alocada.
 *         Retorna NULL se a alocação de memória falhar.
 */
unit_t *allocate_unit(int x, int y, char name[15], unit_e type){                  //Esta função aloca memória para uma nova instância de uma unidade, inicializa suas coordenadas e tipo.
    unit_t *new_unit = NULL;
    new_unit = (unit_t *) malloc(sizeof(unit_t));
    if(new_unit == NULL) return NULL;
    strcpy(new_unit->name, name);
    new_unit->x = x;
    new_unit->y = y;
    new_unit->type = type;
    new_unit->next = NULL;
    return new_unit;
}

/**
 * @brief Insere uma nova unidade no início da lista de unidades.
 * 
 * @param units Um ponteiro para o ponteiro da lista de unidades.
 * @param x A coordenada x da unidade.
 * @param y A coordenada y da unidade.
 * @param type O tipo da unidade.
 */
void insert_unit(unit_t **units, int x, int y, char name[15], unit_e type){      //Esta função insere uma nova unidade no início da lista ligada de unidades.
    unit_t *new_unit = NULL;
    new_unit = allocate_unit(x, y, name, type);
    if(new_unit == NULL) return;
    new_unit->next = *units;
    *units = new_unit;
}

/**
 * @brief Remove uma unidade da lista de unidades.
 * 
 * @param units Um ponteiro para o ponteiro da lista de unidades.
 * @param x A coordenada x da unidade a ser removida.
 * @param y A coordenada y da unidade a ser removida.
 */
void remove_unit(unit_t **units, int x, int y){
    unit_t *current = *units;
    unit_t *previous = NULL;
    while(current != NULL){
        if(current->x == x && current->y == y){
            if(previous == NULL){
                *units = current->next;
            }
            else{
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}
