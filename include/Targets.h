#ifndef TARGETS_H
#define TARGETS_H

#include "Game.h"

void CheckIfTargetShot(int maxTargets, Target_t* targets, int* playerPosX, int* playerPosY, int* score);
void SpawnTargetIfSlotAvailable(int maxTargets, Target_t* targets, int targetPosX, int targetPosY, unsigned long targetDespawnTimer);
void DrawTargets(Texture* targetTexture, int maxTargets, Target_t* targets, unsigned long* frameCounter, int* score);

#endif //TARGETS_H
