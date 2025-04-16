#include "globals.h"
#include "player.h"
#include <raylib.h>
#include <stddef.h>

int main(int argc, char **argv)
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(SHOOTS_SCREEN_WIDTH, SHOOTS_SCREEN_HEIGHT, "Shoots");
    SetExitKey(0); // so esc doesn't quit

    Texture2D background = LoadTexture("res/background.png");
    sEntity *bg = sEntity_Init(
        (Vector2){SHOOTS_SCREEN_WIDTH / 2.0f, SHOOTS_SCREEN_HEIGHT / 2.0f},
        (Vector2){SHOOTS_SCREEN_WIDTH, SHOOTS_SCREEN_HEIGHT}, &background,
        NULL);

    // sEntity_Free will unload the texture
    Texture2D playerTex = LoadTexture("res/playerSheet.png");
    sPlayer *p = sPlayer_Init(&playerTex);

    Camera2D cam = {
        .target = (Vector2){p->pos.x, p->pos.y},
        .offset =
            (Vector2){SHOOTS_SCREEN_WIDTH / 2.0f, SHOOTS_SCREEN_HEIGHT / 2.0f},
        .rotation = 0.0f,
        .zoom = 2.0f, // 2x zoom so 16x16 will look like 32x32
    };

    SetTargetFPS(60);
    int framesCount = 0;

    float dt;
    while (!WindowShouldClose())
    {
        framesCount++;

        if (IsWindowResized())
        {
            SHOOTS_SCREEN_WIDTH = GetScreenWidth();
            SHOOTS_SCREEN_HEIGHT = GetScreenHeight();
            cam.offset = (Vector2){SHOOTS_SCREEN_WIDTH / 2.0f,
                                   SHOOTS_SCREEN_HEIGHT / 2.0f};
        }

        dt = GetFrameTime();

        BeginDrawing();
        BeginMode2D(cam);
        ClearBackground(RAYWHITE);

        cam.target = (Vector2){p->pos.x, p->pos.y};

        sPlayer_Update(p, dt);

        sEntity_DrawFull(bg);
        sPlayer_Draw(p, &framesCount);

        EndMode2D();
        EndDrawing();
    }

    sEntity_Free(p);
    sEntity_Free(bg);

    CloseWindow();

    return 0;
}
