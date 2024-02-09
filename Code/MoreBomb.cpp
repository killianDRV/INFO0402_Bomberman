#include "MoreBomb.h"

MoreBomb::MoreBomb(): Item(){}

void MoreBomb::ajouterBombe(Joueur* joueur)
{
    Bombe* bombe;
    Bombe* bombeTmp = joueur->getBombe();
    
    joueur->setNbBombMax(joueur->getNbBombMax()+1);
    joueur->setNbBombRestante(joueur->getNbBombRestante()+1);

    
    joueur->setBombe(new Bombe[joueur->getNbBombMax()]);
    bombe = joueur->getBombe();
    for(int i=0; i<joueur->getNbBombMax()-1; i++)
    {
        bombe[i] = bombeTmp[i];
    }
   
    bombe[joueur->getNbBombMax()-1].setPuissance(bombe[0].getPuissance());
    bombe[joueur->getNbBombMax()-1].setPortee(bombe[0].getPortee());
}