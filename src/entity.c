#include "entity.h"
#include <raylib.h>
#include <stdlib.h>

sEntity *sEntity_Init(Vector2 pos, Vector2 size, Texture2D *tex, void *data)
{
    sEntity *e = malloc(sizeof(sEntity));
    e->pos = pos;
    e->size = size;
    e->tex = tex;
    e->data = data;
    return e;
}

void sEntity_Draw(sEntity *e)
{
    e->tex != NULL ? DrawTextureV(*e->tex, e->pos, WHITE)
                   : DrawRectangleV(e->pos, e->size, BLACK);
}

void sEntity_Free(sEntity *e)
{
    if (e->tex != NULL)
        UnloadTexture(*e->tex);
    if (e->data != NULL)
        free(e->data);
    free(e);
}
