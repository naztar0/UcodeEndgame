#include "header.h"

void mx_scroll_bg(t_position *pos, int *bg_num, float *bg1_pos, float *bg2_pos) {
    if (pos->x >= 1250) {
        pos->x = 1249;
        if (*bg_num == 1) {
            if (*bg2_pos == -WINDOW_WIDTH)
                    *bg2_pos = WINDOW_WIDTH - 1;
            if (*bg1_pos == -WINDOW_WIDTH + 1) {
                *bg_num = 2;
                *bg1_pos = WINDOW_WIDTH;
            }
            *bg1_pos = *bg1_pos - 1;
            *bg2_pos = *bg2_pos - 1;
        }
        else {
            if (*bg1_pos == -WINDOW_WIDTH)
                    *bg1_pos = WINDOW_WIDTH - 1;
            if (*bg2_pos == -WINDOW_WIDTH + 1) {
                *bg_num = 1;
                *bg2_pos = WINDOW_WIDTH;
            }
            *bg1_pos = *bg1_pos - 1;
            *bg2_pos = *bg2_pos - 1;
        }
    }
    else if (pos->x <= 220) {
        pos->x = 221;
        if (*bg_num == 1) {
            if (*bg2_pos == WINDOW_WIDTH)
                *bg2_pos = -WINDOW_WIDTH + 1;
            if (*bg1_pos == WINDOW_WIDTH - 1) {
                *bg_num = 2;
                *bg1_pos = -WINDOW_WIDTH;
            }
            *bg1_pos = *bg1_pos + 1;
            *bg2_pos = *bg2_pos + 1;
        }
        else {
            if (*bg1_pos == WINDOW_WIDTH)
                *bg1_pos = -WINDOW_WIDTH + 1;
            if (*bg2_pos == WINDOW_WIDTH - 1) {
                *bg_num = 1;
                *bg2_pos = -WINDOW_WIDTH;
            }
            *bg1_pos = *bg1_pos + 1;
            *bg2_pos = *bg2_pos + 1;
        }
    }
}
