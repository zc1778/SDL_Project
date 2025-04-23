#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "motion.h"

int main(int argc, char* argv[]) {

    // Initialize Library, setup access to window through pointer, set to use OpenGL
    bool done = false;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("1", 640, 480, SDL_WINDOW_OPENGL);

    // Setup renderer and draw rectangle
    renderer = SDL_CreateRenderer(window, NULL);
    SDL_FRect rect = {0, 0, 100, 100};

    // Main window loop
    while(!done) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                done = true;
            }
        }

        Uint64 current_time = SDL_GetTicks() * 1000;
        moveRect(&rect, 0.0001, 'y', &current_time);
        moveRect(&rect, 0.0001, 'x', &current_time);

        //Render frame redrawing
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderRect(renderer, &rect);
        SDL_RenderPresent(renderer);

    }

    // Clean program exit
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}