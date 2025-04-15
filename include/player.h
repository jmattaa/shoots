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
} sPlayer_AnimType;

static const uint8_t SPLAYER_ANIM_FC[] = {
    4, // SPLAYER_ANIM_IDLE
};

typedef struct
{
    Vector2 vel;
    uint8_t lookDir : 1; // 0 = left, 1 = right
    uint8_t animFrame;
    sPlayer_AnimType currentAnim;
} sPlayerData;

sPlayer *sPlayer_Init(Texture2D *tex);
void sPlayer_Update(sPlayer *p, float dt);
void sPlayer_Draw(sPlayer *p, int *fc);

#define TS SHOOTS_TILE_SIZE

#define SPLAYER_SPRITESHEET_LEFT_SRC                                           \
    (Rectangle) { 0, 0, TS, TS }
#define SPLAYER_SPRITESHEET_RIGHT_SRC                                          \
    (Rectangle) { 0, TS, TS, TS }
#endif
