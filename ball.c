#include "ball.h"
#include <stdio.h>

int colideWall(struct Ball ball)//return 1 si haut, 2 si bas, 0 si rien
{
    if (ball.coord.y <= 15)
        return 1;
    if (ball.coord.y >= 600 - 15)
        return 2;
    return 0;
}
int colideRWall(struct Ball ball)//return numeroJoueur si colision avec les murs dérière les joueurs
{
    if (ball.coord.x <= 20)
        return 1;
    if (ball.coord.x >= 800 - 30)
        return 2;
    return 0;
}

int colideRaquette(int posY, struct Ball ball)//si colision avec la raquette
{
    if (colideRWall > 0)
    {
        if (ball.coord.y >= posY -10 && ball.coord.y <= posY + 30)
            return 1;
    }
    return 0;
}

void claculateVarY(int posY, struct Ball* ball)
{
//    ball->varY = ((ball->coord.y - posY) - 20)/2.3;
}
void changeDirection(struct Ball* ball) //change le sens de la balle
{
    printf("sens changé\n");
    if (ball->sens == GAUCHE)
        ball->sens = DROITE;
    else 
        ball->sens = GAUCHE;
}

void initBall(struct Ball* ball)
{
    ball->coord.x = (800/2) - (10/2);
    ball->coord.y = (600/2) - (10/2);
}
