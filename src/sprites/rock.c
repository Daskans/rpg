#include "sprite.h"


static SDL_Texture *rock_texture = NULL;

sprite_t *init_rock_texture(SDL_Renderer *renderer, map_t *map, sprite_t *sprite) {
    if (rock_texture == NULL) {
        SDL_Surface *surface = IMG_Load(sprite->tileset->tilepath);
        if (surface == NULL) {
            fprintf(stderr, "Error loading image: %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }

        rock_texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (rock_texture == NULL) {
            fprintf(stderr, "Error creating rock texture: %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        SDL_DestroySurface(surface);
    }
    sprite->texture = rock_texture;
    if (sprite->map_y < map->height - 1 && map->sprites[sprite->map_y + 1][sprite->map_x]->tileset->type == GRASS) {
        sprite->asset_x = (float)(sprite->tileset->start_x + 1) * 32;
        sprite->asset_y = (float)(sprite->tileset->start_y + 3) * 32;
    } else {
        sprite->asset_x = (float)(sprite->tileset->start_x + 1) * 32;
        sprite->asset_y = (float)(sprite->tileset->start_y + 2) * 32;
    }
    return sprite;
}
/*
sprite_t *create_rock(char *tilepath, SDL_Renderer *renderer, float x, float y) {
    init_rock_texture(tilepath, renderer);

    sprite_t *sprite = malloc(sizeof(sprite_t));
    if (sprite == NULL) {
        fprintf(stderr, "Error allocating memory for rock sprite: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    sprite->texture = rock_texture;
    sprite->tileset = &rock;
    sprite->x = (float)rock.start_x + 1;
    sprite->y = (float)rock.start_y + 2;
    sprite->dst_rect = (SDL_FRect){x, y, 32.0f, 32.0f};

    render_sprite(sprite, renderer);

    return sprite;
} */
static const tileset_t rock = {3, 0, ROCK, false, TERRAIN_TILE_FILE_PATH, init_rock_texture};

tileset_t *create_rock() {
    return &rock;
}