#pragma once

#include "main.h"
#include "map.h"

typedef enum {
    NORTH,
    EAST,
    SOUTH,
    WEST
} direction_t;

typedef struct coord {
    uint x;
    uint y;
} coord_t;

typedef enum entityType {
    PLAYER,
    ZOMBIE
} entityType_t;

typedef struct entity {
    uint max_health;
    uint health;
    coord_t coord;
    entityType_t type;
    char* name;
} entity_t;

entity_t* create_entity(uint max_health, uint health, coord_t coord, entityType_t type, char* name);
void delete_entity(entity_t* entity);

void move_entity(entity_t* entity, direction_t direction, map_t* map);