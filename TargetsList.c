#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TargetsList.h"

struct Target_t* AddTarget(struct Target_t *targets, struct Target_t *t, int *numOfTargets)
{
    targets = realloc(targets, sizeof(struct Target_t) * *numOfTargets);
    if (targets == NULL)
    {
        perror("realloc");
        exit(-1);
    }
    targets[*numOfTargets - 1] = *t;

    return targets;
}