#ifndef __SYSTEM_H__
#define __SYSTEM_H__


/**
 * \file System.h
 * \brief Classe du System
 * \author DARVILLE Killian, SINET Theo
 * \version 0.1
 * \date 09 avril 2022
 */
#include "Joueur.h"
#include "Map.h"
#include "Mob.h"
#include "Item.h"
#include "Monster.h"
#include "Ghost.h"
#include "Bowman.h"
#include "Arrow.h"
#include "MoreLife.h"
#include "MoreBomb.h"
#include "SpeedUp.h"
#include "PowerUp.h"
#include "ScaleUp.h"
#include "Wall.h"
#include "Objectif.h"

/**
 * \class System
 * \brief classe representant le System
 * \author SINET Theo
 *
 *  La classe gere l'objet System
 */
class System
{
    private:
        Map* map; /**< un pointeur vers une Map */
        Joueur* joueur; /**< un pointeur vers un Joueur */
        Mob** mob; /**< un double pointeur vers un Mob */
        Item** item; /**< un double pointeur vers un item */
        int nbMobMap; /**< un entier */
        Wall** wall; /**< un tableau de murs */
        Objectif* objectif; /**< l'objectif */

        /**
        *  \brief joueurMort
        *  \author SINET Theo
        *  \return true si le joueur est mort, false sinon
        *  retourne si le joueur est mort ou non
        */
        bool joueurMort();
        /**
        *  \brief joueurMort
        *  \author SINET Theo
        *  \return true si le Mob est mort, false sinon
        *  retourne si le le est mort ou non
        */
        bool mobMort();
        /**
        *  \brief joueurItemFlecheMonstre
        *  \author DARVILLE Killian
        *  \param pos : position de l'entité
        *  gestion des dégats/affichages pour les colisions entre les joueurs, flèches
        *  items et monstres
        */
        void joueurItemFlecheMonstre(int pos);
        /**
        *  \brief gestion des fleches et Mobs
        *  \author SINET Theo
        *  \param pos : position de l'entité
        *  vérifie si une flèche touche un Mob
        */
        void gestionFlecheMob(int pos);
        /**
        *  \brief gestion des fleches et Joueur
        *  \author SINET Theo
        *  \param pos : position de l'entité
        *  vérifie si une flèche touche un Joueur
        */
        void gestionFlecheJoueur(int pos);
        /**
        *  \brief gestionMoreLife
        *  \author SINET Theo
        *  \param i : numéro de l'item
        *  \param trouve : booleen
        *  Permet de vérifier si le joueur passe sur l'item MoreLife
        */
        void gestionMoreLife(int i, bool trouve);
        /**
        *  \brief gestionMoreBomb
        *  \author SINET Theo
        *  \param i : numéro de l'item
        *  \param trouve : booleen
        *  Permet de vérifier si le joueur passe sur l'item MoreBomb
        */
        void gestionMoreBomb(int i, bool trouve);
        /**
        *  \brief gestionPowerUp
        *  \author SINET Theo
        *  \param i : numéro de l'item
        *  \param trouve : booleen
        *  Permet de vérifier si le joueur passe sur l'item PowerUp
        */
        void gestionPowerUp(int i, bool trouve);
        /**
        *  \brief gestionSpeedUp
        *  \author SINET Theo
        *  \param i : numéro de l'item
        *  \param trouve : booleen
        *  Permet de vérifier si le joueur passe sur l'item SpeedUp
        */
        void gestionSpeedUp(int i, bool trouve);
        /**
        *  \brief gestionScaleUp
        *  \author SINET Theo
        *  \param i : numéro de l'item
        *  \param trouve : booleen
        *  Permet de vérifier si le joueur passe sur l'item ScaleUp
        */
        void gestionScaleUp(int i, bool trouve);
        /**
        *  \brief conversion du deplacement de la flèche en entier
        *  \author SINET Theo
        *  \param direction : direction de la flèche
        *  \return la direction de la flèche
        *  Converti le déplacement de la flèche en int
        */
        int conversionDeplacementArrow(char direction);
        /**
        *  \brief conversion de la direction de la flèche en char
        *  \author SINET Theo
        *  \param direction : direction de la flèche
        *  \return la direction de la flèche
        *  Converti la direction de la flèche en char
        */
        char conversionDirectionArrow(char direction);
        /**
        *  \brief dégat de la bombe
        *  \author SINET Theo
        *  \param pos : position de la bombe
        *  \param bombe : la bombe
        *  Permet à la bombe d'infliger des dégats
        */
        void bombeInfligerDegats(int pos, Bombe* bombe);
        /**
        *  \brief mort par bombe
        *  \author SINET Theo
        *  \param position : position de l'entité
        *  vérifie si l'entité est mort par une bombe
        */
        void mortParBombe(int position);
        /**
        *  \brief changement de l'affichage du mur si des degats lui sont infligés
        *  \author SINET Theo
        *  \param position : position du mur
        *  changement de l'affichage du mur si des degats lui sont infligés
        */
        void degatMurs(int position);
        /**
        *  \brief savoir si on a gagné
        *  \author SINET Theo
        *  \return vrai si les conditions pour gagner sont remplis, sinon faux
        */
        bool gagner();

