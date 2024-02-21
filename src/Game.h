#ifndef GAME_H
#define GAME_H

typedef struct Target_t
{
    bool isActive;
    int posX, posY;
    unsigned long despawnFrame;
} Target_t;

#endif //GAME_H
