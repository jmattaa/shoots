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

#endif
