
#include "main.h"
#include "map.h"

int main(int argc, char *argv[]) {
    window_t *window = create_window();
    map_t *map = create_map("./assets/maps/test");
    render_map(window->renderer, map);

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }
    }


    return EXIT_SUCCESS;
}