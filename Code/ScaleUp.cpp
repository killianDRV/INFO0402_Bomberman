#include "ScaleUp.h"

ScaleUp::ScaleUp(): Item(){}

void ScaleUp::augmenterPortee(Joueur* joueur)
{
    int i;
    Bombe* bombe = joueur->getBombe();

    for(i=0; i<joueur->getNbBombMax(); i++)
    {
        bombe[i].setPortee(bombe[i].getPortee()+1);
    }
}