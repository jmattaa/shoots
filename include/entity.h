#ifndef SHOOTS_ENTITY_H
#define SHOOTS_ENTITY_H

#include <raylib.h>

typedef struct
{
    Vector2 pos;
    Vector2 size;
    Texture2D *tex;

    void *data;
} sEntity;

#define sEntity_Init_SIGN Vector2 pos, Vector2 size, Texture2D *tex
sEntity *sEntity_Init(sEntity_Init_SIGN, void *data);
void sEntity_Draw(sEntity *e);
void sEntity_Free(sEntity *e);

#endif
