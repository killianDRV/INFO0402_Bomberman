#include "MoreLife.h"

MoreLife::MoreLife(): Item(){}

void MoreLife::ajouterVie(Joueur* joueur)
{
    joueur->setHP(joueur->getHP()+1);
}