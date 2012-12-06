#ifndef RUN_H
#define RUN_H

#include "ball.h"
#include <SDL.h>

struct Score
{
    int J1;
    int J2;
};

void mouve(struct Ball* ball);
void runAStep(struct Ball* ball, int posYJ1, int posYJ2, struct Score* score);

#endif //RUN_H
