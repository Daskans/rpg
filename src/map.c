#include "map.h"

void render_map(SDL_Renderer *renderer, map_t *map) {
    for (int j = 0; j < map->height; j++) {
        for (int i = 0; i < map->width; i++) {
            map->sprites[j][i] = create_sprite(renderer, map->sprites[j][i], map);
            render_sprite(map->sprites[j][i], renderer);
        }
    }
    SDL_RenderPresent(renderer);
}

map_t *create_map(char *file, SDL_Renderer *renderer) {
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
    map->sprites = malloc(sizeof(tileset_t **) * height);
    if (!map->sprites) {
        fprintf(stderr, "Failed to allocate memory for map tiles\n");
        exit(EXIT_FAILURE);
    }

    for (int j = 0; j < height; j++) {
        map->sprites[j] = malloc(sizeof(tileset_t *) * width);
        if (!map->sprites[j]) {
            fprintf(stderr, "Failed to allocate memory for map tiles row number %d\n", j);
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < width; i++) {
            map->sprites[j][i] = malloc(sizeof(sprite_t));
            if (!map->sprites[j][i]) {
                fprintf(stderr, "Failed to allocate memory for map tiles (%d, %d)\n", i, j);
                exit(EXIT_FAILURE);
            }
        }
    }
    int tile;
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            fscanf(fp, "%d,", &tile);
            map->sprites[j][i]->tileset = init_tileset(tile);
            map->sprites[j][i]->map_x = i;
            map->sprites[j][i]->map_y = j;
        }
    }
    fclose(fp);
    return map;
}

void delete_map(map_t *map) {
    if (map) {
        for (int j = 0; j < map->height; j++) {
            for (int i = 0; i < map->width; i++) {
                delete_sprite(map->sprites[j][i]);
            }
            free(map->sprites[j]);
            map->sprites[j] = NULL;
        }
        free(map->sprites);
        free(map);
        map = NULL;
    }
}