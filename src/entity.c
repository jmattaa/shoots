#include "entity.h"
#include "logger.h"
#include <raylib.h>
#include <stdlib.h>

sEntity *sEntity_Init(Vector2 pos, Vector2 size, Texture *tex, void *data)
{
    sEntity *e = malloc(sizeof(sEntity));
    e->pos = pos;
    e->size = size;
    e->tex = tex;
    e->data = data;
    return e;
}

void sEntity_DrawFull(sEntity *e)
{
    e->tex != NULL ? DrawTextureV(*e->tex, e->pos, WHITE)
                   : DrawRectangleV(e->pos, e->size, BLACK);
}

void sEntity_Draw(sEntity *e, Rectangle src, Rectangle dest)
{
    if (e->tex == NULL)
        sLogger_fatal(1, "attempting to draw entity with no texture\n"
                         "use sEntity_DrawFull instead");

    DrawTexturePro(*e->tex, src, dest, (Vector2){0, 0}, 0, WHITE);
}

void sEntity_Free(sEntity *e)
{
    if (e->tex != NULL)
        UnloadTexture(*e->tex);
    if (e->data != NULL)
        free(e->data);
    free(e);
}
