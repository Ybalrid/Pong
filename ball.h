#ifndef BALL_H
#define BALL_H
#include <SDL.h>
enum {GAUCHE, DROITE}; // definition des sens


struct Ball
{
    SDL_Rect coord; //coordonées de la balle
    int sens; //sens de la balle 
    int varY; //variation de hauteur de la balle
};

void initBall(struct Ball* ball);

int colideWall(struct Ball ball);//return 1 si colision avec les murs en haut et en bas
int colideRWall(struct Ball ball);//return numeroJoueur si colision avec les murs dérière les joueurs

int colideRaquette(int posY, struct Ball ball);//si colision avec la raquette

void changeDirection(struct Ball* ball); //change le sens de la balle
//void invertVarY(struct Ball* ball)
void calculateVarY(int posY, struct Ball* ball);
#endif //BALL_H
