#include "header.h"


// Get a random number from 0 to 255
int randInt(int rmin, int rmax) {
    return rand() % rmax + rmin;
}

int TestThread(void *p) {
    int cnt;
    p = NULL;

    for (cnt = 0; cnt < 10; cnt++) {
        printf("Thread counter: %d\n", cnt);
        SDL_Delay(1000);
    }

    return cnt;
}

int main() {
    static const int width = WIDTH;
    static const int height = HEIGHT;
    // Initialize the random number generator
    srand((unsigned int)time(NULL));
    
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window * window = SDL_CreateWindow("ENDGAME", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    // Initial renderer color
    SDL_SetRenderDrawColor(renderer, 255, 100, 0, 255);
    bool running = true;
    SDL_Event event;


    SDL_Surface * image = SDL_LoadBMP("./resource/images/pog.bmp");
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_Texture * nick = IMG_LoadTexture(renderer, "./resource/images/nick.png");

    while(running) {
        SDL_WaitEvent(&event);


        SDL_RenderCopy(renderer, nick, NULL, NULL);

        if(event.type == SDL_QUIT) {
            running = false;
        }

        else if(event.type == SDL_KEYDOWN) {
            const char *key = SDL_GetKeyName(event.key.keysym.sym);
            if(strcmp(key, "C") == 0) {
                SDL_SetRenderDrawColor(renderer, randInt(0, 255), randInt(0, 255), randInt(0, 255), 255);
            }
            else if(strcmp(key, "A") == 0) {
                printf("ok");
            }
            else if(strcmp(key, "Q") == 0)
                running = false;
        }
        SDL_RenderPresent(renderer);
    }
    // Release resources
    SDL_DestroyTexture(nick);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);

    SDL_RenderClear(renderer);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
