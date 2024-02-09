#include <iostream>
#include "Mob.h"

Mob::Mob(int hp, int speed, int damage, int position, int tourAttente, bool mort): hp(hp), speed(speed), damage(damage), position(position), tourAttente(tourAttente), mort(mort){}
Mob::Mob(const Mob& m1): hp(m1.hp), speed(m1.speed), damage(m1.damage), position(m1.position){}


int Mob::getLigne(int positionPerso, int nbLigne, int nbColonne)
{
    int ligne=-1, x=nbColonne, i=0;
    bool trouver = false;

    while(!trouver || i<nbLigne){
        if(positionPerso>=x*i && positionPerso<=(x*(i+1))-1){
            ligne = i;
            trouver=true;
        }
        i++; 
    }
    
    return ligne; 
}

int Mob::getColonne(int positionPerso, int nbColonne)
{
    return positionPerso%nbColonne;
}


void Mob::seDeplacer(int positionJoueur, int nbLigne, int nbColonne)
{
    int ligneMonstre = getLigne(position, nbLigne, nbColonne), ligneJoueur = getLigne(positionJoueur, nbLigne, nbColonne);
    int colonneMonstre = getColonne(position, nbColonne), colonneJoueur = getColonne(positionJoueur, nbColonne);

    if(position != positionJoueur)
    {
         if(ligneJoueur < ligneMonstre){position += -nbColonne;}
        else if(ligneJoueur > ligneMonstre){position += nbColonne;}
        else
        {
            if(colonneJoueur < colonneMonstre) {position += -1;}
            else if(colonneJoueur > colonneMonstre) {position += 1;}
        }
    }

}

int Mob::attaquer(int hpJoueur)
{
    return hpJoueur-=damage;
}

