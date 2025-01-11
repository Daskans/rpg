#pragma once

#include "window.h"
#include "sprite.h"

struct sprite;
typedef struct sprite sprite_t;

typedef struct map {
    uint width;
    uint height;
    sprite_t ***sprites;
} map_t;

map_t *create_map(char *file, SDL_Renderer *renderer);
void render_map(SDL_Renderer *renderer, map_t *map);