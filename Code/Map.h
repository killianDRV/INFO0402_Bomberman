#ifndef __MAP_H__
#define __MAP_H__

/**
 * \file Map.h
 * \brief Classe de la map
 * \author DARVILLE Killian, SINET Theo
 * \version 0.1
 * \date 09 avril 2022
 */
#include <fstream>
#include "Wall.h"
#include "Objectif.h"

/**
 * \class Map
 * \brief classe representant la Map
 * \author DARVILLE Killian, SINET Theo
 *
 *  La classe gere l'objet Map
 */
class Map
{
    private:
        int nbLigne; /**< un entier */
        int nbColonne; /**< un entier */
        int nbCaractere; /**< un entier */
        std::string *tab; /**< un tableau de string */
        std::string nomFichier; /**< un string */
        bool emoji; /**< un booleen */
        std::fstream monFlux; /**< un fstream */
        int porteePossibleBombe[4]; /**< un tableau d'entier */
        Wall** wall; /**< un tableau de murs */
        int nbWallMap; /**< le nombre de murs dans la map */
        Objectif* objectif; /**< l'objectif */

        /**
        *  \brief récupère la porter de la bombe
        *  \author DARVILLE Killian
        *  \param pos : position de la bombe
        *  \param direction : direction de l'explosion de la bombe
        *  \param porterDeLaBombeGetteur : porter max de la bombe
        *  \return la porter de la bombe
        *  récupère la porter de la bombe pour chaque direction
        */
        int recupPorteeMaxBombe(int pos, char direction, int porterDeLaBombeGetteur);
        /**
        *  \brief récupère la ligne de l'entité
        *  \author SINET Theo
        *  \param positionPerso : position de l'entité
        *  \param nbLigne : nombre de ligne de la map
        *  \param nbColonne : nombre de colonne de la map
        *  \return le ligne de l'entité
        *  récupère la ligne de l'entité
        */
        int getLigne(int positionPerso, int nbLigne, int nbColonne);
        /**
        *  \brief récupère la colonne de l'entité
        *  \author SINET Theo
        *  \param positionPerso : position de l'entité
        *  \param nbColonne : nombre de colonne de la map
        *  \return le colonne de l'entité
        *  récupère la colonne de l'entité
        */
        int getColonne(int positionPerso, int nbColonne);
        /**
        *  \brief vérifie si la flèche est bloquer
        *  \author DARVILLE Killian
        *  \param pos : position de la flèche
        *  \param deplacement : direction de la flèche
        *  \return true si la flèche sort de la carte, false sinon
        *  retourne true si la flèche sort de la carte, false sinon
        */
        bool flecheBloquer(int pos, char deplacement);
        /**
        *  \brief retirer la flèche
        *  \author DARVILLE Killian
        *  \param pos : position de la flèche
        *   Fait disparaitre la flèche de la carte
        */
        void retirerFleche(int pos);

    public:
        /**
        *  \brief constructeur par defaut et initialisation
        *  \author SINET Theo
        *  \param nbLigne : nombre de ligne de la map
        *  \param nbColonne : nombre de colonne de la map
        *  \param nbCaractere : nombre de caractere de la map
        *  \param tab : tableau de string contenant la map
        *  \param nomFichier : nom du fichier .txt de la map
        *  \param emoji : choix du joueur (version emoji ou version simple)
        *  \param wall : tous les murs de la map
        *  \param nbWallMap : nombre de murs
        *  Constructeur par defaut et initialisation de la classe Map
        */
        Map(int nbLigne=0, int nbColonne=0, int nbCaractere=0, std::string* tab=new std::string(), std::string nomFichier="maptest.txt", bool emoji=false, Wall** wall = new Wall*(), int nbWallMap=0, Objectif* objectif = new Objectif());

