#ifndef __OBJECTIF__H
#define __OBJECTIF__H
/**
 * \file Objectif.h
 * \brief Classe de la bombe
 * \author SINET Theo
 * \version 0.1
 * \date 09 avril 2022
 */

/**
 * \class Objectif
 * \brief classe representant l'Objectif
 * \author SINET Theo
 *
 *  La classe gere l'objet Objectif
 */
class Objectif
{
    private:
        int hp; /**< un entier */
        int position; /**< un entier */
        bool sortieValide; /**< un booleen */
    
    public: 
    /**
        *  \brief constructeur par defaut et initialisation
        *  \author SINET Theo
        *  \param hp : hp de l'Objectif
        *  \param position : porter de l'Objectif
        *  \param sortieValide : si la sortie est valide ou non
        *  Constructeur par defaut et initialisation de la classe Objectif
        */
        Objectif(int hp=2, int position=-1, bool sortieValide=false);

        /**
        *  \brief getteur hp
        *  \author SINET Theo
        *  \return hp de l'Objectif
        *  récupère les hp de l'Objectif
        */
        int getHP(){return hp;}
        /**
        *  \brief getteur position
        *  \author SINET Theo
        *  \return position de l'Objectif
        *  récupère la position de l'Objectif
        */
        int getPosition(){return position;}
        /**
        *  \brief getteur sortieValide
        *  \author SINET Theo
        *  \return true si la sortie est valide, false sinon
        *  récupère si la sortie de l'Objectif est valide
        */
        bool getSortieValide(){return sortieValide;}

        /**
        *  \brief setteur hp
        *  \author SINET Theo
        *  \param hp : hp 
        *  change les hp de l'Objectif
        */
        void setHP(int hp){this->hp = hp;}
        /**
        *  \brief setteur position
        *  \author SINET Theo
        *  \param position : position 
        *  change la position de l'Objectif
        */
        void setPosition(int position){this->position = position;}
        /**
        *  \brief setteur sortieValide
        *  \author SINET Theo
        *  \param sortieValide : sortieValide 
        *  change si la sortie de l'Objectif est valide ou non
        */
        void setSortieValide(bool sortieValide){this->sortieValide=sortieValide;}
};


#endif