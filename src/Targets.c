#include <stdbool.h>
#include <raylib.h>
#include "Targets.h"

void CheckIfTargetShot(int maxTargets, Target_t* targets, int* playerPosX, int* playerPosY, int* score)
{
    int i = 0;
    for (i = 0; i < maxTargets; i++)
    {
        if (targets[i].isActive && targets[i].posX - 45 < *playerPosX && targets[i].posX + 45 > *playerPosX &&
            targets[i].posY - 45 < *playerPosY && targets[i].posY + 45 > *playerPosY)
        {
            targets[i].isActive = false;
            *score += 10;
            break;
        }
    }
    if (i == maxTargets)
        *score -= 1;
}

void SpawnTargetIfSlotAvailable(int maxTargets, Target_t* targets, int targetPosX, int targetPosY, unsigned long targetDespawnTimer)
{
    int i = 0;
    for (i = 0; i < maxTargets; i++)
    {
        if (!targets[i].isActive)
        {
            targets[i].isActive = true;
            targets[i].posX = targetPosX;
            targets[i].posY = targetPosY;
            targets[i].despawnTime = targetDespawnTimer;
            break;
        }
    }
}

void DrawTargets(Texture* targetTexture, int maxTargets, Target_t* targets, unsigned long* frameCounter, int* score)
{
    int i = 0;
    for (i = 0; i < maxTargets; i++)
    {
        if (targets[i].isActive)
        {
            if (*frameCounter > targets[i].despawnTime)
            {
                targets[i].isActive = false;
                *score -= 3;
                continue;
            }
            DrawTexture(*targetTexture, targets[i].posX, targets[i].posY, WHITE);
        }
    }
}

void ClearAllTargets(int maxTargets, Target_t* targets)
{
    int i = 0;
    for (i = 0; i < maxTargets; i++)
    {
        if (targets[i].isActive == true)
            targets[i].isActive = false;
    }
}
