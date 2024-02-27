#include <stdbool.h>
#include <raylib.h>
#include "InputHandler.h"

bool MoveLeft()
{
    if (IsKeyDown(KEY_A) ||
        IsKeyDown(KEY_LEFT) ||
        IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_LEFT))
        return true;
    return false;
}
bool MoveRight()
{
    if (IsKeyDown(KEY_D) ||
        IsKeyDown(KEY_RIGHT) ||
        IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT))
        return true;
    return false;
}
bool MoveUp()
{
    if (IsKeyDown(KEY_W) ||
        IsKeyDown(KEY_UP) ||
        IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_UP))
        return true;
    return false;
}
bool MoveDown()
{
    if (IsKeyDown(KEY_S) ||
        IsKeyDown(KEY_DOWN) ||
        IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN))
        return true;
    return false;
}
bool Shoot()
{
    if (IsKeyDown(KEY_SPACE))
        return true;
    return false;
}
void DoPlayerMovement(int playerSpeed, int* playerPosX, int* playerPosY)
{
    if (MoveLeft())
        *playerPosX -= playerSpeed;
    if (MoveRight())
        *playerPosX += playerSpeed;
    if (MoveUp())
        *playerPosY -= playerSpeed;
    if (MoveDown())
        *playerPosY += playerSpeed;
}
