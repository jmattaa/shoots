#ifndef SHOOTS_PLAYER_H
#define SHOOTS_PLAYER_H

#include "entity.h"
#include <raylib.h>
#include <stdint.h>

typedef sEntity sPlayer;

typedef struct
{
    Vector2 vel;
} sPlayerData;

sPlayer *sPlayer_Init(Texture2D *tex);
void sPlayer_Update(sPlayer *p, float dt);
void sPlayer_Draw(sPlayer *p);

#define TS SHOOTS_TILE_SIZE

#define SPLAYER_SPRITESHEET_LEFT_SRC                                           \
    (Rectangle) { 0, 0, TS, TS }
#define SPLAYER_SPRITESHEET_LEFT_IDLE1_SRC                                     \
    (Rectangle) { TS, 0, TS, TS }
#define SPLAYER_SPRITESHEET_LEFT_IDLE2_SRC                                     \
    (Rectangle) { TS * 2, 0, TS, TS }
#define SPLAYER_SPRITESHEET_LEFT_IDLE3_SRC                                     \
    (Rectangle) { TS * 3, 0, TS, TS }

#define SPLAYER_SPRITESHEET_RIGHT_SRC                                          \
    (Rectangle) { 0, TS, TS, TS }
#define SPLAYER_SPRITESHEET_RIGHT_IDLE1_SRC                                    \
    (Rectangle) { TS, TS, TS, TS }
#define SPLAYER_SPRITESHEET_RIGHT_IDLE2_SRC                                    \
    (Rectangle) { TS * 2, TS, TS, TS }
#define SPLAYER_SPRITESHEET_RIGHT_IDLE3_SRC                                    \
    (Rectangle) { TS * 3, TS, TS, TS }

#endif
