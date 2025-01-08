#include "sprite.h"

static const tileset_t rock = {
    .start_x = 3,
    .start_y = 0,
    .type = ROCK,
    .is_walkable = false
};

static SDL_Texture *rock_texture = NULL;

static void init_rock_texture(char *tilepath, SDL_Renderer *renderer) {
    if (rock_texture == NULL) {
        SDL_Surface *surface = IMG_Load(tilepath);
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
}

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
} 