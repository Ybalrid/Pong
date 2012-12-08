#include <stdio.h>
#include <SDL.h>

#include "ball.h"
#include "run.h"


int main(int argc, char* argv[])
{
    
    int gameRun = 1; //tant qu'est égal à 1, le jeu tourne
    struct Ball ball; //balle
    struct Score score;
    score.J1 = 0;
    score.J2 = 0; 


    SDL_Event event; //permet de récupérer les evenemeents
    SDL_Init(SDL_INIT_VIDEO); //on initialise la SDL en chargeant le module vidéo
    SDL_Surface *screen  = NULL; //on cree un pointeur pour la surface de l'écran
    
    SDL_EnableKeyRepeat(10, 10);    
    SDL_Rect posJ1, posJ2;
    
    posJ1.x = 10;
    posJ1.y = (600/2) - (40/2);
    
    posJ2.x = 800 - 20;
    posJ2.y = posJ1.y; 

    ball.coord.x = (800/2) - (10/2);
    ball.coord.y = (600/2) - (10/2);
    ball.sens = GAUCHE;
    ball.varY = 7; //angle défini par la variation de hauteur (coef directeur de la droite)

        /* Parametres :
         *      largeur 800
         *      hauteur 600
         *      profondeur de couleur 24bit
         *      SDL_HWSURFACE -> placer dans la mémoire de la carte graphique
         *      SDL_DOUBLEBUF -> activer le double buffering
         *          (pour éviter les clignotemment d'écran au refresh)
         */
    screen = SDL_SetVideoMode(800, 600, 24, SDL_HWSURFACE | SDL_DOUBLEBUF); //on initialise ce pointeur

    SDL_WM_SetCaption("PONG", NULL); //titre de la fenetre à donner au WM

    SDL_Surface *raquette = NULL;
    SDL_Surface *surfaceBall = NULL;

    raquette = SDL_CreateRGBSurface(SDL_HWSURFACE, 10, 40, 24, 0, 0, 0, 0);
    surfaceBall = SDL_CreateRGBSurface(SDL_HWSURFACE, 10, 10, 24, 0, 0, 0, 0);
    

    SDL_FillRect(raquette, NULL, SDL_MapRGB(screen->format, 255,255,255));
    SDL_FillRect(surfaceBall, NULL, SDL_MapRGB(screen->format, 255,255,255));

    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0,0,0)); //on peint en noir
    const int speed = 3;
    
    
    int J1up, J1down, J2up, J2down;
    J1up = 0;
    J1down = 0;
    J2up = 0;
    J2down = 0;
   

    int now = SDL_GetTicks();
    int lastTime = now;


    while(gameRun)//boucle du jeu

    {
        SDL_PollEvent(&event);

        switch(event.type)
        {
            case SDL_QUIT:
                gameRun = 0;
                break;
            case SDL_KEYDOWN://touche clavier enfoncée
                switch(event.key.keysym.sym)
                {
                    case SDLK_z://z
                        J1up = 1;
                        break;
                    case SDLK_s://s
                        J1down = 1;
                        break;
                    case SDLK_UP://fleche du haut
                        J2up = 1;
                        break;
                    case SDLK_DOWN://fleche du bas
                        J2down = 1;
                        break;
                }

                break;

            case SDL_KEYUP:
                switch(event.key.keysym.sym)
                {
                    case SDLK_z://z
                        J1up = 0;
                        break;
                    case SDLK_s://s
                        J1down = 0;
                        break;
                    case SDLK_UP://fleche du haut
                        J2up = 0;
                        break;
                    case SDLK_DOWN://fleche du bas
                        J2down = 0;
                        break;
                }

                break;
        }

        if (J1up)
        {

            if (posJ1.y - speed< 0)
                posJ1.y = 0;
            else
                posJ1.y -= speed;
        }

        if (J1down)
        {

            if (posJ1.y + speed > 600 - 40)
                posJ1.y = 600 - 40;
            else
                posJ1.y += speed;
        }
        
        
        if (J2up)
        {

            if (posJ2.y - speed< 0)
                posJ2.y = 0;
            else
                posJ2.y -= speed;
        }

        if (J2down)
        {

            if (posJ2.y + speed > 600 - 40)
                posJ2.y = 600 - 40;
            else
                posJ2.y += speed;
        }
        
        now = SDL_GetTicks();
        if (now - lastTime > 30)
        {
            runAStep(&ball, posJ1.y, posJ2.y, &score);
            lastTime = now;
        }
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0,0,0)); //on peint en noir

        SDL_BlitSurface(raquette, NULL, screen, &posJ1);
        SDL_BlitSurface(raquette, NULL, screen, &posJ2);

        SDL_BlitSurface(surfaceBall, NULL, screen, &ball.coord);

        SDL_Flip(screen);//refresh de l'écran
//        SDL_Delay(20); // on attend 40 ms; 1000/40 ~= 25fps
    }

    SDL_Quit();
    return 0;
}
