#ifndef __MONSTER_H__
#define __MONSTER_H__

/**
 * \file Monster.h
 * \brief Classe du Monster
 * \author SINET Theo
 * \version 0.1
 * \date 09 avril 2022
 */
#include "Mob.h"

/**
 * \class Monster
 * \brief classe representant un Monster, hérite de Mob
 * \author SINET Theo
 *  La classe gere l'objet Monster
 */
class Monster : public Mob
{
    public:
        /**
        *  \brief constructeur par defaut
        *  \author SINET Theo
        *  Constructeur par defaut de la classe Monster
        */
        Monster();
        /**
        *  \brief est un Bowman
        *  \author SINET Theo
        *  \return false
        *  Methode qui retourne false lorsque elle est appelée 
        */
        bool isBowman(){return false;}
};


#endif