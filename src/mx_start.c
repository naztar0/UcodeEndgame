#include "header.h"

SDL_Renderer *mx_jump(SDL_Renderer *renderer, bool *jump, bool *down, t_position *pos, float ground, bool runL, bool runR) {
    if (*jump) {
        if (pos->y > ground - JUMP_HEIGHT) {
            pos->y -= JUMP_STEP;
            if (runL)
                pos->x -= MOVE_STEP;
            else if (runR)
                pos->x += MOVE_STEP;
        }
        else if (pos->y <=  ground - JUMP_HEIGHT) {
            *jump = false;
            *down = true;
        }
    }
    else {
        if (pos->y != ground) {
            SDL_Delay(1);
            pos->y += JUMP_STEP;
            if (runL)
                pos->x -= MOVE_STEP;
            else if (runR)
                pos->x += MOVE_STEP;
        }
        else
            *down = false;
    }
    return renderer;
}

void mx_start(SDL_Renderer *renderer) {
    bool game = true;
    SDL_Event event;

    SDL_Texture* bg1 = IMG_LoadTexture(renderer, "./resource/images/background.png");
    SDL_Texture* bg2 = IMG_LoadTexture(renderer, "./resource/images/background.png");
    SDL_Texture* moon = IMG_LoadTexture(renderer, "./resource/images/moon.png");
    SDL_Texture* neo_stand = IMG_LoadTexture(renderer, "./resource/images/neo_stand.png");
    SDL_Texture* neo_runR = IMG_LoadTexture(renderer, "./resource/images/neo_runR.png");
    SDL_Texture* neo_runL = IMG_LoadTexture(renderer, "./resource/images/neo_runL.png");
    SDL_Texture* neo_jumpR = IMG_LoadTexture(renderer, "./resource/images/neo_jumpR.png");
    SDL_Texture* neo_jumpL = IMG_LoadTexture(renderer, "./resource/images/neo_jumpL.png");

    Mix_Music *backgroundSound = Mix_LoadMUS(mx_pickmusic());
    Mix_PlayMusic(backgroundSound, -1);

    t_position pos;
    pos.x = 440, pos.y = WINDOW_HEIGHT - 300;
    float ground = pos.y;
    const char *key;
    Uint32 ticks;
    Uint32 stand;
    Uint32 run;
    Uint32 jump;

    bool walk = false;
    bool jump_process = false;
    bool jump_down_process = false;
    bool runR = false;
    bool runL = false;

    int bg_num = 1;
    float bg1_pos = 0, bg2_pos = WINDOW_WIDTH;
    //t_position TEMP_pos = {pos.x, pos.y};
    while (game) {

        /*if (TEMP_pos.x != pos.x || TEMP_pos.y != pos.y) {
            TEMP_pos.x = pos.x;
            TEMP_pos.y = pos.y;
            printf("x: %f y: %f\n", pos.x, pos.y);
        }*/

        ticks = SDL_GetTicks();
        stand = (ticks / 300) % 5;
        run = (ticks / 300) % 4;
        jump = (ticks / 300) % 8;

        SDL_Rect moonPos = { 1200, -245, 763, 770 };
        SDL_Rect background1 = { bg1_pos, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
        SDL_Rect background2 = { bg2_pos, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
        SDL_Rect srcrectStand = { stand * NEO_WIDTH, 0, NEO_WIDTH, NEO_HEIGHT };
        SDL_Rect srcrectRun = { run * NEO_WIDTH, 0, NEO_WIDTH, NEO_HEIGHT };
        SDL_Rect srcrectJump = { jump * NEO_WIDTH, 0, NEO_WIDTH, NEO_HEIGHT };
        SDL_Rect dstrect = { pos.x, pos.y, NEO_WIDTH, NEO_HEIGHT };

        SDL_RenderCopy(renderer, bg1, NULL, &background1);
        SDL_RenderCopy(renderer, bg2, NULL, &background2);
        SDL_RenderCopy(renderer, moon, NULL, &moonPos);

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    game = false;
                    break;
                case SDL_KEYDOWN:
                    walk = true;
                    key = SDL_GetKeyName(event.key.keysym.sym);
                    break;
                case SDL_KEYUP:
                    walk = false;
                    break;
            }
        }

        if(walk == false && !(jump_down_process || jump_process)) {
            SDL_RenderCopy(renderer, neo_stand, &srcrectStand, &dstrect);
        }
        else {
            if(strcmp(key, "Q") == 0) game = false;
            else if(strcmp(key, "A") == 0) { 
                pos.x -= MOVE_STEP;
                runL = true;
                }
            else if(strcmp(key, "D") == 0) { 
                pos.x += MOVE_STEP;
                runR = true;
            }
            else if(strcmp(key, "W") == 0) { 
                if (!jump_down_process)
                    jump_process = true;
            }
            else
                walk = false;
        }
        SDL_Renderer *jump_renderer = mx_jump(renderer, &jump_process, &jump_down_process, &pos, ground, runL, runR);
        if (jump_process || jump_down_process) {
            SDL_RenderCopy(jump_renderer, neo_jumpR, &srcrectJump, &dstrect);
        }
        else if (runL) {
            SDL_RenderCopy(renderer, neo_runL, &srcrectRun, &dstrect);
            runL = false;
        }
        else if (runR) {
            SDL_RenderCopy(renderer, neo_runR, &srcrectRun, &dstrect);
            runR = false;
        }
        

        mx_scroll_bg(&pos, &bg_num, &bg1_pos, &bg2_pos);

        SDL_RenderPresent(renderer);
        SDL_Delay(2);
        SDL_RenderClear(renderer);
    }

    Mix_FreeMusic(backgroundSound);
    SDL_DestroyTexture(bg1);
    SDL_DestroyTexture(bg2);
    SDL_DestroyTexture(moon);
    SDL_DestroyTexture(neo_stand);
    SDL_DestroyTexture(neo_runR);
    SDL_DestroyTexture(neo_runL);
    SDL_DestroyTexture(neo_jumpR);
    SDL_DestroyTexture(neo_jumpL);

}
