#include "sprite.h"

sprite_t *create_sprite(SDL_Renderer *renderer, sprite_t *sprite, map_t *map) {
    sprite = sprite->tileset->choose_variant_function_t(renderer, map, sprite);
    sprite->dst_rect = (SDL_FRect){(float)sprite->map_x * 32, (float)sprite->map_y * 32, 32.0f, 32.0f};
    return sprite;
}

void render_sprite(sprite_t *sprite, SDL_Renderer *renderer) {
    SDL_FRect src_rect = {sprite->asset_x, sprite->asset_y, 32.0f, 32.0f};
    SDL_RenderTexture(renderer, sprite->texture, &src_rect, &sprite->dst_rect);
}

tileset_t *init_tileset(tiletype_t type) {
    tileset_t *tileset = malloc(sizeof(tileset_t));
    switch (type) {
        case GRASS:
            tileset = create_grass();
            break;
        case ROCK:
            tileset = create_rock();
            break;
        default:
            fprintf(stderr, "Invalid tile type\n");
            exit(EXIT_FAILURE);
    }
    return tileset;
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