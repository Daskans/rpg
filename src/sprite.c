#include "sprite.h"

sprite_t *create_sprite(char *file, SDL_Renderer *renderer) {
    sprite_t *sprite = malloc(sizeof(sprite_t));
    if (!sprite) {
        fprintf(stderr, "Failed to allocate memory for sprite\n");
        exit(EXIT_FAILURE);
    }
    sprite->texture = NULL;
    
    SDL_Surface *surface = IMG_Load(file);
    if (!surface) {
        fprintf(stderr, "Failed to load image: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    if (!sprite->texture) {
        sprite->texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (!sprite->texture) {
            fprintf(stderr, "Failed to create texture: %s\n", SDL_GetError());
            exit(EXIT_FAILURE);
        }
    }
    SDL_DestroySurface(surface);
    return sprite;
}

void render_sprite(sprite_t *sprite, SDL_Renderer *renderer) {
    SDL_FRect src_rect = {sprite->x*32.0f, sprite->y*32.0f, 32.0f, 32.0f};
    SDL_RenderTexture(renderer, sprite->texture, &src_rect, &sprite->dst_rect);
}

sprite_t *init_sprite(char *file, SDL_Renderer *renderer, float x, float y, tiletype_t type) {
    sprite_t *sprite;
    switch (type) {
        case GRASS:
            sprite = create_grass(file, renderer, x, y);
            break;
        case ROCK:
            sprite = create_rock(file, renderer, x, y);
            break;
        default:
            fprintf(stderr, "Invalid tile type\n");
            exit(EXIT_FAILURE);
    }
    return sprite;
}

void delete_sprite(sprite_t *sprite) {
    if (sprite) {
        if (sprite->texture) {
            SDL_DestroyTexture(sprite->texture);
        }
        free(sprite);
        sprite = NULL;
    }
}