        /**
        *  \brief affiche la map
        *  \author DARVILLE Killian
        *  Affiche la map dans le terminal
        */
        void affichageMap(int nbHP, int puissanceBombe, int nbBombMax, int speed, int portee);
        /**
        *  \brief actualise la map
        *  \author DARVILLE Killian
        *  Actualise la map dans le fichier .txt
        */
        void actualiserMap();
        /**
        *  \brief lecture de la map
        *  \author DARVILLE Killian
        *  Lis la map dans dans le fichier .txt
        */
        void lectureMap();
        /**
        *  \brief information sur la map
        *  \author DARVILLE Killian
        *  Récupère le nombre de ligne, nombre de colonne et nombre de caractère du fichier .txt
        */
        void infoMap();
        /**
        *  \brief afficher bombe et fleche
        *  \author SINET Theo
        *  \param pos : position de l'objet
        *  \param lettre : lettre de l'objet
        *  Affiche la bombe quand elle est poser et la flèche quand elle est tirer
        */
        void afficherPersoObjet(int pos, char lettre);
        /**
        *  \brief gère les déplacements des entités
        *  \author DARVILLE Killian
        *  \param pos : position de l'entité
        *  \param x : futur position de l'entité
        *  Permet aux entités de se déplacer 
        */
        void gestionDeplacementMap(int pos, int x); // pos : la position du personnage ; x : la valeur liée au déplacement du personnage 
        /**
        *  \brief fait exploser une bombe
        *  \author DARVILLE Killian
        *  \param pos : position de l'entité
        *  \param porteePossibleBombe : porter de la bombe selon les élements de la map
        *  \param porteeBombe : porter max de la bombe
        *  Permet de faire exploser une bombe
        */
        void explosionBombe(int pos, int porteeBombe);
        /**
        *  \brief retire l'explosion de la bombe
        *  \author DARVILLE Killian
        *  \param pos : position de l'entité
        *  \param porteePossibleBombe : porter de la bombe selon les élements de la map
        *  Permet de retirer l'explosion de la bombe
        */
        void retirerExplosionBombe(int positionBombe);
        /**
        *  \brief verifie si le joueur est bloquer
        *  \author DARVILLE Killian
        *  \param position : position du joueur
        *  \return false si le joueur est bloquer, true sinon
        *  vérifie si le joueur est bloquer
        */
        bool verifJoueurBloque(int position);
        /**
        *  \brief deplacement de la flèche
        *  \author DARVILLE Killian
        *  \param pos : position de la flèche
        *  \param direction : direction de la flèche
        *  Déplace la flèche sur la map
        */
        void deplacementFleche(int pos, char direction);
        /**
        *  \brief compte le nombre de murs dans la map
        *  \author SINET Theo
        *  \return le nombre de murs 
        *  compte le nombre de murs dans la map
        */
        int compteMurs();
        /**
        *  \brief alloue le nombre de murs qu'il faut
        *  \author SINET Theo
        *  alloue le nombre de murs qu'il faut
        */
        void alloueMurs();
        /**
        *  \brief trouver l'objectif
        *  \author SINET Theo
        *   trouve l'objectif
        */
        void positionObjectif();
        
        

        /**
        *  \brief getteur nbLigne
        *  \author SINET Theo
        *  \return le nombre de ligne de la map
        *  retourne le nombre de ligne de la map
        */
        int getNbLigne(){return nbLigne;}
        /**
        *  \brief getteur nbColonne
        *  \author SINET Theo
        *  \return le nombre de colonne de la map
        *  retourne le nombre de colonne de la map
        */
        int getNbColonne(){return nbColonne;}
        /**
        *  \brief getteur nbColonne
        *  \author SINET Theo
        *  \return le nombre de caractere de la map
        *  retourne le nombre de caractere de la map
        */
        int getNbCaractere(){return nbCaractere;}
        /**
        *  \brief getteur tab
        *  \author SINET Theo
        *  \return la map
        *  retourne la map
        */
        std::string* getTab(){return tab;}
        /**
        *  \brief getteur nomFichier
        *  \author SINET Theo
        *  \return le nom du fichier .txt 
        *  retourne le nom du fichier .txt 
        */
        std::string getNomFichier(){return nomFichier;}
        /**
        *  \brief getteur emoji
        *  \author SINET Theo
        *  \return true si le joueur joue avec les emoji, false sinon 
        *  Permet de savoir si le joueur joue avec les emoji ou non 
        */
        bool getEmoji(){return emoji;}

        /**
        *  \brief setteur nbLigne
        *  \author SINET Theo
        *  \param nbLigne : nombre de ligne
        *  change le nombre de ligne 
        */
        void setNbLigne(int nbLigne){this->nbLigne=nbLigne;}
        /**
        *  \brief setteur nbColonne
        *  \author SINET Theo
        *  \param nbLigne : nombre de colonne
        *  change le nombre de colonne 
        */
        void setNbColonne(int nbColonne){this->nbColonne=nbColonne;}
        /**
        *  \brief setteur nbCaractere
        *  \author SINET Theo
        *  \param nbLigne : nombre de caractere
        *  change le nombre de nbCaractere 
        */
        void setNbCaractere(int nbCaractere){this->nbCaractere=nbCaractere;}
        /**
        *  \brief setteur tab
        *  \author SINET Theo
        *  \param tab : le tableau
        *  change la tableau (la map) 
        */
        void setTab(std::string* tab){this->tab=tab;}
        /**
        *  \brief setteur nomFichier
        *  \author SINET Theo
        *  \param nomFichier : le nom du fichier
        *  change le nom du fichier
        */
        void setNomFichier(std::string nomFichier){this->nomFichier=nomFichier;}
        /**
        *  \brief setteur emoji
        *  \author SINET Theo
        *  \param emoji : emoji
        *  change l'emoji
        */
        void setEmoji(bool emoji){this->emoji = emoji;}
        /**
        *  \brief getteur porteePossibleBombe
        *  \author SINET Theo
        *  \return le tableau de porter de la bombe 
        *  récupère le tableau de porter de la bombe 
        */
        int* getPorteePossibleBombe(){return porteePossibleBombe;}
        /**
        *  \brief getteur wall
        *  \author SINET Theo
        *  \return le tableau de murs 
        *  récupère le tableau de murs 
        */
        Wall** getWall(){return wall;}
        /**
        *  \brief getteur nombre de murs de la Map
        *  \author SINET Theo
        *  \return le nombre de murs de la Map
        *  récupère nombre de murs de la Map
        */
        int getNbWallMap(){return nbWallMap;}
        Objectif* getObjectif(){return objectif;}
};

#endif