#include <iostream>
#include "Joueur.h"

using namespace std;

Joueur::Joueur(int hp, int speed, int position, int nbBombMax, int nbBombRestante, Bombe* bombe): hp(hp), speed(speed), position(position), nbBombMax(nbBombMax), nbBombRestante(nbBombRestante), bombe(bombe){}
Joueur::Joueur(const Joueur& j1): hp(j1.hp), speed(j1.speed), position(j1.position), nbBombMax(j1.nbBombMax), nbBombRestante(j1.nbBombRestante), bombe(j1.bombe){}


void Joueur::seDeplacer(char direction, int nbColonne)
{
    switch(direction)
    {
        case 'z':
            position += -nbColonne;
            break;
        case 's':
            position += nbColonne;
            break;
        case 'q':
            position += -1;
            break;
        case 'd':
            position += 1;
            break;
        default:
            cout << "Entrez z, q, s ou d" << endl;
    }
}


void Joueur::poserBombe()
{
    int nbBombePositionne = nbBombMax-nbBombRestante;
    int i=0;
    bool place=false;
    
    
    while(i<nbBombMax && !place) // while pour quitter si rien a positionner
    {
        if(i<nbBombePositionne && bombe[i].getPosition() == -1 && !place)
        {
            bombe[i].setPosition(position);
            bombe[i].setTourExplosion(4);
            place = true;
        }
        else if(bombe[nbBombePositionne].getPosition() == -1 && !place)
        {
            bombe[nbBombePositionne].setPosition(position);
            bombe[nbBombePositionne].setTourExplosion(4);
            place = true;
        }
        i++;
    }

    nbBombRestante -= 1;

}
