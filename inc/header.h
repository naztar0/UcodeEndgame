#ifndef ENDGAME_H
#define ENDGAME_H

#define WINDOW_WIDTH (1280)
#define WINDOW_HEIGHT (720)
#define SCROLL_SPEED (300)

// Utility macros
#define WIDTH 1920;
#define HEIGHT 1080;
#define CHECK_ERROR(test, message) if((test)) {fprintf(stderr, "%s\n", (message)); exit(1);}

// SDL2 Frameworks
#include <SDL2/SDL.h>
#include "SDL2_image/SDL_image.h"
#include "SDL2_mixer/SDL_mixer.h"
#include "SDL2_rotozoom.h"
#include "SDL2_ttf/SDL_ttf.h"

// Sytem Libriaries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>

#endif
