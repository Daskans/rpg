#include "sprite.h"


static SDL_Texture *grass_texture = NULL;

sprite_t *init_grass_texture(SDL_Renderer *renderer, float x, float y, map_t *map, sprite_t *sprite) {
    if (grass_texture == NULL) {
        SDL_Surface *surface = IMG_Load(sprite->tileset->tilepath);
        if (surface == NULL) {
            fprintf(stderr, "Error loading image: %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }

        grass_texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (grass_texture == NULL) {
            fprintf(stderr, "Error creating grass texture: %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        SDL_DestroySurface(surface);
    }
    sprite->texture = grass_texture;
    sprite->asset_x = (float)(sprite->tileset->start_x + 1) * 32;
    sprite->asset_y = (float)(sprite->tileset->start_y + 1) * 32;
    return sprite;
}
/*
sprite_t *create_grass(char *tilepath, SDL_Renderer *renderer, float x, float y) {
    init_grass_texture(tilepath, renderer);

    sprite_t *sprite = malloc(sizeof(sprite_t));
    if (sprite == NULL) {
        fprintf(stderr, "Error allocating memory for grass sprite: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    sprite->texture = grass_texture;
    sprite->tileset = &grass;
    sprite->x = (float)grass.start_x + 1;
    sprite->y = (float)grass.start_y + 2;
    sprite->dst_rect = (SDL_FRect){x, y, 32.0f, 32.0f};

    render_sprite(sprite, renderer);

    return sprite;
} */
static const tileset_t grass = {0, 0, GRASS, true, TERRAIN_TILE_FILE_PATH, init_grass_texture};

tileset_t *create_grass() {
    return &grass;
}