#include "SpeedUp.h"

SpeedUp::SpeedUp(): Item(){}

void SpeedUp::augmenterVitesse(Joueur* joueur)
{
    joueur->setSpeed(joueur->getSpeed()+1);
}