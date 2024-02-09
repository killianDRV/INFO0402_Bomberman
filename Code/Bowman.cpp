#include "Bowman.h"

using namespace std;

Bowman::Bowman(int nbFleche, Arrow* arrow): Mob::Mob(), nbFleche(nbFleche), arrow(arrow){}

bool Bowman::peutTirer(int positionJoueur, std::string* tab, int nbLigne, int nbColonne)
{
    int ligneMonstre = getLigne(position, nbLigne, nbColonne), ligneJoueur = getLigne(positionJoueur, nbLigne, nbColonne);
    int colonneMonstre = getColonne(position, nbColonne), colonneJoueur = getColonne(positionJoueur, nbColonne);
    bool tire = true;
    int i;

    if(ligneMonstre == ligneJoueur)
    {
        if(colonneJoueur<colonneMonstre)
        {
            for(i=(colonneJoueur + (ligneJoueur*nbColonne)); i<(colonneMonstre + (ligneMonstre*nbColonne)); i++)
            {
                tire = verifObstacle(tab, i);     
            }
            if(tire)
            {
                arrow->setPosition(position-1);
            }
        }
        else if(colonneJoueur>colonneMonstre)
        {
            for(i=1+(colonneMonstre + (ligneMonstre*nbColonne)); i<(colonneJoueur + (ligneJoueur*nbColonne)); i++)
            {
                tire = verifObstacle(tab, i); 
            }
            if(tire)
            {
                arrow->setPosition(position+1);
            }
        }
    }
    else if(colonneMonstre == colonneJoueur)
    {
        if(ligneJoueur<ligneMonstre)
        {
            for(i=(colonneJoueur + (ligneJoueur*nbColonne)); i<(colonneMonstre + (ligneMonstre*nbColonne)); i+=nbColonne)
            {
                tire = verifObstacle(tab, i);       
            }
            if(tire)
            {
                arrow->setPosition(position-nbColonne);
            }
        }
        else if(ligneJoueur>ligneMonstre)
        {
            for(i=nbColonne+(colonneMonstre + (ligneMonstre*nbColonne)); i<(colonneJoueur + (ligneJoueur*nbColonne)); i+=nbColonne)
            {
                tire = verifObstacle(tab, i);          
            }
            if(tire)
            {
                arrow->setPosition(position+nbColonne);
            }
        }
    }
    else
    {
        tire = false;
    }
    return tire;
}


bool Bowman::verifObstacle(std::string* tab, int i)
{
    bool tire = true;

    if(tab[i]=="w" || tab[i]=="W" || tab[i]=="wG" || tab[i]=="WG" || tab[i]=="G"|| tab[i]=="M" || tab[i]=="B" || tab[i]=="0G" || tab[i]=="G0")
    {
        tire = false;
    }
    else if(tab[i]=="MLB" || tab[i]=="MLM" || tab[i]=="MLG" || tab[i]=="MBM" || tab[i]=="MBG" || tab[i]=="MBB" || tab[i]=="PUB" || tab[i]=="PUM" || tab[i]=="PUG" || tab[i]=="SCG" || tab[i]=="SCM" || tab[i]=="SCB" || tab[i]=="SPM" || tab[i]=="SPG" || tab[i]=="SPB")
    {
        tire = false;
    }  

    return tire;
}



char Bowman::tirer(int positionJoueur, std::string* tab, int nbLigne, int nbColonne)
{
    int ligneMonstre = getLigne(position, nbLigne, nbColonne), ligneJoueur = getLigne(positionJoueur, nbLigne, nbColonne);
    int colonneMonstre = getColonne(position, nbColonne), colonneJoueur = getColonne(positionJoueur, nbColonne);
    int i;
    char direction;


    if(ligneMonstre == ligneJoueur)
    {
        if(colonneJoueur<colonneMonstre)
        {
            direction = '<';
            arrow->setDirection(direction);
        }
        else if(colonneJoueur>colonneMonstre)
        {
            direction = '>';
            arrow->setDirection(direction);
        }
    }
    else if(colonneMonstre == colonneJoueur)
    {
        if(ligneJoueur<ligneMonstre)
        {
            direction = 'A';
            arrow->setDirection(direction);
        }
        else if(ligneJoueur>ligneMonstre)
        {
            direction = 'V';
            arrow->setDirection(direction);
        }
    }
    return direction;
}