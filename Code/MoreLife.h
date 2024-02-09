#ifndef __MORELIFE_H__
#define __MORELIFE_H__

/**
 * \file MoreLife.h
 * \brief Classe de l'item MoreLife
 * \author SINET Theo
 * \version 0.1
 * \date 09 avril 2022
 */
#include "Item.h"

/**
 * \class MoreLife
 * \brief classe representant l'item MoreLife, hérite de Item
 * \author SINET Theo
 *
 *  La classe gere l'objet MoreLife
 */
class MoreLife : public Item
{
    public:
        /**
        *  \brief constructeur par défaut et initialisation
        *  \author SINET Theo
        *  Constructeur par défaut et initialisation de l'item MoreLife
        */
        MoreLife();
        /**
        *  \brief ajouterVie
        *  \author SINET Theo
        *  \param joueur : un joueur
        *  permet d'ajouter de la vie au joueur
        */
        void ajouterVie(Joueur* joueur);
};

#endif