#ifndef __BOWMAN_H__
#define __BOWMAN_H__

/**
 * \file Bowman.h
 * \brief Classe du Bowman
 * \author SINET Theo
 * \version 0.1
 * \date 09 avril 2022
 */
#include "Mob.h"
#include "Arrow.h"

/**
 * \class Bowman
 * \brief classe representant le Bowman, hérite de Mob
 * \author SINET Theo
 *  La classe gere l'objet Bowman
 */
class Bowman : public Mob
{
    private:
        int nbFleche; /**< un entier */
        Arrow* arrow; /**< pointeur vers une flèche */
        
        /**
        *  \brief verifi si il y a un obstacle
        *  \author SINET Theo
        *  \param tab : la map
        *  \param i : la fufutr position
        *  \return true si le Bowman peut tirer sa flèche
        *  Methode qui retourne true lorsque qu'il n'y à pas d'obstacle entre le Bowman et le Joueur 
        */
        bool verifObstacle(std::string* tab, int i);

    public:
        /**
        *  \brief constructeur par défaut et initialisation
        *  \author SINET Theo
        *  Constructeur par défaut et initialisation du Bowman
        */
        Bowman(int nbFleche=1, Arrow* arrow = new Arrow());
        /**
        *  \brief est un Bowman
        *  \author SINET Theo
        *  \return true
        *  Methode qui retourne true lorsque elle est appelée 
        */
        bool isBowman(){return true;}
        /**
        *  \brief verifie si le Bowman peut tirer
        *  \author SINET Theo 
        *  \param positionJoueur : position du joueur 
        *  \param tab : la map 
        *  \param nbLigne : nombre de ligne de la map 
        *  \param nbColonne : nombre de colone de la map 
        *  \return true si le Bowman peut tirer, fasle sinon
        *  Methode qui verifie si le joueur peut tirer
        */
        bool peutTirer(int positionJoueur, std::string* tab, int nbLigne, int nbColonne);
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
        char tirer(int positionJoueur, std::string* tab, int nbLigne, int nbColonne);

        /**
        *  \brief getteur nbFleche
        *  \author SINET Theo
        *  \return le nombre de flèche
        *  récupère le nombre de flèche du Bowman
        */
        int getNbFleche(){return nbFleche;}
        /**
        *  \brief getteur arrow
        *  \author SINET Theo
        *  \return la flèche du Bowman
        *  récupère la flèche du Bowman
        */
        Arrow* getArrow(){return arrow;}

        /**
        *  \brief setteur nbFleche
        *  \author SINET Theo
        *  \param nbFleche : le nombre de flèche du Bowman
        *  change le nombre de flèche du Bowman
        */
        void setNbFleche(int nbFleche){this->nbFleche = nbFleche;}
};


#endif