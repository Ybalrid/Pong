#include "score.h"

void clearConsole()
{
    system("clear");
}

void displayScore(struct Score score)
{
    clearConsole();
    printf("Joueur 1 : %d\n", score.J1);
    printf("Joueur 2 : %d\n", score.J2);
}
