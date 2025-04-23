#include <SDL3/SDL.h>
#include "motion.h"

void moveRect(SDL_FRect *rect, float speed, char dimension, Uint64 *current_time) {
    switch (dimension) {
        case 'x': rect->x = speed * (float)*current_time; break;
        case 'y': rect->y = speed * (float)*current_time; break;
    }
}