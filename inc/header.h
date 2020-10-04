#ifndef ENDGAME_H
#define ENDGAME_H

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define NEO_WIDTH 280
#define NEO_HEIGHT 230
#define MOVE_STEP 0.7
#define JUMP_STEP 2
#define JUMP_HEIGHT 200

// SDL2 Frameworks
#include <SDL2/SDL.h>
#include "SDL2_image/SDL_image.h"
#include "SDL2_mixer/SDL_mixer.h"
#include "SDL2_ttf/SDL_ttf.h"

// Sytem Libriaries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>



typedef struct s_position {
    float x;
    float y;
}              t_position;

void mx_start(SDL_Renderer *renderer);
const char *mx_pickmusic();
void mx_scroll_bg(t_position *pos, int *bg_num, float *bg1_pos, float *bg2_pos);


// typedef struct s_bullet {
//     t_position pos;
//     int health;
//     int type;
//     int size;
//     struct s_bullet *next;
//     struct s_bullet *prev;
// }              t_bullet;

// typedef struct s_weapon {
//     double firerate;
//     int damage;
//     int bullet_speed;
//     int type;
//     int bullets_count;
//     t_bullet *bullets_live;
// }               t_weapon;

// typedef struct s_player {
//     t_position pos;
//     double tower_angle;
//     int caterpillar;
//     unsigned int caterpillar_time;
//     int max_health;
//     int cur_health;
//     int size;
//     double speed;
//     int exp;
//     bool death;
//     t_weapon *cur_weapon;
// }               t_player;

// typedef struct s_enemy {
//     t_position pos;
//     int max_health;
//     int cur_health;
//     double speed;
//     int damage;
//     int attack_time;
//     unsigned int attack_speed;
//     int size;
//     int type;
//     unsigned int step_time;
//     bool dead;
//     enum e_textures sprites_deskr[11];
//     uint cur_sprite;
//     struct s_enemy *next;
//     struct s_enemy *prev;
// }               t_enemy;

// typedef struct s_corpse {
//     t_position pos;
//     int type;
//     int timer;
//     int size;
//     struct s_corpse *next;
//     struct s_corpse *prev;
// }               t_corpse;
// typedef struct s_ingameSound {
//     Mix_Chunk **track;
//     int *channel;
//     bool *pause;
// }              t_ingameSound;
// typedef struct s_gamestate {
//     unsigned int last_time;
//     enum e_scenestate scene;
//     bool input_name;
//     t_player *player;
//     t_enemy *enemies;
//     int kill_count;
//     unsigned int enemies_spawn_time;
//     unsigned int wave_number;
//     t_corpse *corpses;
//     t_ingameSound *sounds;
//     SDL_Texture **textures;
//     Mix_Music *backgroundSound;

// }               t_gamestate;

#endif
