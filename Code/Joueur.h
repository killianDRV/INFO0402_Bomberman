#ifndef __JOUEUR_H__
#define __JOUEUR_H__

/**
 * \file Joueur.h
 * \brief Classe du Joueur
 * \author DARVILLE Killian, SINET Theo
 * \version 0.1
 * \date 09 avril 2022
 */
#include "Bombe.h"

/**
 * \class Joueur
 * \brief classe representant la Joueur
 * \author SINET Theo
 *
 *  La classe gere l'objet Joueur
 */
class Joueur
{
    private: 
        int hp; /**< un entier */
        int speed; /**< un entier */
        int position; /**< un entier */
        int nbBombMax; /**< un entier */
        int nbBombRestante; /**< un entier */
        Bombe *bombe; /**< un pointeur vres une bombe */

    public:
        /**
        *  \brief constructeur par défaut et initialisation
        *  \author SINET Theo
        *  \param hp : hp du joueur
        *  \param speed : speed du joueur
        *  \param position : position du joueur
        *  \param nbBombMax : nombre de bombe max à poser
        *  \param nbBombRestante : nombre de bombe restante à poser
        *  \param bombe : bombe du joueur
        *  Constructeur par défaut et initialisation du joueur
        */
        Joueur(int hp=3, int speed=1, int position=50, int nbBombMax=1, int nbBombRestante=1, Bombe* bombe = new Bombe());
        /**
        *  \brief constructeur par copie
        *  \author SINET Theo
        *  \param Joueur : joueur
        *  Constructeur par copie du joueur
        */
        Joueur(const Joueur& j1);

        /**
        *  \brief Destructeur
        *  \author SINET Theo
        *  Destructeur de la classe Joueur
        */
        ~Joueur(){/*delete bombe;*/}

        /**
        *  \brief se deplacer
        *  \author DARVILLE Killian, SINET Theo
        *  permet au joueur de se déplacer
        */
        void seDeplacer(char direction, int nbColonne);
        /**
        *  \brief poser bombe
        *  \author SINET Theo
        *  Permet au joueur de poser une bombe
        */
        void poserBombe();

        /**
        *  \brief getteur hp
        *  \author SINET Theo
        *  \return hp du joueur
        *  Permet de récuperer les hp du joueur
        */
        int getHP(){return hp;}
        /**
        *  \brief getteur speed
        *  \author SINET Theo
        *  \return speed du joueur
        *  Permet de récuperer la speed du joueur
        */
        int getSpeed(){return speed;}
        /**
        *  \brief getteur position
        *  \author SINET Theo
        *  \return position du joueur
        *  Permet de récuperer la position du joueur
        */
        int getPosition(){return position;}
        /**
        *  \brief getteur nbBombMax
        *  \author SINET Theo
        *  \return le nombre de bombe max
        *  Permet de récuperer le nombre max de bombe que le joueur peux poser
        */
        int getNbBombMax(){return nbBombMax;}
        /**
        *  \brief getteur nbBombRestante
        *  \author SINET Theo
        *  \return le nombre de bombe restante
        *  Permet de récuperer le nombre de bombe restante que le joueur peux poser
        */
        int getNbBombRestante(){return nbBombRestante;}
        /**
        *  \brief getteur bombe
        *  \author SINET Theo
        *  \return la bombe du joueur
        *  Permet de récuperer la bombe du joueur
        */
        Bombe* getBombe(){return bombe;}
        
        /**
        *  \brief setteur hp
        *  \author SINET Theo
        *  \param hp : les hp du joueur
        *  actualise les hp du joueur
        */
        void setHP(int hp){this->hp = hp;}
        /**
        *  \brief setteur speed
        *  \author SINET Theo
        *  \param speed : la speed du joueur
        *  actualise la speed du joueur
        */
        void setSpeed(int speed){this->speed = speed;}
        /**
        *  \brief setteur position
        *  \author SINET Theo
        *  \param position : la position du joueur
        *  actualise la position du joueur
        */
        void setPosition(int position){this->position = position;}
        /**
        *  \brief setteur nbBombMax
        *  \author SINET Theo
        *  \param nbBombMax : le nombre de bombe max du joueur
        *  actualise le nombre de bombe max du joueur
        */
        void setNbBombMax(int nbBombMax){this->nbBombMax = nbBombMax;}
        /**
        *  \brief setteur nbBombRestante
        *  \author SINET Theo
        *  \param nbBombRestante : le nombre de bombe restant du joueur
        *  actualise le nombre de bombe restant du joueur
        */
        void setNbBombRestante(int nbBombRestante){this->nbBombRestante = nbBombRestante;}
        /**
        *  \brief setteur bombe
        *  \author SINET Theo
        *  \param Bombe : une bombe
        *  actualise la bombe du joueur
        */
        void setBombe(Bombe* b1){this->bombe = b1;}
};


#endif