#ifndef SHOOTS_CONSTANTS_H
#define SHOOTS_CONSTANTS_H

// world stuff
#define SHOOTS_FRICTION .8
#define SHOOTS_TILE_SIZE 16

// screen stuff
extern int SHOOTS_SCREEN_WIDTH;
extern int SHOOTS_SCREEN_HEIGHT;

// player stuff
#define SPLAYER_ACCEL 100
#define SPLAYER_MAX_SPEED SPLAYER_ACCEL * 3
#define SPLAYER_SIZE SHOOTS_TILE_SIZE

#define SPLAYER_ANIM_SPEED 10 // the higher -> the slower

#endif
