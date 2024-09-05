#include <raylib.h>
#include "game.h"

double lastUpdateTime = 0;
bool intervalCompleted(double ivl)
{
    double curTime = GetTime();
    if (curTime - lastUpdateTime >= ivl)
    {
        lastUpdateTime = curTime;
        return true;
    }
    return false;
}

int main()
{
    Color bgCol = {0, 0, 103, 255};
    InitWindow(1000, 950, "TetrisGameWindow"); // Window size 600px, 900px  , 50px offset
    SetTargetFPS(60);
    Font font = LoadFontEx("Atop-R99O3.ttf", 64, 0, 0);
    Game game = Game();

    while (WindowShouldClose() == false)
    {
        game.handleInput();
        if (intervalCompleted(0.1))
        {
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(bgCol);
        game.Draw();
        DrawTextEx(font, "SCORE", {750, 100}, 38, 2, WHITE);
        DrawTextEx(font, "NEXT", {750, 400}, 38, 2, WHITE);
        if (game.gameOver)
            DrawTextEx(font, "!! GAME OVER !!", {680, 800}, 38, 2, WHITE);
        DrawRectangleRounded({700, 200, 200, 60}, 0.3, 6, GRAY);
        DrawRectangleRounded({700, 500, 200, 250}, 0.3, 6, GRAY);
        EndDrawing();
    }

    CloseWindow();
}