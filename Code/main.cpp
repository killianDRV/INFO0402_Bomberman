/**
 * \file main.cpp
 * \brief main du programme
 * \author DARVILLE Killian, SINET Theo
 * \version 0.1
 * \date 09 avril 2022
 */
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>

#include "System.h"
#include "Joueur.h"
#include "Bombe.h"
#include "Mob.h"
#include "Map.h"

/** \namespace std
 * espace de nommage
 */
using namespace std;
/** \namespace std::chrono_literals
 * espace de nommage (pour utiliser les sleep)
 */
using namespace std::chrono_literals;

/**
*  \brief menuGeneral
*  \author SINET Theo
*  \return le choix du joueur
*  Demande au joueur ce qu'il veux faire lorsque il lance le programme
*/
int menuGeneral()
{
    int choix=-1;

    while(choix < 0 || choix > 3)
    {
        cout << "Voici les actions possibles : " << endl;
        cout << "1. Jouer" << endl;
        cout << "2. Consulter les règles" << endl;
        cout << "3. Consulter la légende de la carte" << endl;
        cout << "0. Quitter" << endl;
        cout << "Que voulez-vous faire ? : ";
        cin >> choix;

        if(choix<0 || choix>3) {cout << "\n\nSaisissez un numéro correct" << endl;}
    }

    return choix;    
}

/**
*  \brief affichageRegles
*  \author SINET Theo
*  Ouvre le fichier regles.txt et les affiches
*/
void affichageRegles()
{
    ifstream fichier("regles.txt");

    cout << "\n\n\nVoici les règles du jeu :" << endl;

    if(fichier)
    {
        string ligne;
        while(getline(fichier, ligne))
        {
           cout << ligne << endl; 
        }
    }
    else
    {
        cout << "Impossible d'ouvrir regles.txt" << endl;
    }

    cout << "\n\n" << endl;
}

/**
*  \brief affichageRegles
*  \author DARVILLE Killian, SINET Theo
*  Affiche les règles
*/
void affichageLegende()
{
    cout << "\n\n\nVoici la légende de la carte :" << endl;
    cout << " P / 😀 Player" << endl;
    cout << " 0 / 💣 Bombe" << endl;
    cout << " @ / 💥 Bombe qui explose" << endl;
    cout << " M / 👹 Monster" << endl;
    cout << " B / 🏹 Bowman" << endl;
    cout << " G / 👻 Ghost" << endl;
    cout << "ML / 💖 MoreLife" << endl;
    cout << "PU / 🔥 PowerUp" << endl;
    cout << "MB / 🔮 MoreBombe" << endl;
    cout << "SP / 👟 SpeedUp" << endl;
    cout << "SC / 📏 ScaleUp" << endl;
    cout << "< Flèche gauche" << endl;
    cout << "> Flèche droite" << endl;
    cout << "A Flèche haut" << endl;
    cout << "V Flèche bas" << endl;
    cout << "X Objectif" << endl;
    cout << "\n\n" << endl;
}

    



/**
*  \brief main
*  \author DARVILLE Killian, SINET Theo
*  \return 0 pour quitter le programme
*  lance le programme
*/
int main()
{


    System sys;

    int choix=-1, emoji=-1;
    int tailleMap;
    string nomFichier;

    cout << "Bienvenue sur le BomberMan\n" << endl;

    while(choix!=0 && choix!=1)
    {
        choix = menuGeneral();

        switch(choix)
        {
            case 0:
                return 0;
                break;
            case 1:
                do
                {
                    cout << "\n\n\n";
                    cout << "Voulez-vous jouer avec la version emoji ?" << endl << "(😀💖💣 si vous ne voyez pas ces emojis, nous vous déconseillons cette version)" << endl << "1. Oui" << endl << "2. Non" << endl;
                    cout << "Votre choix : ";
                    cin >> emoji;
                }while(emoji != 1 && emoji != 2);   

                if(emoji == 1) {sys.getMap()->setEmoji(true);}

                do{
                    cout << "\nQuelle taille de map voulez-vous :" << endl << "1:Petite / 2:Moyenne / 3:Grande" << endl;
                    cin >> tailleMap;
                }while(tailleMap!=1 && tailleMap!=2 && tailleMap!=3);
                if(tailleMap==1)   nomFichier="map/mapPetite.txt";
                else if(tailleMap==2) nomFichier="map/mapMoyenne.txt";
                else  nomFichier="map/mapGrande.txt";

                cout << "\n\n\nLe jeu commence :" << endl;
                sys.jouer(nomFichier);
                break;
            case 2:
                affichageRegles();
                break;
            case 3: 
                affichageLegende();
                break;
            default:
                cout << "Choix invalide" << endl;
        }
    }


    return 0;
}


