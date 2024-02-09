#ifndef __SCALEUP_H__
#define __SCALEUP_H__

/**
 * \file ScaleUp.h
 * \brief Classe de l'item ScaleUp
 * \author SINET Theo
 * \version 0.1
 * \date 09 avril 2022
 */
#include "Item.h"

/**
 * \class ScaleUp
 * \brief classe representant l'item ScaleUp, hérite de Item
 * \author SINET Theo
 *
 *  La classe gere l'objet ScaleUp
 */
class ScaleUp : public Item
{
    public:
        /**
        *  \brief constructeur par défaut et initialisation
        *  \author SINET Theo
        *  Constructeur par défaut et initialisation de l'item ScaleUp
        */
        ScaleUp();
        /**
        *  \brief augmenterPortee
        *  \author SINET Theo
        *  \param joueur : un joueur
        *  permet d'augmenter la porter de la bombe du joueur
        */
        void augmenterPortee(Joueur* joueur);
};

#endif