#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "board.h"
#include "faction.h"
#include "unit.h"
#include "building.h"
#include "alliance.h"

#include "handlers.h"

// Constants
#define MAX_PART_LEN 15
#define MAX_ACTION_LEN 10
#define MAX_FACTION_NAME_LEN 10
#define MAX_PARAMS 6

// Structures
typedef struct history {
    char attacking_faction[MAX_FACTION_NAME_LEN];
    char defending_faction[MAX_FACTION_NAME_LEN];
    int stolen_resources;
} history_t;

// Function Declarations
int read_dimensions(FILE *file, int *rows, int *columns);
int read_num_factions(FILE *file, int *num_factions);
int read_part_action(FILE *file, char *part, char *action);
int read_alliances(FILE *file, char *faction);
int read_attack(FILE *file, char *param, int *params);
int read_combat(FILE *file, char *enemy_name, int *self_value, int *enemy_value);
int read_position_faction(FILE *file, int *params);
int read_position_unit(FILE *file, int *params);
int read_building(FILE *file, int *params);
int read_move(FILE *file, int *params);
int read_collect(FILE *file, int *params);
int read_defend(FILE *file, int *params);
int read_win(FILE *file, int* type_a, char name_b[15], int* type_b);
int read_lose(FILE *file, int* type_a, char name_b[15], int* type_b);
int read_earn(FILE *file, int* param);
int read_all_file(FILE *file);

// Handlers
void handle_alliance(faction_t **factions, char *part, char *faction);
void handle_attack(faction_t **factions, char *part, char *param);
void handle_combat(char *part, char *enemy_name, int self_value, int enemy_value);
void handle_position_faction(board_t **board, faction_t **factions, char *part, int *params);
void handle_position_unit(board_t **board, faction_t **factions, unit_t **units, char *part, int *params);
void handle_move(board_t *board, unit_t **units, char part[MAX_PART_LEN], int *params);
void handle_collect(faction_t **factions, char part[MAX_PART_LEN]);
void handle_building(board_t **board, faction_t **factions, building_t **buildings, char *part, int *params);
void handle_defend(faction_t **factions, char part[MAX_PART_LEN]);

#endif // FILE_H
