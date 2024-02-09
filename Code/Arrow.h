#ifndef __ARROW_H__
#define __ARROW_H__
/**
 * \file Arrow.h
 * \brief Classe de la flèche
 * \author SINET Theo
 * \version 0.1
 * \date 09 avril 2022
 */


/**
 * \class Arrow
 * \brief classe representant la Arrow
 * \author SINET Theo
 *
 *  La classe gere l'objet Arrow
 */
class Arrow
{
    private:
        int degat; /**< un entier */
        int position; /**< un entier */
        bool touche; /**< un booleen */
        char direction; /**< un char */
    public:
        /**
        *  \brief constructeur par defaut et initialisation
        *  \author SINET Theo
        *  \param degat : degat de la flèche
        *  \param position : position de la flèche
        *  \param direction : direction de la flèche
        *  \param touche : si la flèche touche ou non
        *  Constructeur par defaut et initialisation de la classe Arrow
        */
        Arrow(int degat=1, int position=-1, char direction=' ', bool touche=false);
        /**
        *  \brief seDeplacer
        *  \author SINET Theo
        *  \param deplacement : le sens du déplacement de la flèche
        *  Permet à la flèche de se déplacer
        */
        void seDeplacer(int deplacement);
        
        /**
        *  \brief getteur degat
        *  \author SINET Theo
        *  \return degat
        *  récupère les degats de la flèche
        */
        int getDegat(){return this->degat;}
        /**
        *  \brief getteur position
        *  \author SINET Theo
        *  \return position
        *  récupère la position de la flèche
        */
        int getPosition(){return this->position;}
        /**
        *  \brief getteur direction
        *  \author SINET Theo
        *  \return direction
        *  récupère la direction de la flèche
        */
        char getDirection(){return this->direction;}
        /**
        *  \brief getteur touche
        *  \author SINET Theo
        *  \return touche
        *  récupère true si la flèche touche, false sinon
        */
        bool getTouche(){return this->touche;}

        /**
        *  \brief setteur degat
        *  \author SINET Theo
        *  \param degat : degat 
        *  change la degat de la flèche
        */
        void setDegat(int degat){this->degat = degat;}
        /**
        *  \brief setteur position
        *  \author SINET Theo
        *  \param position : position 
        *  change la position de la flèche
        */
        void setPosition(int position){this->position = position;}
        /**
        *  \brief setteur direction
        *  \author SINET Theo
        *  \param position : direction 
        *  change la direction de la flèche
        */
        void setDirection(char direction){this->direction = direction;}
        /**
        *  \brief setteur touche
        *  \author SINET Theo
        *  \param touche : touche 
        *  change le booleen touche
        */
        void setTouche(bool touche){this->touche = touche;}
};


#endif