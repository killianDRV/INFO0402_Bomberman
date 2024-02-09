#include "Bombe.h"

Bombe::Bombe(int puissance, int portee, int position, int tourExplosion): puissance(puissance), portee(portee), position(position), tourExplosion(tourExplosion){}
Bombe::Bombe(const Bombe& b1): puissance(b1.puissance), portee(b1.portee){}
