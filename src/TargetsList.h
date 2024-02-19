#ifndef LIST_H
#define LIST_H

struct Target_t
{
    int posX;
    int posY;
};

struct Target_t* AddTarget(struct Target_t *targets, struct Target_t *t, int *numOfTargets);

#endif //LIST_H
