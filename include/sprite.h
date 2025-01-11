#pragma once

#include <SDL3_image/SDL_image.h>

#include "window.h"
#include "map.h"

typedef enum tiletype {
    GRASS,
    ROCK,
    SAND,
    WATER
} tiletype_t;

struct map;
typedef struct map map_t;
struct sprite;
typedef struct sprite sprite_t;

typedef sprite_t *(*choose_variant_function_t)(SDL_Renderer *renderer, map_t *map, sprite_t *sprite);

/**
 * @param start_x the square in the x collumn in the asset file
 * @param start_y the square in the Y row in the asset file
 * @param type the type of tile (tiletype_t) like GRASS or ROCK
 * @param is_walkable can it be crossed by entity
 * @param choose_variant_function what function will initialize the tile : init_function(SDL_Renderer *renderer, map_t *map, sprite_t *sprite)
 * @param tilepath the path to the asset file
 */
typedef struct tileset {
    int start_x;
    int start_y;
    tiletype_t type;
    bool is_walkable;
    char *tilepath;
    choose_variant_function_t choose_variant_function_t; /** function to initialize the right tile variant @param renderer, @param map the map, @param sprite the sprite */ 
} tileset_t;

/**
 * @param texture (SDL_Texture)
 * @param asset_x the x coordonate in the asset file (float)
 * @param asset_y the Y coordonate in the asset file (float)
 * @param map_x the x collumn in the map (uint)
 * @param map_y the y row in the map (uint)
 * @param dst_rect where it will be on the render (SDL_FRect)
 * @param tileset what set of tile it is (tileset_t)
 */
typedef struct sprite {
    SDL_Texture *texture;
    float asset_x;
    float asset_y;
    uint map_x;
    uint map_y;
    SDL_FRect dst_rect;
    tileset_t *tileset;
} sprite_t;

sprite_t *create_sprite(SDL_Renderer *renderer, sprite_t *sprite, map_t *map);
void render_sprite(sprite_t *sprite, SDL_Renderer *renderer);


tileset_t *init_tileset(tiletype_t type);
void delete_sprite(sprite_t *sprite);

tileset_t *create_grass();
tileset_t *create_rock();