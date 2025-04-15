#include "globals.h"
#include "player.h"
#include <raylib.h>
#include <stddef.h>

int main(int argc, char **argv)
{
    InitWindow(SHOOTS_SCREEN_WIDTH, SHOOTS_SCREEN_HEIGHT, "Shoots");
    SetTargetFPS(60);

    sPlayer *p = sPlayer_Init(NULL);

    float dt;
    while (!WindowShouldClose())
    {
        dt = GetFrameTime();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        sPlayer_Update(p, dt);

        sEntity_Draw(p);

        EndDrawing();
    }

    sEntity_Free(p);

    CloseWindow();

    return 0;
}
