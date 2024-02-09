#ifndef __POWERUP_H__
#define __POWERUP_H__

/**
 * \file PowerUp.h
 * \brief Classe de l'item PowerUp
 * \author SINET Theo
 * \version 0.1
 * \date 09 avril 2022
 */
#include "Item.h"

/**
 * \class PowerUp
 * \brief classe representant l'item PowerUp, hérite de Item
 * \author SINET Theo
 *
 *  La classe gere l'objet PowerUp
 */
class PowerUp : public Item
{
    public:
        /**
        *  \brief constructeur par défaut et initialisation
        *  \author SINET Theo
        *  Constructeur par défaut et initialisation de l'item PowerUp
        */
        PowerUp();
        /**
        *  \brief augmenterPuissance
        *  \author SINET Theo
        *  \param joueur : un joueur
        *  permet d'augmenter la puissance des bombes du joueur
        */
        void augmenterPuissance(Joueur* joueur);
};


#endif