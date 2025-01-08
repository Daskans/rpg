#include "window.h"

window_t *create_window() {
    window_t *window = malloc(sizeof(window_t));
    if (!window) {
        perror("failed to malloc the window");
        return NULL;
    }

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "SDL initialization failed: %s\n", SDL_GetError());
        delete_window(window);
        return NULL;
    }

    window->window = SDL_CreateWindow("RPG Game", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
    if (!window->window) {
        fprintf(stderr, "Window creation failed: %s\n", SDL_GetError());
        delete_window(window);
        return NULL;
    }

    window->renderer = SDL_CreateRenderer(window->window, NULL);
    if (!window->renderer) {
        fprintf(stderr, "Renderer creation failed: %s\n", SDL_GetError());
        delete_window(window);
        return NULL;
    }

    return window;
}

void delete_window(window_t *window) {
    if (window) {
        SDL_DestroyRenderer(window->renderer);
        SDL_DestroyWindow(window->window);
        free(window);
        window = NULL;
    }
}