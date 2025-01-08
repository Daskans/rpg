#pragma once

#include "window.h"
#include "sprite.h"

typedef struct map {
    int width;
    int height;
    tiletype_t **tiles;
} map_t;

map_t *create_map(char *file);
void render_map(SDL_Renderer *renderer, map_t *map);