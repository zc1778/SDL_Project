#include <SDL3/SDL.h>
#include "motion.h"

void moveRect(SDL_FRect *rect, float speed, char dimension, Uint64 *current_time, bool gravity) {
    switch (dimension) {
        case 'x': rect->x = speed * (float)*current_time; break;
        case 'y': rect->y = speed * (float)*current_time; break;
    }
    if (gravity) {
        rect->y = 0.00098 * (float)*current_time;
    }
}

void rectFrame(SDL_Renderer *renderer, SDL_FRect *rect) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderRect(renderer, rect);
    SDL_RenderPresent(renderer);
}