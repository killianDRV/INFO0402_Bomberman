#ifndef __MOREBOMB_H__
#define __MOREBOMB_H__

/**
 * \file MoreBomb.h
 * \brief Classe de l'item MoreBomb
 * \author SINET Theo
 * \version 0.1
 * \date 09 avril 2022
 */
#include "Item.h"

/**
 * \class MoreBomb
 * \brief classe representant l'item MoreBomb, hérite de Item
 * \author SINET Theo
 *
 *  La classe gere l'objet MoreBomb
 */
class MoreBomb : public Item
{
    public:
        /**
        *  \brief constructeur par défaut et initialisation
        *  \author SINET Theo
        *  Constructeur par défaut et initialisation de l'item MoreBomb
        */
        MoreBomb();
        /**
        *  \brief ajouterBombe
        *  \author SINET Theo
        *  \param joueur : un joueur
        *  permet d'ajouter une bombe supplémentaire au joueur
        */
        void ajouterBombe(Joueur* joueur);
};

#endif