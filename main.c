#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>



int main(int argc, char* argv[]) {


    // Initialize Library, setup access to window through pointer, set to use OpenGL
    bool done = false;
    SDL_Window *window;
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("1", 640, 480, SDL_WINDOW_OPENGL);

    // Main window loop
    while(!done) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                done = true;
            }
        }
    }

    // Clean program exit
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}