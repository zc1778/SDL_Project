#include <SDL3/SDL.h>
#include "motion.h"

void moveRect(SDL_FRect *rect, float speed) {
    //Uint64 current_time = SDL_GetTicks() * 1000;
    rect->x = rect->x + speed;
}