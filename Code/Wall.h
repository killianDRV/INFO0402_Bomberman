#ifndef __WALL_H__
#define __WALL_H__
/**
 * \file Wall.h
 * \brief Classe de la bombe
 * \author SINET Theo
 * \version 0.1
 * \date 09 avril 2022
 */

/**
 * \class Wall
 * \brief classe representant le Wall
 * \author SINET Theo
 *
 *  La classe gere l'objet Wall
 */
class Wall
{
    private:
        int hp; /**< un entier */
        int position; /**< un entier */

    public:
        /**
        *  \brief constructeur par defaut et initialisation
        *  \author SINET Theo
        *  \param hp : hp du Wall
        *  \param position : position du Wall
        *  Constructeur par defaut et initialisation de la classe Wall
        */
        Wall(int hp=2, int position=-1);
        
        /**
        *  \brief getteur hp
        *  \author SINET Theo
        *  \return les hp du Wall
        *  récupère les hp du Wall
        */
        int getHP(){return hp;}
        /**
        *  \brief getteur hp
        *  \author SINET Theo
        *  \return la position du Wall
        *  récupère la position du Wall
        */
        int getPosition(){return position;}

        /**
        *  \brief setteur hp
        *  \author SINET Theo
        *  \param hp : hp
        *  change les hp du wall 
        */
        void setHP(int hp){this->hp = hp;}
        /**
        *  \brief setteur position
        *  \author SINET Theo
        *  \param position : position
        *  change la position du wall 
        */
        void setPosition(int position){this->position = position;}

};

#endif