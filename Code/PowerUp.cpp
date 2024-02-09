#include "PowerUp.h"

PowerUp::PowerUp(): Item(){}

void PowerUp::augmenterPuissance(Joueur* joueur)
{
    int i;
    Bombe* bombe = joueur->getBombe();

    for(i=0; i<joueur->getNbBombMax(); i++)
    {
        bombe[i].setPuissance(bombe[i].getPuissance()+1);
    }
}