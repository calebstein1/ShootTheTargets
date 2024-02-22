#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <raylib.h>
#include "Game.h"
#include "InputHandler/InputHandler.h"

// MODIFY THESE
#define FRAMERATE 60
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 480
#define PLAYER_START_POS_X 320
#define PLAYER_START_POS_Y 240
#define TARGET_SPAWN_CHANCE_SECONDS 2
#define PLAYER_MOVEMENT_PIXELS_AT_60FPS 3
#define TARGET_DESPAWN_SECONDS 7
#define MAX_TARGETS 4

// DON'T MODIFY THESE
#define PLAYER_MOVEMENT_SPEED ((60 * PLAYER_MOVEMENT_PIXELS_AT_60FPS) / FRAMERATE)
#define SHOOT_COOLDOWN_TIMER (FRAMERATE >> 2)
#define TARGET_SPAWN_CHANCE_FREQ (FRAMERATE * TARGET_SPAWN_CHANCE_SECONDS)
#define TARGET_DESPAWN_TIMER (FRAMERATE * TARGET_DESPAWN_SECONDS)

int main()
{
    SetTargetFPS(FRAMERATE);

    srand(time(NULL));
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Shoot The Targets");

    Image playerImage = LoadImage("Resources/crosshairs.png");
    Texture2D playerTexture = LoadTextureFromImage(playerImage);

    Image targetImage = LoadImage("Resources/target.png");
    Texture2D targetTexture = LoadTextureFromImage(targetImage);

    bool playerCanShoot = true;
    int i = 0, playerPosX = PLAYER_START_POS_X, playerPosY = PLAYER_START_POS_Y, nextTargetSpawnChance = 0;
    unsigned long frameCounter = 0, playerCooldownTimer;

    Target_t targets[MAX_TARGETS];

    while (!WindowShouldClose())
    {
        frameCounter++;

        if (frameCounter > playerCooldownTimer && !playerCanShoot)
            playerCanShoot = true;

        if (MoveLeft())
            playerPosX -= PLAYER_MOVEMENT_SPEED;
        if (MoveRight())
            playerPosX += PLAYER_MOVEMENT_SPEED;
        if (MoveUp())
            playerPosY -= PLAYER_MOVEMENT_SPEED;
        if (MoveDown())
            playerPosY += PLAYER_MOVEMENT_SPEED;
        if (Shoot() && playerCanShoot)
        {
            playerCanShoot = false;
            TraceLog(LOG_INFO, "Shot");
            playerCooldownTimer = frameCounter + SHOOT_COOLDOWN_TIMER;
        }

        if (frameCounter > nextTargetSpawnChance && rand() % 2 == 0)
        {
            nextTargetSpawnChance += TARGET_SPAWN_CHANCE_FREQ;
            for (i = 0; i < MAX_TARGETS; i++)
            {
                if (!targets[i].isActive)
                {
                    targets[i].isActive = true;
                    targets[i].posX = rand() % WINDOW_WIDTH;
                    targets[i].posY = rand() % WINDOW_HEIGHT;
                    targets[i].despawnTime = frameCounter + TARGET_DESPAWN_TIMER;
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
                    if (frameCounter > targets[i].despawnTime)
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
