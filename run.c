#include "run.h"
#include <stdio.h>
void mouve(struct Ball* ball)
{
//    printf("mouve !\n");
    if (ball->sens == GAUCHE)
    {
        ball->coord.x -= 5;
        ball->coord.y += ball->varY;
    }
    else
    {
        ball->coord.x += 5;
        ball->coord.y += ball->varY;
    }
}

void runAStep(struct Ball* ball, int posYJ1, int posYJ2, struct Score* score)
{
    if(colideRWall(*ball) == 1)
    {
        if (colideRaquette(posYJ1, *ball))
        {
            changeDirection(ball);
            ball->varY = ((ball->coord.y - posYJ1) - 20)/2.3;
            mouve(ball);
        }
        else 
        {
            score->J2++;
            initBall(ball);
        }
    }
    else if(colideRWall(*ball) == 2)
    {
        if (colideRaquette(posYJ2, *ball))
        {
            changeDirection(ball);
            ball->varY = ((ball->coord.y - posYJ2) - 20)/2.3;
            mouve(ball);
        }
        else
        {
            score->J1++;
            initBall(ball);
        }
    }
    else
    {
        if (colideWall(*ball) > 0)
            ball->varY =  - ball->varY;
        mouve(ball);
    }


}
