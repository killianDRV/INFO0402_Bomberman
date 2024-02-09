#ifndef __MOB_H__
#define __MOB_H__

/**
 * \file Mob.h
 * \brief Classe du Mob
 * \author SINET Theo
 * \version 0.1
 * \date 09 avril 2022
 */
#include <iostream>
#include <string>
#include "Arrow.h"

/**
 * \class Mob
 * \brief classe representant le Mob
 * \author SINET Theo
 *
 *  La classe gere l'objet Mob
 */
class Mob
{
    protected:
        int hp; /**< un entier */
        int speed; /**< un entier */
        int damage; /**< un entier */
        int position; /**< un entier */
        int tourAttente; /**< un entier */
        bool mort; /**< un booleen */

        /**
        *  \brief récupère la ligne du Mob
        *  \author SINET Theo
        *  \param positionPerso : position du Mob
        *  \param nbLigne : nombre de ligne de la map
        *  \param nbColonne : nombre de colonne de la map
        *  \return le ligne du Mob
        *  récupère la ligne du Mob
        */
        int getLigne(int positionPerso, int nbLigne, int nbColonne);
        /**
        *  \brief récupère la colonne du Mob
        *  \author SINET Theo
        *  \param positionPerso : position du Mob
        *  \param nbColonne : nombre de colonne de la map
        *  \return le colonne du Mob
        *  récupère la colonne du Mob
        */
        int getColonne(int positionPerso, int nbColonne);

    public:
        /**
        *  \brief constructeur par defaut et initialisation
        *  \author SINET Theo
        *  \param hp : hp du Mob
        *  \param speed : speed du Mob
        *  \param damage : damage du Mob
        *  \param position : position du Mob
        *  \param tourAttente : tour avant que le Mob puisse jouer
        *  Constructeur par defaut et initialisation de la classe Mob
        */
        Mob(int hp=1, int speed=1, int damage=1, int position=42, int tourAttente=0, bool mort=false);
        /**
        *  \brief constructeur par copie
        *  \author SINET Theo
        *  \param Mob : un Mob
        *  Constructeur par copie de la classe Mob
        */
        Mob(const Mob& m1);

        /**
        *  \brief se deplacer
        *  \author DARVILLE Killian, SINET Theo
        *  permet au Mob de se déplacer
        */
        void seDeplacer(int positionJoueur, int nbLigne, int nbColonne);
        /**
        *  \brief attaquer
        *  \author SINET Theo
        *  \return les hp du joueur après avoir pris des dégats
        *  Permet au Mob d'attaquer et de faire des dégats
        */
        int attaquer(int hpJoueur);
        /**
        *  \brief est un Bowman
        *  \author SINET Theo
        *  \return false
        *  Methode qui retourne false lorsque elle est appelée 
        */
        virtual bool isBowman(){return false;}
        /**
        *  \brief est un Bowman
        *  \param positionJoueur : position du joueur
        *  \param tab : tableau de jeu
        *  \param nbLigne : nombre de ligne de la map
        *  \param nbColonne : nombre de colonne de la map
        *  \return false
        *  Methode qui retourne false lorsque elle est appelée 
        */
        virtual bool peutTirer(int positionJoueur, std::string* tab, int nbLigne, int nbColonne){return false;}
        /**
        *  \brief tirer une flèche
        *  \author SINET Theo
        *  \param positionJoueur : position du joueur 
        *  \param tab : la map 
        *  \param nbLigne : nombre de ligne de la map 
        *  \param nbColonne : nombre de colone de la map 
        *  \return la direction du tir
        *  Methode qui permet au Bowman de tirer une flèche 
        */
        virtual char tirer(int positionJoueur, std::string* tab, int nbLigne, int nbColonne){return ' ';}
        /**
        *  \brief getteur nbFleche
        *  \author SINET Theo
        *  \return le nombre de flèche
        *  récupère le nombre de flèche du Bowman
        */
        virtual int getNbFleche(){return 0;}
        /**
        *  \brief getteur arrow
        *  \author SINET Theo
        *  \return la flèche du Bowman
        *  récupère la flèche du Bowman
        */
        virtual Arrow* getArrow(){return NULL;}
        /**
        *  \brief setteur nbFleche
        *  \author SINET Theo
        *  \param nbFleche : le nombre de flèche du Bowman
        *  change le nombre de flèche du Bowman
        */
        virtual void setNbFleche(int nbFleche){}

        /**
        *  \brief getteur hp
        *  \author SINET Theo
        *  \return hp du Mob
        *  Permet de récuperer les hp du Mob
        */
        int getHP(){return hp;}
        /**
        *  \brief getteur speed
        *  \author SINET Theo
        *  \return speed du Mob
        *  Permet de récuperer la speed du Mob
        */
        int getSpeed(){return speed;}
        /**
        *  \brief getteur damage
        *  \author SINET Theo
        *  \return damage du Mob
        *  Permet de récuperer les damage du Mob
        */
        int getDamage(){return damage;}
        /**
        *  \brief getteur position
        *  \author SINET Theo
        *  \return position du Mob
        *  Permet de récuperer la position du Mob
        */
        int getPosition(){return position;}
        /**
        *  \brief getteur tourAttente
        *  \author SINET Theo
        *  \return nombre de tour en attente
        *  Permet de récuperer le nombre de tour durant lequel le Mob est en attente
        */
        int getTourAttente(){return tourAttente;}
        /**
        *  \brief getteur mort
        *  \author SINET Theo
        *  \return si le joueur est mort
        *  Permet de récupérer si le joueur est mort
        */
        bool getMort(){return mort;}

        /**
        *  \brief setteur hp
        *  \author SINET Theo
        *  \param hp : les hp du Mob
        *  actualise les hp du Mob
        */
        void setHP(int hp){this->hp = hp;}
        /**
        *  \brief setteur speed
        *  \author SINET Theo
        *  \param speed : la speed du Mob
        *  actualise la speed du Mob
        */
        void setSpeed(int speed){this->speed = speed;}
        /**
        *  \brief setteur damage
        *  \author SINET Theo
        *  \param speed : les damage du Mob
        *  actualise les damage du Mob
        */
        void setDamage(int damage){this->damage = damage;}
        /**
        *  \brief setteur position
        *  \author SINET Theo
        *  \param position : la position du Mob
        *  actualise la position du Mob
        */
        void setPosition(int position){this->position = position;}   
        /**
        *  \brief setteur tourAttente
        *  \author SINET Theo
        *  \param tourAttente : le nombre de tour en attente du Mob
        *  actualise le nombre de tour en attente du Mob
        */
        void setTourAttente(int tourAttente){this->tourAttente = tourAttente;}
        /**
        *  \brief setteur mort
        *  \author SINET Theo
        *  \param mort : si le Mob est mort ou non
        *  actualise le booleen mort
        */
        void setMort(bool mort){this->mort=mort;}
};

#endif