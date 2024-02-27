#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

bool MoveLeft();
bool MoveRight();
bool MoveUp();
bool MoveDown();
bool Shoot();
void DoPlayerMovement(int playerSpeed, int* playerPosX, int* playerPosY);

#endif //INPUTHANDLER_H
