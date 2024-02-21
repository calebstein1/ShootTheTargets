#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <raylib.h>
#include "Game.h"
#include "InputHandler/InputHandler.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 480
#define TARGET_SPAWN_CHANCE_FREQ 2
#define TARGET_DESPAWN_SECONDS 7
#define MAX_TARGETS 4
#define PLAYER_MOVEMENT_SPEED 200
#define PLAYER_START_POS_X 320
#define PLAYER_START_POS_Y 240
#define SHOOT_COOLDOWN_TIME 0.25

int main()
{
    srand(time(NULL));
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Shoot The Targets");

    Image playerImage = LoadImage("Resources/crosshairs.png");
    Texture2D playerTexture = LoadTextureFromImage(playerImage);

    Image targetImage = LoadImage("Resources/target.png");
    Texture2D targetTexture = LoadTextureFromImage(targetImage);

    bool playerCanShoot = true;
    double playerPosX, playerPosY, playerCooldownTimer = 0, delta, gameTimer = 0, nextTargetSpawnChance = 0;
    playerPosX = PLAYER_START_POS_X;
    playerPosY = PLAYER_START_POS_Y;

    Target_t targets[MAX_TARGETS];
    int i = 0;

    while (!WindowShouldClose())
    {
        delta = GetFrameTime();
        gameTimer = GetTime();

        if (!playerCanShoot && playerCooldownTimer < gameTimer)
            playerCanShoot = true;

        if (MoveLeft())
            playerPosX -= PLAYER_MOVEMENT_SPEED * delta;
        if (MoveRight())
            playerPosX += PLAYER_MOVEMENT_SPEED * delta;
        if (MoveUp())
            playerPosY -= PLAYER_MOVEMENT_SPEED * delta;
        if (MoveDown())
            playerPosY += PLAYER_MOVEMENT_SPEED * delta;
        if (Shoot() && playerCanShoot)
        {
            playerCanShoot = false;
            TraceLog(LOG_INFO, "Shot");
            playerCooldownTimer = gameTimer + SHOOT_COOLDOWN_TIME;
        }

        if (gameTimer > nextTargetSpawnChance && rand() % 2 == 0)
        {
            nextTargetSpawnChance += TARGET_SPAWN_CHANCE_FREQ;
            for (i = 0; i < MAX_TARGETS; i++)
            {
                if (!targets[i].isActive)
                {
                    targets[i].isActive = true;
                    targets[i].posX = rand() % WINDOW_WIDTH;
                    targets[i].posY = rand() % WINDOW_HEIGHT;
                    targets[i].despawnTime = gameTimer + TARGET_DESPAWN_SECONDS;
                    break;
                }
            }
        }

        BeginDrawing();
            ClearBackground(BLUE);

            for (i = 0; i < MAX_TARGETS; i++)
            {
                if (targets[i].isActive)
                {
                    if (targets[i].despawnTime < gameTimer)
                    {
                        targets[i].isActive = false;
                        continue;
                    }
                    DrawTexture(targetTexture, targets[i].posX, targets[i].posY, WHITE);
                }
            }
            DrawTexture(playerTexture, playerPosX, playerPosY, WHITE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
