#include "map.h"

void render_map(SDL_Renderer *renderer, map_t *map) {
    for (int j = 0; j < map->height; j++) {
        for (int i = 0; i < map->width; i++) {
            sprite_t *sprite = init_sprite("./assets/sprites/terrain_tile.png", renderer, (float)i * 32, (float)j * 32, map->tiles[j][i]);
            render_sprite(sprite, renderer);
        }
    }
    SDL_RenderPresent(renderer);
}

map_t *create_map(char *file) {
    map_t *map = malloc(sizeof(map_t));
    if (!map) {
        fprintf(stderr, "Failed to allocate memory for map\n");
        exit(EXIT_FAILURE);
    }
    FILE *fp = fopen(file, "r");
    if (!fp) {
        fprintf(stderr, "Failed to open file: %s\n", file);
        exit(EXIT_FAILURE);
    }
    int width, height;
    fscanf(fp, "%d,%d\n", &width, &height);
    map->width = width;
    map->height = height;
    map->tiles = malloc(sizeof(tiletype_t *) * height);
    if (!map->tiles) {
        fprintf(stderr, "Failed to allocate memory for map tiles\n");
        exit(EXIT_FAILURE);
    }

    for (int j = 0; j < height; j++) {
        map->tiles[j] = malloc(sizeof(tiletype_t) * width);
        if (!map->tiles[j]) {
            fprintf(stderr, "Failed to allocate memory for map tiles\n");
            exit(EXIT_FAILURE);
        }
    }
    int tile;
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            fscanf(fp, "%d,", &tile);
            map->tiles[j][i] = tile;
        }
    }
    return map;
}