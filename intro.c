#include <raylib.h>
#include "InputHandler/InputHandler.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define PLAYER_MOVEMENT_SPEED 250
#define PLAYER_START_POS_X 320
#define PLAYER_START_POS_Y 240

int main()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Shoot The Targets");

    Image playerImage = LoadImage("Resources/crosshairs.png");
    Texture2D playerTexture = LoadTextureFromImage(playerImage);

    Image targetImage = LoadImage("Resources/target.png");
    Texture2D targetTexture = LoadTextureFromImage(targetImage);

    float playerPosX, playerPosY, delta;
    playerPosX = PLAYER_START_POS_X;
    playerPosY = PLAYER_START_POS_Y;

    while (!WindowShouldClose())
    {
        delta = GetFrameTime();
        if (MoveLeft())
            playerPosX -= PLAYER_MOVEMENT_SPEED * delta;
        if (MoveRight())
            playerPosX += PLAYER_MOVEMENT_SPEED * delta;
        if (MoveUp())
            playerPosY -= PLAYER_MOVEMENT_SPEED * delta;
        if (MoveDown())
            playerPosY += PLAYER_MOVEMENT_SPEED* delta;


        BeginDrawing();
            ClearBackground(BLUE);
            DrawTexture(targetTexture, 120, 120, WHITE);
            DrawTexture(playerTexture, playerPosX, playerPosY, WHITE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
