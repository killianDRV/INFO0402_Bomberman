#ifndef __SPEEDUP_H__
#define __SPEEDUP_H__

/**
 * \file SpeedUp.h
 * \brief Classe de l'item SpeedUp
 * \author SINET Theo
 * \version 0.1
 * \date 09 avril 2022
 */
#include "Item.h"

/**
 * \class SpeedUp
 * \brief classe representant l'item SpeedUp, hérite de Item
 * \author SINET Theo
 *
 *  La classe gere l'objet SpeedUp
 */
class SpeedUp : public Item
{
    public:
        /**
        *  \brief constructeur par défaut et initialisation
        *  \author SINET Theo
        *  Constructeur par défaut et initialisation de l'item SpeedUp
        */
        SpeedUp();
        /**
        *  \brief augmenterVitesse
        *  \author SINET Theo
        *  \param joueur : un joueur
        *  permet d'augmenter le nombre de déplacement du joueur
        */
        void augmenterVitesse(Joueur* joueur);
};

#endif