#include "Arrow.h"
#include <iostream>

Arrow::Arrow(int degat, int position, char direction, bool touche): degat(degat), position(position), direction(direction), touche(touche){}

void Arrow::seDeplacer(int deplacement)
{
    position += deplacement;
}