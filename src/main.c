#include "globals.h"
#include "player.h"
#include <raylib.h>
#include <stddef.h>

int main(int argc, char **argv)
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(SHOOTS_SCREEN_WIDTH, SHOOTS_SCREEN_HEIGHT, "Shoots");
    SetTargetFPS(60);
    SetExitKey(0); // so esc doesn't quit

    sPlayer *p = sPlayer_Init(NULL);

    float dt;
    while (!WindowShouldClose())
    {
        if (IsWindowResized())
        {
            SHOOTS_SCREEN_WIDTH = GetScreenWidth();
            SHOOTS_SCREEN_HEIGHT = GetScreenHeight();
        }

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
