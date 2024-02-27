#ifndef TARGETS_H
#define TARGETS_H

typedef struct Target_t
{
    bool isActive;
    int posX, posY;
    unsigned long despawnTime;
} Target_t;

void CheckIfTargetShot(int maxTargets, Target_t* targets, int* playerPosX, int* playerPosY, int* score);
void SpawnTargetIfSlotAvailable(int maxTargets, Target_t* targets, int targetPosX, int targetPosY, unsigned long targetDespawnTimer);
void DrawTargets(Texture* targetTexture, int maxTargets, Target_t* targets, unsigned long* frameCounter, int* score);
void ClearAllTargets(int maxTargets, Target_t* targets);

#endif //TARGETS_H
