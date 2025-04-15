#include "player.h"
#include "globals.h"
#include <raylib.h>
#include <raymath.h>
#include <stdio.h>
#include <stdlib.h>

sPlayer *sPlayer_Init(Texture2D *tex)
{
    sPlayerData *pdata = malloc(sizeof(sPlayerData));
    pdata->vel = Vector2Zero();

    sPlayer *p = sEntity_Init(
        (Vector2){SHOOTS_SCREEN_WIDTH / 2.0f, SHOOTS_SCREEN_HEIGHT / 2.0f},
        (Vector2){SPLAYER_SIZE, SPLAYER_SIZE}, tex, pdata);
    return p;
}

void sPlayer_Update(sPlayer *p, float dt)
{
    sPlayerData *pdata = (sPlayerData *)p->data;

    Vector2 inpDir = {(float)(IsKeyDown(KEY_D) - IsKeyDown(KEY_A)),
                      (float)(IsKeyDown(KEY_S) - IsKeyDown(KEY_W))};

    // so we don get no diagonal vroooom
    if (Vector2Length(inpDir) > 0)
        inpDir = Vector2Normalize(inpDir);
    pdata->vel = Vector2Add(pdata->vel, Vector2Scale(inpDir, SPLAYER_ACCEL));

    if (Vector2Length(pdata->vel) > SPLAYER_MAX_SPEED)
        pdata->vel =
            Vector2Scale(Vector2Normalize(pdata->vel), SPLAYER_MAX_SPEED);

    pdata->vel = Vector2Add(pdata->vel, inpDir);

    p->pos = Vector2Add(p->pos, Vector2Scale(pdata->vel, dt));

    pdata->vel = Vector2Scale(pdata->vel, SHOOTS_FRICTION);
}

void sPlayer_Draw(sPlayer *p)
{
    sEntity_Draw(p, SPLAYER_SPRITESHEET_LEFT_SRC,
                 (Rectangle){p->pos.x, p->pos.y, p->size.x, p->size.y});
}
