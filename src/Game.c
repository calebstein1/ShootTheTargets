#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <raylib.h>
#include "Game.h"
#include "InputHandler/InputHandler.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 480
#define TARGET_CHANCE 2000
#define MAX_TARGETS 8
#define PLAYER_MOVEMENT_SPEED 200
#define PLAYER_START_POS_X 320
#define PLAYER_START_POS_Y 240

int main()
{
    srand(time(NULL));
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Shoot The Targets");

    Image playerImage = LoadImage("Resources/crosshairs.png");
    Texture2D playerTexture = LoadTextureFromImage(playerImage);

    Image targetImage = LoadImage("Resources/target.png");
    Texture2D targetTexture = LoadTextureFromImage(targetImage);

    double playerPosX, playerPosY, delta;
    playerPosX = PLAYER_START_POS_X;
    playerPosY = PLAYER_START_POS_Y;

    Target_t targets[MAX_TARGETS];
    int i = 0;

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
            playerPosY += PLAYER_MOVEMENT_SPEED * delta;

        if (rand() % TARGET_CHANCE == 0)
        {
            for (i = 0; i < MAX_TARGETS; i++)
            {
                if (!targets[i].isActive)
                {
                    targets[i].isActive = true;
                    targets[i].posX = rand() % WINDOW_WIDTH;
                    targets[i].posY = rand() % WINDOW_HEIGHT;
                    break;
                }
            }
        }

        BeginDrawing();
            ClearBackground(BLUE);

            for (i = 0; i < MAX_TARGETS; i++)
            {
                if (targets[i].isActive)
                    DrawTexture(targetTexture, targets[i].posX, targets[i].posY, WHITE);
            }
            DrawTexture(playerTexture, playerPosX, playerPosY, WHITE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
