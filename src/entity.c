#include "entity.h"


entity_t* create_entity(uint max_health, uint health, coord_t coord, entityType_t type, char* name) {
    entity_t* entity = malloc(sizeof(entity_t));
    entity->max_health = max_health;
    entity->health = health;
    entity->coord = coord;
    entity->type = type;
    entity->name = name;
    return entity;
}

void delete_entity(entity_t* entity) {
    if (entity) {
        free(entity);
    }
}

void move_entity(entity_t* entity, direction_t direction, map_t* map) {
    coord_t new_coord = entity->coord;
    switch (direction) {
        case NORTH:
            if (new_coord.y > 0) {
                new_coord.y -= 1;
            }
            break;
        case EAST:
            if (new_coord.x < map->width - 1) {
                new_coord.x += 1;
            }
            break;
        case SOUTH:
            if (new_coord.y < map->height - 1) {
                new_coord.y += 1;
            }
            break;
        case WEST:
            if (new_coord.x > 0) {
                new_coord.x -= 1;
            }
            break;
    }/*
    if (map->tiles[new_coord.y][new_coord.x].is_walkable) {
        entity->coord = new_coord;
    }*/
    
}