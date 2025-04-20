#ifndef SHOOTS_PLAYER_H
#define SHOOTS_PLAYER_H

#include "entity.h"
#include "globals.h"
#include <raylib.h>
#include <stdint.h>

typedef sEntity sPlayer;

typedef enum
{
    SPLAYER_ANIM_IDLE,
    SPLAYER_ANIM_RUN
} sPlayer_AnimType;

typedef struct
{
    uint8_t fc;
    uint8_t speed; // higher -> slower
} sPlayerAnimInfo;

static const sPlayerAnimInfo sPlayerAnims[] = {
    [SPLAYER_ANIM_IDLE] = {1, 0},
    [SPLAYER_ANIM_RUN] = {6, SPLAYER_ACCEL / 15},
};

typedef struct
{
    Vector2 vel;
    Vector2 lookDir;
    uint8_t animFrame;
    sPlayer_AnimType currentAnim;
} sPlayerData;

sPlayer *sPlayer_Init(Texture2D *tex);
void sPlayer_Update(sPlayer *p, float dt);
void sPlayer_Draw(sPlayer *p, int *fc);

#define TS SHOOTS_TILE_SIZE

#define SPLAYER_SPRITESHEET_DOWN_SRC                                           \
    (Rectangle) { 0, 0, TS, TS }
#define SPLAYER_SPRITESHEET_LEFT_SRC                                           \
    (Rectangle) { 0, TS, TS, TS }
#define SPLAYER_SPRITESHEET_RIGHT_SRC                                          \
    (Rectangle) { 0, TS * 2, TS, TS }
#define SPLAYER_SPRITESHEET_UP_SRC                                             \
    (Rectangle) { 0, TS * 3, TS, TS }

#define SPLAYER_SPRITESHEET_DOWN_RUN1_SRC                                      \
    (Rectangle) { TS *sPlayerAnims[SPLAYER_ANIM_IDLE].fc, 0, TS, TS }
#define SPLAYER_SPRITESHEET_LEFT_RUN1_SRC                                      \
    (Rectangle) { TS *sPlayerAnims[SPLAYER_ANIM_IDLE].fc, TS, TS, TS }
#define SPLAYER_SPRITESHEET_RIGHT_RUN1_SRC                                     \
    (Rectangle) { TS *sPlayerAnims[SPLAYER_ANIM_IDLE].fc, TS * 2, TS, TS }
#define SPLAYER_SPRITESHEET_UP_RUN1_SRC                                        \
    (Rectangle) { TS *sPlayerAnims[SPLAYER_ANIM_IDLE].fc, TS * 3, TS, TS }

#endif
