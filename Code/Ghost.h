#ifndef __GHOST_H__
#define __GHOST_H__

/**
 * \file Ghost.h
 * \brief Classe du ghost
 * \author SINET Theo
 * \version 0.1
 * \date 09 avril 2022
 */
#include "Mob.h"

/**
 * \class Ghost
 * \brief classe representant le Ghost, hérite de Mob
 * \author SINET Theo
 *  La classe gere l'objet Ghost
 */
class Ghost : public Mob
{
    public:
        /**
        *  \brief constructeur par défaut
        *  \author SINET Theo
        *  Constructeur par défaut du Ghost
        */
        Ghost(/*int hp, int speed, int damage, int position, int tourAttente*/);
        /**
        *  \brief est un Bowman
        *  \author SINET Theo
        *  \return false
        *  Methode qui retourne false lorsque elle est appelée 
        */
        bool isBowman(){return false;}
        
};


#endif