#pragma once

#include <SDL3_image/SDL_image.h>

#include "window.h"

typedef enum tiletype {
    GRASS,
    ROCK,
    SAND,
    WATER
} tiletype_t;

typedef struct tileset {
    int start_x;
    int start_y;
    tiletype_t type;
    bool is_walkable;
} tileset_t;

typedef struct sprite {
    SDL_Texture *texture;
    float x;
    float y;
    SDL_FRect dst_rect;
    const tileset_t *tileset;
} sprite_t;

sprite_t *create_sprite(char *file, SDL_Renderer *renderer);
void render_sprite(sprite_t *sprite, SDL_Renderer *renderer);
sprite_t *init_sprite(char *file, SDL_Renderer *renderer, float x, float y, tiletype_t type);
void delete_sprite(sprite_t *sprite);

sprite_t *create_grass(char *tilepath, SDL_Renderer *renderer, float x, float y);
sprite_t *create_rock(char *tilepath, SDL_Renderer *renderer, float x, float y);