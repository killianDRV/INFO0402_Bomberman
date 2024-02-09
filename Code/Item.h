#ifndef __ITEM_H__
#define __ITEM_H__

/**
 * \file Item.h
 * \brief Classe de l'Item
 * \author SINET Theo
 * \version 0.1
 * \date 09 avril 2022
 */
#include "Joueur.h"
#include "Bombe.h"

/**
 * \class Item
 * \brief classe representant l'Item
 * \author SINET Theo
 *  La classe gere l'objet Item
 */
class Item
{
    private:
        int position; /**< un entier */

    public:
        /**
        *  \brief constructeur par defaut et initialisation
        *  \author SINET Theo
        *  \param position : position de l'Item
        *  Constructeur par defaut et initialisation de la classe Item
        */
        Item(int position=-1);

        /**
        *  \brief getteur position
        *  \author SINET Theo
        *  \return position de l'item
        *  récupère la position de l'item
        */
        int getPosition(){return this->position;}
        /**
        *  \brief setteur position
        *  \author SINET Theo
        *  \param position : la position de l'item
        *  met a jour la position de la item
        */
        void setPosition(int position){this->position = position;}

        /**
        *  \brief ajouterVie
        *  \author SINET Theo
        *  \param joueur : le joueur
        *  ajoute de la vie au joueur
        */
        virtual void ajouterVie(Joueur* joueur){}
        /**
        *  \brief ajouterBombe
        *  \author SINET Theo
        *  \param joueur : le joueur
        *  augmente le nombre de bombe du joueur
        */
        virtual void ajouterBombe(Joueur* joueur){}
        /**
        *  \brief augmenterVitesse
        *  \author SINET Theo
        *  \param joueur : le joueur
        *  augmente la vitesse du joueur
        */
        virtual void augmenterVitesse(Joueur* joueur){}
        /**
        *  \brief augmenterPuissance
        *  \author SINET Theo
        *  \param joueur : le joueur
        *  augmente la puissance de la bombe du joueur
        */
        virtual void augmenterPuissance(Joueur* joueur){}
        /**
        *  \brief augmenterPortee
        *  \author SINET Theo
        *  \param joueur : le joueur
        *  augmente la porter de la bombe du joueur
        */
        virtual void augmenterPortee(Joueur* joueur){}
};

#endif