    public:
        /**
        *  \brief constructeur par défaut et initialisation
        *  \author SINET Theo
        *  \param map : map
        *  \param joueur : joueur
        *  \param mob : mob
        *  \param item : item
        *  \param nbMobMap : nombre de mob
        *  \param wall : wall
        *  Constructeur par défaut et initialisation du joueur
        */
        System(Map* map = new Map(), Joueur* joueur = new Joueur(), Mob** mob = new Mob*(), Item** item = new Item*(), int nbMobMap=0, Wall** wall=new Wall*());
        
    
        /**
        *  \brief afficherCarte
        *  \author DARVILLE Killian, SINET Theo
        *  permet d'appeler la fonction d'affichage de la map
        */
        void afficherCarte(int nbHP, int puissanceBombe, int nbBombMax, int speed, int portee);
        /**
        *  \brief demanderAction
        *  \author DARVILLE Killian, SINET Theo
        *  \return true si le joueur veux quitter la partie
        *  Demande au joueur dans quel direction il veux aller
        */
        bool demanderAction();
        /**
        *  \brief deplacerMonstres
        *  \author SINET Theo
        *  \param numMob : numéro du Mob qui va se daplacer
        *  Déplace les monstres
        */
        void deplacerMonstres(int numMob);
        /**
        *  \brief exploserBombe
        *  \author SINET Theo
        *  \param bombe : une bombe
        *  explose la bombe si le détonateur est à 0
        */
        void exploserBombe(Bombe* bombe);
        /**
        *  \brief enleverExplosionBombe
        *  \author DARVILLE Killian
        *  \param position : position de la bombe
        *  retire l'explose de la bombe
        */
        void enleverExplosionBombe(int position);
        /**
        *  \brief resetBomb
        *  \author SINET Theo
        *  \param bombe : bombe
        *  redonne une bombe au joueur
        */
        void resetBomb(Bombe* bombe);
        /**
        *  \brief actualiser la map
        *  \author DARVILLE Killian
        *  appelle la fonction pour actualiser le fichier map.txt
        */
        void actualiserCarte();
        /**
        *  \brief verifie si la futur position de l'entité est bonne
        *  \author DARVILLE Killian
        *  \param position : position de l'entité
        *  \param deplacement : deplacement de l'entité
        *  \param futurPosition : futurPosition de l'entité
        *  \param lettreJoueur : lettre de l'entité
        *  vérifie si l'entité peut se déplacer
        */
        bool verifFuturPosition(int position, char deplacement, int futurPosition, std::string lettreJoueur);
        /**
        *  \brief nombreMobMap
        *  \author SINET Theo
        *  \return le nombre de mob
        *  calcule le nombre de Mob sur la map
        */
        int nombreMobMap();
        /**
        *  \brief alloueMob
        *  \author SINET Theo
        *  créer le tableau de Mob
        */
        void alloueMob();
        /**
        *  \brief nombreItemMap
        *  \author SINET Theo
        *  \return le nombre d'item sur la map
        *  calcule le nombre d'item sur la map 
        */
        int nombreItemMap();
        /**
        *  \brief alloueItem
        *  \author SINET Theo
        *  créer le tableau d'item 
        */
        void alloueItem();
        /**
        *  \brief alloueBomb
        *  \author SINET Theo
        *  créer le tableau de bombe 
        */
        void alloueBomb();
        /**
        *  \brief lirePositionJoueur
        *  \author SINET Theo
        *  Lis la position du joueur sur la map 
        */
        void lirePositionJoueur();
        /**
        *  \brief jouer
        *  \author SINET Theo
        *  \param nomFichier le nom du fichier de la map
        *  Lance le jeu 
        */
        void jouer(std::string nomFichier);

        /**
        *  \brief getteur getMap
        *  \author SINET Theo
        *  \return la map
        *  retourne la map 
        */
        Map* getMap(){return map;}
        /**
        *  \brief getteur getMob
        *  \author SINET Theo
        *  \return le tableau de Mob
        *  retourne le tableau de Mob 
        */
        Mob** getMob(){return mob;}
        /**
        *  \brief getteur joueur
        *  \author SINET Theo
        *  \return le joueur
        *  retourne le joueur 
        */
        Joueur* getJoueur(){return joueur;}
        /**
        *  \brief getteur nbMobMap
        *  \author SINET Theo
        *  \return le nombre de Mob sur la map
        *  retourne le nombre de Mob sur la map 
        */
        int getNbMobMap(){return nbMobMap;}

        /**
        *  \brief setteur nbMobMap
        *  \author SINET Theo
        *  \param nbMobMap le nombre de Mob sur la map
        *  change le nombre de Mob sur la map 
        */
        void setNbMobMap(int nbMobMap){this->nbMobMap=nbMobMap;}
};


#endif