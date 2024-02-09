#ifndef __BOMBE_H__
#define __BOMBE_H__
/**
 * \file Bombe.h
 * \brief Classe de la bombe
 * \author SINET Theo
 * \version 0.1
 * \date 09 avril 2022
 */

// #include <string>
// #include <iostream>
// #include "Mob.h"
// #include "Joueur.h"

/*! \namespace std
 * espace de nommage
 */
using namespace std;

/**
 * \class Bombe
 * \brief classe representant la bombe
 * \author SINET Theo
 *
 *  La classe gere l'objet bombe
 */
class Bombe
{
    private:
        int puissance; /**< un entier */
        int portee; /**< un entier */
        int position; /**< un entier */
        int tourExplosion; /**< un entier */
       

    public:
        /**
        *  \brief constructeur par defaut et initialisation
        *  \author SINET Theo
        *  \param puissance : puissance de la bombe
        *  \param portee : porter de la bombe
        *  \param position : position de la bombe
        *  \param tourExplosion : tour avant l'explosion de la bombe
        *  Constructeur par defaut et initialisation de la classe Bombe
        */
        Bombe(int puissance=1, int portee=2, int position=-1, int tourExplosion=0);
        /**
        *  \brief constructeur par copie
        *  \author SINET Theo
        *  \param Bombe : une bombe
        *  Constructeur par copie de la classe Bombe
        */
        Bombe(const Bombe& b1);

        /**
        *  \brief toucher un personnage
        *  \author SINET Theo
        *  
        */
        void toucherPersonnage();

        /**
        *  \brief getteur puissance
        *  \author SINET Theo
        *  \return puissance de la bombe
        *  récupère la puissance de la bombe
        */
        int getPuissance(){return puissance;}
        /**
        *  \brief getteur portee
        *  \author SINET Theo
        *  \return portee de la bombe
        *  récupère la portee de la bombe
        */
        int getPortee(){return portee;}
        /**
        *  \brief getteur position
        *  \author SINET Theo
        *  \return position de la bombe
        *  récupère la position de la bombe
        */
        int getPosition(){return position;}
        /**
        *  \brief getteur tourExplosion
        *  \author SINET Theo
        *  \return tour avant l'explosion de la bombe 
        *  récupère le nombre de tour avant l'explosion de la bombe
        */
        int getTourExplosion(){return tourExplosion;}

        /**
        *  \brief setteur puissance
        *  \author SINET Theo
        *  \param puissance : puissance 
        *  change la puissance de la bombe
        */
        void setPuissance(int puissance){this->puissance = puissance;}
        /**
        *  \brief setteur portee
        *  \author SINET Theo
        *  \param portee : portee
        *  change la portee de la bombe 
        */
        void setPortee(int portee){this->portee = portee;}
        /**
        *  \brief setteur position
        *  \author SINET Theo
        *  \param position : position
        *  change la position de la bombe 
        */
        void setPosition(int position){this->position = position;}
        /**
        *  \brief setteur explosion bombe
        *  \author SINET Theo
        *  \param tourExplosion : tour avant l'explosion
        *  change le nombre de tour avant l'explosion de la bombe 
        */
        void setTourExplosion(int tourExplosion){this->tourExplosion = tourExplosion;}
};


#endif