#pragma once

#include <SDL3/SDL.h>

#include "main.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

typedef struct window {
    SDL_Window *window;
    SDL_Renderer *renderer;
} window_t;

window_t *create_window();
void delete_window(window_t *window);