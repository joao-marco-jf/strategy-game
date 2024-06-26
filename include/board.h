#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "faction.h"
#include "building.h"
#include "unit.h"

typedef enum node_e{
    PLANICE = 0,
    FLORESTA = 1,
    MONTANHA = 2
} node_e;

typedef struct node_t{
    int line;
    int col;
    unit_t *unit;
    unit_t *unit1;
    unit_t *unit2;
    building_t *building;
    faction_t *faction;
    struct node_t *next;
} node_t;

typedef struct board_t{
    int lines;
    int columns;
    node_t *head;
}board_t;

board_t *create_board(int lines, int columns);
node_t *allocate_node(int line, int col, unit_t* unit, building_t* building, faction_t* faction);
void insert_node(board_t *board, int line, int col, unit_t *unit, building_t *building, faction_t *faction);
faction_t *get_faction_board(board_t *board, int line, int col);
building_t *get_building_board(board_t *board, int line, int col);
unit_t *get_unit_board(board_t *board, int line, int col);
unit_t *get_unit1_board(board_t *board, int line, int col);
unit_t *get_unit2_board(board_t *board, int line, int col);
void remove_node(board_t *board_t, int row, int col);
void free_board(board_t *board);
void print_board(FILE *log, board_t *board);

#endif