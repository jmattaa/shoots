#include "player.h"
#include "globals.h"
#include <raylib.h>
#include <raymath.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    SPLAYER_DIR_UP = 0,
    SPLAYER_DIR_LEFT = 1,
    SPLAYER_DIR_RIGHT = 2
} sPDirection;

static const Rectangle spriteTable[2][3] = {
    // IDLE animation
    {
        SPLAYER_SPRITESHEET_UP_SRC,   // up
        SPLAYER_SPRITESHEET_LEFT_SRC, // left
        SPLAYER_SPRITESHEET_RIGHT_SRC // right
    },
    // RUN animation
    {
        SPLAYER_SPRITESHEET_UP_RUN1_SRC,   // up
        SPLAYER_SPRITESHEET_LEFT_RUN1_SRC, // left
        SPLAYER_SPRITESHEET_RIGHT_RUN1_SRC // right
    }};

sPlayer *sPlayer_Init(Texture2D *tex)
{
    sPlayerData *pdata = malloc(sizeof(sPlayerData));
    pdata->vel = Vector2Zero();
    pdata->animFrame = 0;
    pdata->currentAnim = SPLAYER_ANIM_IDLE;
    pdata->dirIdx = SPLAYER_DIR_LEFT;

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
    inpDir = Vector2Normalize(inpDir);

    pdata->vel = Vector2Add(pdata->vel, Vector2Scale(inpDir, SPLAYER_ACCEL));

    if (Vector2Length(pdata->vel) > SPLAYER_MAX_SPEED)
        pdata->vel =
            Vector2Scale(Vector2Normalize(pdata->vel), SPLAYER_MAX_SPEED);

    if (Vector2Length(inpDir) > 0)
    {
        pdata->dirIdx =
            (fabsf(inpDir.x) > fabsf(inpDir.y))
                ? ((inpDir.x < 0) ? SPLAYER_DIR_LEFT : SPLAYER_DIR_RIGHT)
            : (inpDir.y < 0)                    ? SPLAYER_DIR_UP
            : (pdata->dirIdx == SPLAYER_DIR_UP) ? SPLAYER_DIR_RIGHT
                                                : pdata->dirIdx;

        pdata->currentAnim = SPLAYER_ANIM_RUN;
    }
    else
        pdata->currentAnim = SPLAYER_ANIM_IDLE;

    p->pos = Vector2Add(p->pos, Vector2Scale(pdata->vel, dt));
    pdata->vel = Vector2Scale(pdata->vel, SHOOTS_FRICTION);
}

void sPlayer_Draw(sPlayer *p, int *fc)
{
    sPlayerData *pdata = (sPlayerData *)p->data;

    Rectangle spriteSrc = spriteTable[pdata->currentAnim][pdata->dirIdx];

    if (*fc % sPlayerAnims[pdata->currentAnim].speed == 0)
    {
        *fc = 0;
        pdata->animFrame =
            (pdata->animFrame + 1) % sPlayerAnims[pdata->currentAnim].fc;
    }

    spriteSrc.x += pdata->animFrame * SPLAYER_SIZE;

    sEntity_Draw(p, spriteSrc,
                 (Rectangle){p->pos.x, p->pos.y, p->size.x, p->size.y});
}
