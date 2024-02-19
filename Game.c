#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "TargetsList.h"
#include "InputHandler/InputHandler.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define TARGET_CHANCE 2000
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

    float playerPosX, playerPosY, delta;
    playerPosX = PLAYER_START_POS_X;
    playerPosY = PLAYER_START_POS_Y;

    struct Target_t *targets = malloc(0);
    int numOfTargets = 0;

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

        if (rand() % TARGET_CHANCE == 0)
        {
            struct Target_t *newTarget = malloc(sizeof(struct Target_t));
            if (newTarget == NULL)
            {
                perror("malloc");
                return -1;
            }
            newTarget->posX = rand() % WINDOW_WIDTH;
            newTarget->posY = rand() % WINDOW_HEIGHT;
            numOfTargets++;
            targets = AddTarget(targets, newTarget, &numOfTargets);
        }

        BeginDrawing();
            ClearBackground(BLUE);

            for (int i = 0; i < numOfTargets; i++)
            {
                DrawTexture(targetTexture, targets[i].posX, targets[i].posY, WHITE);
            }
            DrawTexture(playerTexture, playerPosX, playerPosY, WHITE);
        EndDrawing();
    }

    free(targets);
    CloseWindow();

    return 0;
}
