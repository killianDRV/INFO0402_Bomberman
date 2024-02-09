#include <iostream>
#include "System.h"
#include <string>
#include <chrono>
#include <thread>


using namespace std;
using namespace std::chrono_literals;

System::System(Map* map, Joueur* joueur, Mob** mob, Item** item, int nbMobMap, Wall** wall): map(map), joueur(joueur), mob(mob), item(item), nbMobMap(nbMobMap), wall(wall){}


void System::afficherCarte(int nbHP, int puissanceBombe, int nbBombMax, int speed, int portee)
{
    map->affichageMap(joueur->getHP(), joueur->getBombe()->getPuissance(), joueur->getNbBombMax(), joueur->getSpeed(), joueur->getBombe()->getPortee());
}


int System::nombreMobMap()
{
    string* tab = map->getTab();
    int nbMob=0;
    for(int i=0; i<map->getNbCaractere(); i++)
    {
        if(tab[i].size()==1){
            if(tab[i]=="M" || tab[i]=="B" || tab[i]=="G"){
                nbMob++;
            }
        }else if(tab[i].size()==2){
            if(tab[i]=="WG" || tab[i]=="wG" || tab[i]=="@G" || tab[i]=="G@" || tab[i]=="0G" || tab[i]=="G0" || tab[i]=="0M" || tab[i]=="M0" || tab[i]=="B0" || tab[i]=="0B"){
                nbMob++;
            }
        }else if(tab[i].size()==3){
            if(tab[i]=="MLM" || tab[i]=="MLB" || tab[i]=="MLG"){
                nbMob++;
            }else if(tab[i]=="PUM" || tab[i]=="PUB" || tab[i]=="PUG"){
                nbMob++;
            }else if(tab[i]=="MBM" || tab[i]=="MBB" || tab[i]=="MBG"){
                nbMob++;
            }else if(tab[i]=="SPM" || tab[i]=="SPB" || tab[i]=="SPG"){
                nbMob++;
            }else if(tab[i]=="SCM" || tab[i]=="SCB" || tab[i]=="SCG"){
                nbMob++;
            }
        }
    }
    return nbMob;
}


void System::alloueMob()
{
    int nbMob = nombreMobMap();
    mob = new Mob*[nbMob];
    string* tab = map->getTab();
    int j=0;


    for(int i=0; i<map->getNbCaractere(); i++)
    {
        if(tab[i] == "M")
        {
            mob[j] = new Monster();
            mob[j]->setPosition(i);
        
            j++;
        }
        else if(tab[i]=="G" || tab[i]=="WG" || tab[i]=="wG")
        {
            mob[j] = new Ghost();
            mob[j]->setPosition(i);
            j++;
        }
        else if(tab[i]=="B")
        {

            mob[j] = new Bowman();
            mob[j]->setPosition(i);
            j++;
        }
        
    }
}



int System::nombreItemMap()
{
    string* tab = map->getTab();
    int nbItem=0;
    for(int i=0; i<map->getNbCaractere(); i++)
    {
        if(tab[i].size()==2){
            if(tab[i]=="ML" || tab[i]=="MB" || tab[i]=="SP" || tab[i]=="SC" || tab[i]=="PU"){
                nbItem++;
            }
        }
        else if(tab[i].size()==3){
            if(tab[i]=="MLP" || tab[i]=="MBP" || tab[i]=="SPP" || tab[i]=="SCP" || tab[i]=="PUP")
            {
                nbItem++;
            }
            else if(tab[i]=="MLG" || tab[i]=="MLM" || tab[i]=="MLB" || tab[i]=="MBG" || tab[i]=="MBM" || tab[i]=="MBB" || tab[i]=="PUG" || tab[i]=="PUM" || tab[i]=="PUB" || tab[i]=="SPG" || tab[i]=="SPM" || tab[i]=="SPB" || tab[i]=="SCG" || tab[i]=="SCM" || tab[i]=="SCB")
            {
                nbItem++;
            }
        }
        else if(tab[i].size()==4){
            if(tab[i]=="MLGP" || tab[i]=="MLPG" || tab[i]=="MLBP" || tab[i]=="MLPB" || tab[i]=="MLMP" || tab[i]=="MLPM" || tab[i]=="PUGP" || tab[i]=="PUPG" || tab[i]=="PUMP" || tab[i]=="PUPM" || tab[i]=="MBGP" || tab[i]=="MBPG" || tab[i]=="MBBP" || tab[i]=="MBPB" || tab[i]=="MBMP" || tab[i]=="MBPM" || tab[i]=="SPGP" || tab[i]=="SPPG" || tab[i]=="SPBP" || tab[i]=="SPPB" || tab[i]=="SPMP" || tab[i]=="SPPM" || tab[i]=="SCGP" || tab[i]=="SCPG" || tab[i]=="SCBP" || tab[i]=="SCPB" || tab[i]=="SCMP" || tab[i]=="SCPM"){
                nbItem++;
            }
            else if(tab[i]=="ML<P" || tab[i]=="ML>P" || tab[i]=="MLAP" || tab[i]=="MLVP" || tab[i]=="MLP<" || tab[i]=="MLP>" || tab[i]=="MLPA" || tab[i]=="MLPV" || tab[i]=="PU<P" || tab[i]=="PU>P" || tab[i]=="PUAP" || tab[i]=="PUVP" || tab[i]=="PUP<" || tab[i]=="PUP>" || tab[i]=="PUPA" || tab[i]=="PUPV" || tab[i]=="MB<P" || tab[i]=="MB>P" || tab[i]=="MBAP" || tab[i]=="MBVP" || tab[i]=="MBP<" || tab[i]=="MBP>" || tab[i]=="MBPA" || tab[i]=="MBPV" || tab[i]=="SP<P" || tab[i]=="SP>P" || tab[i]=="SPAP" || tab[i]=="SPVP" || tab[i]=="SPP<" || tab[i]=="SPP>" || tab[i]=="SPPA" || tab[i]=="SPPV" || tab[i]=="SC<P" || tab[i]=="SC>P" || tab[i]=="SCAP" || tab[i]=="SCVP" || tab[i]=="SCP<" || tab[i]=="SCP>" || tab[i]=="SCPA" || tab[i]=="SCPV"){
                nbItem++;
            }
        }
    }
    return nbItem;
}


void System::alloueItem()
{
    int nbItem = nombreItemMap();
    item = new Item*[nbItem];
    string* tab = map->getTab();
    int j=0;

    for(int i=0; i<map->getNbCaractere(); i++)
    {
        if(tab[i] == "ML")
        {   
            item[j] = new MoreLife();
            item[j]->setPosition(i);
            j++;
        }
        else if(tab[i]=="MB")
        {
            item[j] = new MoreBomb();
            item[j]->setPosition(i);
            j++;
        }
        else if(tab[i]=="SP")
        {
            item[j] = new SpeedUp();
            item[j]->setPosition(i);
            j++;
        }
        else if(tab[i]=="SC")
        {
            item[j] = new ScaleUp();
            item[j]->setPosition(i);
            j++;
        }
        else if(tab[i]=="PU")
        {
            item[j] = new PowerUp();
            item[j]->setPosition(i);
            j++;
        }
    }

}



void System::alloueBomb()
{
    joueur->setNbBombRestante(joueur->getNbBombMax());
    joueur->setBombe(new Bombe[joueur->getNbBombMax()]);
}


void System::lirePositionJoueur()
{
    string* tab = map->getTab();

    for(int i=0; i<map->getNbCaractere(); i++)
    {
        if(tab[i] == "P")
        {
            joueur->setPosition(i);
        }
    }
}




bool System::demanderAction()
{
    string action;
    string* tab = map->getTab();

    bool verif;
    int positionJoueur =  joueur->getPosition();
    bool quitter = false;

    do
    {
        do
        {
            cout << "Choisissez votre action : " << endl;
            cout << "     z" << endl << "   q s d" << endl << "b pour poser une bombe         " << "x pour quitter le jeu" << endl;
            cout << "Que voulez-vous faire ? : ";
            cin >> action;
        }while(action[0]!='z' && action[0]!='q' && action[0]!='s' && action[0]!='d' && action[0]!='b' && action[0]!='x');


        if(action[0]=='x')
        {
            quitter = true;
        }
        else
        {
            if(action[0]=='b')
            {
                if(joueur->getNbBombRestante()!=0)
                {
                    joueur->poserBombe();
                    map->afficherPersoObjet(joueur->getPosition(), '0'); 
                    afficherCarte(joueur->getHP(), joueur->getBombe()->getPuissance(), joueur->getNbBombMax(), joueur->getSpeed(), joueur->getBombe()->getPortee());
                    
                    
                    do
                    {
                        cout << "Vous avez posé une bombe, choisissez votre déplacement : " << endl;
                        cout << "     z" << endl << "   q s d" << endl;
                        cout << "Que voulez-vous faire ? : ";
                        cin >> action;
                    }while(action[0]!='z' && action[0]!='q' && action[0]!='s' && action[0]!='d');
                }
                else
                {
                    cout << "\n\nVous n'avez plus de bombe\n" << endl;
                    verif = false;
                }
            }


            joueur->seDeplacer(action[0], map->getNbColonne());
        
            // position joueur n'ayant pas été mise a jour, elle correspond a l'ancienne et getPosition donne donc la nouvelle
            verif = verifFuturPosition(positionJoueur, action[0], joueur->getPosition(), tab[positionJoueur]); 
            if(verif==false)
            {
                cout << "Impossible, quelque chose vous bloque !\n\n" << endl;
                joueur->setPosition(positionJoueur);
            }
            else
            {
                map->gestionDeplacementMap(positionJoueur, (joueur->getPosition()-positionJoueur));
                joueurItemFlecheMonstre(joueur->getPosition());
            }
                
        } 
    }while(!verif && !quitter);
        
    return quitter;    
}



void System::deplacerMonstres(int numMob)
{
    bool verif;
    char action;
    int deplacement;
    int positionMob;
    bool tire;
    string* tab = map->getTab();

 
    positionMob = mob[numMob]->getPosition();

    if(mob[numMob]->getTourAttente()==0 && mob[numMob]->getHP()>0) // le mob peut se deplacer ou attaquer s'il n'a pas attaquer le joueur récemment
    {
        if(joueur->getPosition() != positionMob)
        {
            mob[numMob]->seDeplacer(joueur->getPosition(), map->getNbLigne(), map->getNbColonne());
            
            // petite partie pour savoir dans quelle direction se deplace le mob pour simplifier la gestion sur la map
            deplacement = mob[numMob]->getPosition()-positionMob;
            if(deplacement == -(map->getNbColonne())) {action = 'z';}
            else if(deplacement == map->getNbColonne()) {action = 's';}
            else if(deplacement == -1){action = 'q';}
            else if(deplacement == 1){action = 'd';}


            // Vérifie si le mob peut vraiment se deplacer sinon on le remet à sa place d'origine
            verif = verifFuturPosition(positionMob, action, mob[numMob]->getPosition(), tab[positionMob]); 
            if(verif==false)
            {
                mob[numMob]->setPosition(positionMob);
            }
            else
            {
                map->gestionDeplacementMap(positionMob, (mob[numMob]->getPosition()-positionMob));// prise en compte du deplacement dans le tableau de la map
                joueurItemFlecheMonstre(mob[numMob]->getPosition());
            }
        }
        


        // si le mob est sur la case du joueur, il l'attaque
        if(mob[numMob]->getPosition() == joueur->getPosition())
        {
            joueur->setHP(mob[numMob]->attaquer(joueur->getHP()));
            mob[numMob]->setTourAttente(3);
        }
        else if(mob[numMob]->isBowman())
        {
            if(mob[numMob]->getArrow()->getTouche())
            {
                mob[numMob]->getArrow()->setTouche(false);
                mob[numMob]->setNbFleche(mob[numMob]->getNbFleche()+1);
            }
            
            if(mob[numMob]->getNbFleche()>0)
                tire = mob[numMob]->peutTirer(joueur->getPosition(), tab, map->getNbLigne(), map->getNbColonne());
            if(tire && (mob[numMob]->getNbFleche()>0))
            {
                map->afficherPersoObjet(mob[numMob]->getArrow()->getPosition(), mob[numMob]->tirer(joueur->getPosition(), tab, map->getNbLigne(), map->getNbColonne()));
                mob[numMob]->setNbFleche(mob[numMob]->getNbFleche()-1);
                joueurItemFlecheMonstre(mob[numMob]->getArrow()->getPosition());
            }
        }
    }
    else
    {
        mob[numMob]->setTourAttente(mob[numMob]->getTourAttente()-1);
    }    
}





void System::joueurItemFlecheMonstre(int pos){

    string* tab = map->getTab();
    string tmp;
    int i=0;
    bool trouve=false;
    bool mort = false;
    int nbItem = nombreItemMap();
    
    while(i<nbItem && !trouve)
    {
        if(joueur->getPosition() == item[i]->getPosition())
        {
            trouve=true;
        }
        else
            i++;
    }
    


    // ============================================Joueur ramasse Item============================================
    if(tab[pos]=="MLP"){
        // joueur MoreLife
        gestionMoreLife(i, trouve);
        tab[pos]="P";
    }else if(tab[pos]=="PUP"){
        // joueur PowerUp
        gestionPowerUp(i, trouve);
        tab[pos]='P';
    }else if(tab[pos]=="MBP"){
        // joueur MoreBomb
        gestionMoreBomb(i, trouve);
        tab[pos]="P";
    }else if(tab[pos]=="SPP"){
        // joueur SpeedUp
        gestionSpeedUp(i, trouve);
        tab[pos]="P";
    }else if(tab[pos]=="SCP"){
        // joueur ScaleUp
        gestionScaleUp(i, trouve);
        tab[pos]='P';
    }


    // ========================================Entité touché par une fleche========================================
    else if(tab[pos]=="<P" || tab[pos]=="P<" || tab[pos]==">P" || tab[pos]=="P>" || tab[pos]=="AP" || tab[pos]=="PA" || tab[pos]=="VP" || tab[pos]=="PV"){
        tab[pos]='P';
        gestionFlecheJoueur(pos);
        if(joueurMort()) {
            tab[pos]=' ';
            exit(EXIT_SUCCESS);
        }
        // joueur perd de la vie car toucher par fleche
    }else if(tab[pos]=="<B" || tab[pos]=="B<" || tab[pos]==">B" || tab[pos]=="B>" || tab[pos]=="AB" || tab[pos]=="BA" || tab[pos]=="VB" || tab[pos]=="BV"){
        tab[pos]='B';
        gestionFlecheMob(pos);
        if(mobMort()) {tab[pos]=' ';}
        // Bowman perd de la vie car toucher par fleche
    }else if(tab[pos]=="<M" || tab[pos]=="M<" || tab[pos]==">M" || tab[pos]=="M>" || tab[pos]=="AM" || tab[pos]=="MA" || tab[pos]=="VM" || tab[pos]=="MV"){
        tab[pos]='M';
        gestionFlecheMob(pos);
        if(mobMort()) {tab[pos]=' ';}
        // Monstre perd de la vie car toucher par fleche
    }else if(tab[pos]=="<G" || tab[pos]=="G<" || tab[pos]==">G" || tab[pos]=="G>" || tab[pos]=="AG" || tab[pos]=="GA" || tab[pos]=="VG" || tab[pos]=="GV"){
        tab[pos]='G';
        gestionFlecheMob(pos);
        if(mobMort()) {tab[pos]=' ';}
        // Ghost perd de la vie car toucher par fleche
    }


    // ===================================Bowman touché par une fleche avec item==================================
    else if(tab[pos]=="PUVB" || tab[pos]=="PUBV" || tab[pos]=="PUAB" || tab[pos]=="PUBA" || tab[pos]=="PU<B" || tab[pos]=="PUB<" || tab[pos]=="PU>B" || tab[pos]=="PUB>"){
        tab[pos]="PUB";
        gestionFlecheMob(pos);
        if(mobMort()) {tab[pos]="PU";}
        // Bowman perd de la vie car toucher par fleche
    }else if(tab[pos]=="MLVB" || tab[pos]=="MLBV" || tab[pos]=="MLAB" || tab[pos]=="MLBA" || tab[pos]=="ML<B" || tab[pos]=="MLB<" || tab[pos]=="ML>B" || tab[pos]=="MLB>"){
        tab[pos]="MLB";
        gestionFlecheMob(pos);
        if(mobMort()) {tab[pos]="ML";}
        // Bowman perd de la vie car toucher par fleche
    }else if(tab[pos]=="MBVB" || tab[pos]=="MBBV" || tab[pos]=="MBAB" || tab[pos]=="MBBA" || tab[pos]=="MB<B" || tab[pos]=="MBB<" || tab[pos]=="MB>B" || tab[pos]=="MBB>"){
        tab[pos]="MBB";
        gestionFlecheMob(pos);
        if(mobMort()) {tab[pos]="MB";}
        // Bowman perd de la vie car toucher par fleche
    }else if(tab[pos]=="SCVB" || tab[pos]=="SCBV" || tab[pos]=="SCAB" || tab[pos]=="SCBA" || tab[pos]=="SC<B" || tab[pos]=="SCB<" || tab[pos]=="SC>B" || tab[pos]=="SCB>"){
        tab[pos]="SCB";
        gestionFlecheMob(pos);
        if(mobMort()) {tab[pos]="SC";}
        // Bowman perd de la vie car toucher par fleche
    }else if(tab[pos]=="SPVB" || tab[pos]=="SPBV" || tab[pos]=="SPAB" || tab[pos]=="SPBA" || tab[pos]=="SP<B" || tab[pos]=="SPB<" || tab[pos]=="SP>B" || tab[pos]=="SPB>"){
        tab[pos]="SPB";
        gestionFlecheMob(pos);
        if(mobMort()) {tab[pos]="SP";}
        // Bowman perd de la vie car toucher par fleche
    }

    // ===================================Ghost touché par une fleche avec item==================================
    else if(tab[pos]=="PUVG" || tab[pos]=="PUGV" || tab[pos]=="PUAG" || tab[pos]=="PUGA" || tab[pos]=="PU<G" || tab[pos]=="PUG<" || tab[pos]=="PU>G" || tab[pos]=="PUG>"){
        tab[pos]="PUG";
        gestionFlecheMob(pos);
        if(mobMort()) {tab[pos]="PU";}
        // Ghost perd de la vie car toucher par fleche
    }else if(tab[pos]=="MLVG" || tab[pos]=="MLGV" || tab[pos]=="MLAG" || tab[pos]=="MLGA" || tab[pos]=="ML<G" || tab[pos]=="MLG<" || tab[pos]=="ML>G" || tab[pos]=="MLG>"){
        tab[pos]="MLG";
        gestionFlecheMob(pos);
        if(mobMort()) {tab[pos]="ML";}
        // Ghost perd de la vie car toucher par fleche
    }else if(tab[pos]=="MBVG" || tab[pos]=="MBGV" || tab[pos]=="MBAG" || tab[pos]=="MBGA" || tab[pos]=="MB<G" || tab[pos]=="MBG<" || tab[pos]=="MB>G" || tab[pos]=="MBG>"){
        tab[pos]="MBG";
        gestionFlecheMob(pos);
        if(mobMort()) {tab[pos]="MB";}
        // Ghost perd de la vie car toucher par fleche
    }else if(tab[pos]=="SCVG" || tab[pos]=="SCGV" || tab[pos]=="SCAG" || tab[pos]=="SCGA" || tab[pos]=="SC<G" || tab[pos]=="SCG<" || tab[pos]=="SC>G" || tab[pos]=="SCG>"){
        tab[pos]="SCG";
        gestionFlecheMob(pos);
        if(mobMort()) {tab[pos]="SC";}
        // Ghost perd de la vie car toucher par fleche
    }else if(tab[pos]=="SPVG" || tab[pos]=="SPGV" || tab[pos]=="SPAG" || tab[pos]=="SPGA" || tab[pos]=="SP<G" || tab[pos]=="SPG<" || tab[pos]=="SP>G" || tab[pos]=="SPG>"){
        tab[pos]="SPG";
        gestionFlecheMob(pos);
        if(mobMort()) {tab[pos]="SP";}
        // Ghost perd de la vie car toucher par fleche
    }


    // ===================================Monstre touché par une fleche avec item==================================
    else if(tab[pos]=="PUVM" || tab[pos]=="PUMV" || tab[pos]=="PUAM" || tab[pos]=="PUMA" || tab[pos]=="PU<M" || tab[pos]=="PUM<" || tab[pos]=="PU>M" || tab[pos]=="PUM>"){
        tab[pos]="PUM";
        gestionFlecheMob(pos);
        if(mobMort()) {tab[pos]="PU";}
        // Monstre perd de la vie car toucher par fleche
    }else if(tab[pos]=="MLVM" || tab[pos]=="MLMV" || tab[pos]=="MLAM" || tab[pos]=="MLMA" || tab[pos]=="ML<M" || tab[pos]=="MLM<" || tab[pos]=="ML>M" || tab[pos]=="MLM>"){
        tab[pos]="MLM";
        gestionFlecheMob(pos);
        if(mobMort()) {tab[pos]="ML";}
        // Monstre perd de la vie car toucher par fleche
    }else if(tab[pos]=="MBVM" || tab[pos]=="MBMV" || tab[pos]=="MBAM" || tab[pos]=="MBMA" || tab[pos]=="MB<M" || tab[pos]=="MBM<" || tab[pos]=="MB>M" || tab[pos]=="MBM>"){
        tab[pos]="MBM";
        gestionFlecheMob(pos);
        if(mobMort()) {tab[pos]="MB";}
        // Monstre perd de la vie car toucher par fleche
    }else if(tab[pos]=="SCVM" || tab[pos]=="SCMV" || tab[pos]=="SCAM" || tab[pos]=="SCMA" || tab[pos]=="SC<M" || tab[pos]=="SCM<" || tab[pos]=="SC>M" || tab[pos]=="SCM>"){
        tab[pos]="SCM";
        gestionFlecheMob(pos);
        if(mobMort()) {tab[pos]="SC";}
        // Monstre perd de la vie car toucher par fleche
    }else if(tab[pos]=="SPVM" || tab[pos]=="SPMV" || tab[pos]=="SPAM" || tab[pos]=="SPMA" || tab[pos]=="SP<M" || tab[pos]=="SPM<" || tab[pos]=="SP>M" || tab[pos]=="SPM>"){
        tab[pos]="SPM";
        gestionFlecheMob(pos);
        if(mobMort()) {tab[pos]="SP";}
        // Monstre perd de la vie car toucher par fleche
    }
    
    // ===========================Joueur prend Item MoreLife + touché par un Monstre/Ghost/Bowman===========================
    else if(tab[pos]=="MLGP" || tab[pos]=="MLPG"){
        // joueur MoreLife +1
        // Joueur perd de la vie car touché par Ghost
        gestionMoreLife(i, trouve);
        tab[pos]="GP";
        if(joueurMort()) {
            tab[pos]='G';
            exit(EXIT_SUCCESS);
        }
    }else if(tab[pos]=="MLBP" || tab[pos]=="MLPB"){
        // joueur MoreLife +1
        // Joueur perd de la vie car touché par Bowman
        gestionMoreLife(i, trouve);
        tab[pos]="BP";
        if(joueurMort()) {
            tab[pos]='B';
            exit(EXIT_SUCCESS);
        }
    }else if(tab[pos]=="MLMP" || tab[pos]=="MLPM"){
        // joueur MoreLife +1
        // Joueur perd de la vie car touché par Monstre
        gestionMoreLife(i, trouve);
        tab[pos]="MP";
        if(joueurMort()) {
            tab[pos]='M';
            exit(EXIT_SUCCESS);
        }
    }

    // ===========================Joueur prend Item PowerUp + touché par un Monstre/Ghost/Bowman===========================
    else if(tab[pos]=="PUGP" || tab[pos]=="PUPG"){
        // joueur PowerUp +1
        // Joueur perd de la vie car touché par Ghost
        gestionPowerUp(i, trouve);
        tab[pos]="GP";
        if(joueurMort()) {
            tab[pos]='G';
            exit(EXIT_SUCCESS);
        }
    }else if(tab[pos]=="PUBP" || tab[pos]=="PUPB"){
        // joueur PowerUp +1
        // Joueur perd de la vie car touché par Bowman
        gestionPowerUp(i, trouve);
        tab[pos]="BP";
        if(joueurMort()) {
            tab[pos]='B';
            exit(EXIT_SUCCESS);
        }
    }else if(tab[pos]=="PUMP" || tab[pos]=="PUPM"){
        // joueur PowerUp +1
        // Joueur perd de la vie car touché par Monstre
        gestionPowerUp(i, trouve);
        tab[pos]="MP";
        if(joueurMort()) {
            tab[pos]='M';
            exit(EXIT_SUCCESS);
        }
    }

    // ===========================Joueur prend Item MoreBombe + touché par un Monstre/Ghost/Bowman===========================
    else if(tab[pos]=="MBGP" || tab[pos]=="MBPG"){
        // joueur MoreBombe +1
        // Joueur perd de la vie car touché par Ghost
        gestionMoreBomb(i, trouve);
        tab[pos]="GP";
        if(joueurMort()) {
            tab[pos]='G';
            exit(EXIT_SUCCESS);
        }
    }else if(tab[pos]=="MBBP" || tab[pos]=="MBPB"){
        // joueur MoreBombe +1
        // Joueur perd de la vie car touché par Bowman
        gestionMoreBomb(i, trouve);
        tab[pos]="BP";
        if(joueurMort()) {
            tab[pos]='B';
            exit(EXIT_SUCCESS);
        }
    }else if(tab[pos]=="MBMP" || tab[pos]=="MBPM"){
        // joueur MoreBombe +1
        // Joueur perd de la vie car touché par Monstre
        gestionMoreBomb(i, trouve);
        tab[pos]="MP";
        if(joueurMort()) {
            tab[pos]='M';
            exit(EXIT_SUCCESS);
        }
    }

    // ===========================Joueur prend Item SpeedUp + touché par un Monstre/Ghost/Bowman===========================
    else if(tab[pos]=="SPGP" || tab[pos]=="SPPG"){
        // joueur SpeedUp +1
        // Joueur perd de la vie car touché par Ghost
        gestionSpeedUp(i, trouve);
        tab[pos]="GP";
        if(joueurMort()) {
            tab[pos]='G';
            exit(EXIT_SUCCESS);
        }
    }else if(tab[pos]=="SPBP" || tab[pos]=="SPPB"){
        // joueur SpeedUp +1
        // Joueur perd de la vie car touché par Bowman
        gestionSpeedUp(i, trouve);
        tab[pos]="BP";
        if(joueurMort()) {
            tab[pos]='B';
            exit(EXIT_SUCCESS);
        }
    }else if(tab[pos]=="SPMP" || tab[pos]=="SPPM"){
        // joueur SpeedUp +1
        // Joueur perd de la vie car touché par Monstre
        gestionSpeedUp(i, trouve);
        tab[pos]="MP";
        if(joueurMort()) {
            tab[pos]='M';
            exit(EXIT_SUCCESS);
        }
    }

    // ===========================Joueur prend Item ScaleUp + touché par un Monstre/Ghost/Bowman===========================
    else if(tab[pos]=="SCGP" || tab[pos]=="SCPG"){
        // joueur ScaleUp +1
        // Joueur perd de la vie car touché par Ghost
        gestionScaleUp(i, trouve);
        tab[pos]="GP";
        if(joueurMort()) {
            tab[pos]='G';
            exit(EXIT_SUCCESS);
        }
    }else if(tab[pos]=="SCBP" || tab[pos]=="SCPB"){
        // joueur ScaleUp +1
        // Joueur perd de la vie car touché par Bowman
        gestionScaleUp(i, trouve);
        tab[pos]="BP";
        if(joueurMort()) {
            tab[pos]='B';
            exit(EXIT_SUCCESS);
        }
    }else if(tab[pos]=="SCMP" || tab[pos]=="SCPM"){
        // joueur ScaleUp +1
        // Joueur perd de la vie car touché par Monstre
        gestionScaleUp(i, trouve);
        tab[pos]="MP";
        if(joueurMort()) {
            tab[pos]='M';
            exit(EXIT_SUCCESS);
        }
    }
    

    // ===========================Joueur prend Item MoreLife + touché par une fleche===========================
    else if(tab[pos]=="ML<P" || tab[pos]=="ML>P" || tab[pos]=="MLAP" || tab[pos]=="MLVP" || tab[pos]=="MLP<" || tab[pos]=="MLP>" || tab[pos]=="MLPA" || tab[pos]=="MLPV"){
        // joueur MoreLife +1
        // Joueur perd de la vie car touché une fleche
        gestionMoreLife(i, trouve);
        tab[pos]="P";
        gestionFlecheJoueur(pos);
        if(joueurMort()) {
            tab[pos]=' ';
            exit(EXIT_SUCCESS);
        }
    }else if(tab[pos]=="PU<P" || tab[pos]=="PU>P" || tab[pos]=="PUAP" || tab[pos]=="PUVP" || tab[pos]=="PUP<" || tab[pos]=="PUP>" || tab[pos]=="PUPA" || tab[pos]=="PUPV"){
        // joueur PowerUp +1
        // Joueur perd de la vie car touché une fleche
        gestionPowerUp(i, trouve);
        tab[pos]="P";
        gestionFlecheJoueur(pos);
        if(joueurMort()) {
            tab[pos]=' ';
            exit(EXIT_SUCCESS);
        }
    }else if(tab[pos]=="MB<P" || tab[pos]=="MB>P" || tab[pos]=="MBAP" || tab[pos]=="MBVP" || tab[pos]=="MBP<" || tab[pos]=="MBP>" || tab[pos]=="MBPA" || tab[pos]=="MBPV"){
        // joueur MoreBombe +1
        // Joueur perd de la vie car touché une fleche
        gestionMoreBomb(i, trouve);
        tab[pos]="P";
        gestionFlecheJoueur(pos);
        if(joueurMort()) {
            tab[pos]=' ';
            exit(EXIT_SUCCESS);
        }
    }else if(tab[pos]=="SP<P" || tab[pos]=="SP>P" || tab[pos]=="SPAP" || tab[pos]=="SPVP" || tab[pos]=="SPP<" || tab[pos]=="SPP>" || tab[pos]=="SPPA" || tab[pos]=="SPPV"){
        // joueur SpeedUp +1
        // Joueur perd de la vie car touché une fleche
        gestionSpeedUp(i, trouve);
        tab[pos]="P";
        gestionFlecheJoueur(pos);
        if(joueurMort()) {
            tab[pos]=' ';
            exit(EXIT_SUCCESS);
        }
    }else if(tab[pos]=="SC<P" || tab[pos]=="SC>P" || tab[pos]=="SCAP" || tab[pos]=="SCVP" || tab[pos]=="SCP<" || tab[pos]=="SCP>" || tab[pos]=="SCPA" || tab[pos]=="SCPV"){
        // joueur ScaleUp +1
        // Joueur perd de la vie car touché une fleche
        gestionScaleUp(i, trouve);
        tab[pos]="P";
        gestionFlecheJoueur(pos);
        if(joueurMort()) {
            tab[pos]=' ';
            exit(EXIT_SUCCESS);
        }
    }

    // ===================================Ghost touché par une fleche avec bombe==================================
    else if(tab[pos]=="0>G" || tab[pos]=="0<G" || tab[pos]=="0AG" || tab[pos]=="0VG"){
        tab[pos]="0G";
        gestionFlecheMob(pos);
        if(mobMort()) {tab[pos]="0";}
        // Ghost perd de la vie car toucher par fleche
    }
    
    // ===========================Joueur touché par un Monstre/Ghost/Bowman===========================
    else if(tab[pos]=="PG" || tab[pos]=="GP"){
        // joueur perd de la vie car touché par Ghost
        if(joueurMort()) {
            tab[pos]='G';
            exit(EXIT_SUCCESS);
        }
    }else if(tab[pos]=="PM" || tab[pos]=="MP"){
        // joueur perd de la vie car touché par Monstre
        if(joueurMort()) {
            tab[pos]='M';
            exit(EXIT_SUCCESS);
        }
    }else if(tab[pos]=="PB" || tab[pos]=="BP"){
        // joueur perd de la vie car touché par Bowman
        if(joueurMort()) {
            tab[pos]='B';
            exit(EXIT_SUCCESS);
        }
    }
    

    // ===========================Flèche touche une Entité + bombe===========================
    else if(tab[pos]=="0G>" || tab[pos]=="0G<" || tab[pos]=="0GA" || tab[pos]=="0GV" || tab[pos]=="G0>" || tab[pos]=="G0<" || tab[pos]=="G0A" || tab[pos]=="G0V"){
        tab[pos]="0G";
        if(mobMort()) {
            tab[pos]="0";
            exit(EXIT_SUCCESS);
        }
        // Ghost perd de la vie car touché par une flèche
    }else if(tab[pos]=="0M>" || tab[pos]=="0M<" || tab[pos]=="0MA" || tab[pos]=="0MV" || tab[pos]=="M0>" || tab[pos]=="M0<" || tab[pos]=="M0A" || tab[pos]=="M0V"){
        tab[pos]="0M";
        if(mobMort()) {
            tab[pos]="0";
            exit(EXIT_SUCCESS);
        }
        // Monstre perd de la vie car touché par une flèche
    }else if(tab[pos]=="0B>" || tab[pos]=="0B<" || tab[pos]=="0BA" || tab[pos]=="0BV" || tab[pos]=="B0>" || tab[pos]=="B0<" || tab[pos]=="B0A" || tab[pos]=="B0V"){
        tab[pos]="0B";
        if(mobMort()) {
            tab[pos]="0";
            exit(EXIT_SUCCESS);
        }
        // Bowman perd de la vie car touché par une flèche
    }

    // ===========================Flèche touche une Flèche===========================
    else if(tab[pos]=="AA" || tab[pos]=="AV" || tab[pos]=="A<" || tab[pos]=="A>" || tab[pos]=="VA" || tab[pos]=="VV" || tab[pos]=="V<" || tab[pos]=="V>" || tab[pos]=="<A" || tab[pos]=="<V" || tab[pos]=="<<" || tab[pos]=="<>" || tab[pos]==">A" || tab[pos]==">V" || tab[pos]=="><" || tab[pos]==">>"){
        tab[pos]=tab[pos][1];
        // La flèche qui arrive en deuxième CASSE la premiere fleche
    }

    // ===========================Retirer fleche qui rentre dans un mur===========================
    else if(tab[pos]=="wA" || tab[pos]=="WA" || tab[pos]=="wV" || tab[pos]=="WV" || tab[pos]=="w<" || tab[pos]=="W<" || tab[pos]=="w>" || tab[pos]=="W>"){
        tab[pos]=tab[pos][0];
        // La flèche se casse car touche un mur
    }else if(tab[pos]=="wGA" || tab[pos]=="WGA" || tab[pos]=="wGV" || tab[pos]=="WGV" || tab[pos]=="wG<" || tab[pos]=="WG<" || tab[pos]=="wG>" || tab[pos]=="WG>"){
        tmp=tab[pos][0];
        tmp+=tab[pos][1];
        tab[pos]=tmp;
        // La flèche se casse car touche un mur
    }
    else if(tab[pos]=="XAP" || tab[pos]=="XVP" || tab[pos]=="X<P" || tab[pos]=="X>P"){
        tab[pos]="XP";
        gestionFlecheJoueur(pos);
        if(joueurMort()) {
            tab[pos]='X';
            exit(EXIT_SUCCESS);
        }
        // joueur perd de la vie car toucher par fleche
    }else if(tab[pos]=="XAG" || tab[pos]=="XVG" || tab[pos]=="X<G" || tab[pos]=="X>G"){
        tab[pos]="XG";
        gestionFlecheJoueur(pos);
        if(mobMort()) {
            tab[pos]='X';
            exit(EXIT_SUCCESS);
        }
        // Ghost perd de la vie car toucher par fleche
    }else if(tab[pos]=="XAB" || tab[pos]=="XVB" || tab[pos]=="X<B" || tab[pos]=="X>B"){
        tab[pos]="XB";
        gestionFlecheJoueur(pos);
        if(mobMort()) {
            tab[pos]='X';
            exit(EXIT_SUCCESS);
        }
        // Bowman perd de la vie car toucher par fleche
    }else if(tab[pos]=="XAM" || tab[pos]=="XVM" || tab[pos]=="X<M" || tab[pos]=="X>M"){
        tab[pos]="XM";
        gestionFlecheJoueur(pos);
        if(mobMort()) {
            tab[pos]='X';
            exit(EXIT_SUCCESS);
        }
        // Monstre perd de la vie car toucher par fleche
    }
}

bool System::joueurMort()
{
    int i;
    bool mort = false;
   
    if(joueur->getHP()==0)
    {
        mort=true;
    }
    return mort;
}


bool System::mobMort()
{
    int i;
    bool mort = false;
    for(i=0; i<nbMobMap; i++)
    {
            if(mob[i]->getHP()==0 && !mob[i]->getMort())
            {
                mort = true;
                mob[i]->setMort(true);
            }
    }
    return mort;
}



void System::gestionFlecheJoueur(int pos)
{
    int i;

    if(joueur->getPosition() == pos)
    {
        for(i=0; i<nombreMobMap(); i++)
        {
            if(mob[i]->isBowman() && (mob[i]->getArrow()->getPosition() == pos))
            {
                joueur->setHP(joueur->getHP()-mob[i]->getArrow()->getDegat());
                mob[i]->getArrow()->setTouche(true);
                mob[i]->getArrow()->setPosition(-1);
                mob[i]->setTourAttente(3);
                
                if(joueur->getHP()==0){joueur->setPosition(-1);}
            }
        }
    }
}




void System::gestionFlecheMob(int pos)
{
    int i, j=0;
    for(i=0; i<nbMobMap; i++)
    {
        if(mob[i]->getPosition() == pos)
        {
            while(j<nbMobMap)
            {
                if(mob[j]->isBowman() && (mob[j]->getArrow()->getPosition() == pos))
                {
                    mob[i]->setHP(mob[i]->getHP()-mob[j]->getArrow()->getDegat());
                    mob[j]->getArrow()->setTouche(true);
                    mob[j]->getArrow()->setPosition(-1);
                    mob[j]->setTourAttente(3);

                    if(mob[i]->getHP()==0){mob[i]->setPosition(-1);}
                }
                j++;
            }
        }
        j=0;
    }
}


void System::gestionMoreLife(int i, bool trouve)
{

    if(!trouve)
    {
        if(joueur->getPosition() == item[i]->getPosition())
        {
            trouve=true;
        }
    }
    if(trouve)
    {
        item[i]->ajouterVie(joueur);
    }
}



void System::gestionMoreBomb(int i, bool trouve)
{
    if(!trouve)
    {
        if(joueur->getPosition() == item[i]->getPosition())
        {
            trouve=true;
        }
    }
    if(trouve)
    {
        item[i]->ajouterBombe(joueur);
    }
}



void System::gestionPowerUp(int i, bool trouve)
{
    if(!trouve)
    {
        if(joueur->getPosition() == item[i]->getPosition())
        {
            trouve=true;
        }
    }
    if(trouve)
    {
        item[i]->augmenterPuissance(joueur);
    }
}



void System::gestionSpeedUp(int i, bool trouve)
{
    if(!trouve)
    {
        if(joueur->getPosition() == item[i]->getPosition())
        {
            trouve=true;
        }
    }
    if(trouve)
    {
        item[i]->augmenterVitesse(joueur);
    }
}



void System::gestionScaleUp(int i, bool trouve)
{        
    if(!trouve)
    {
        if(joueur->getPosition() == item[i]->getPosition())
        {
            trouve=true;
        }
    }
    if(trouve)
    {
        item[i]->augmenterPortee(joueur);
    }
}


void System::bombeInfligerDegats(int pos, Bombe* bombe)
{
    string* tab = map->getTab();
    if(joueur->getPosition()==pos)
    {
        joueur->setHP(joueur->getHP()-bombe->getPuissance());
    }

    for(int i=0; i<nbMobMap; i++)
    {
        if(mob[i]->getPosition() == pos)
        {
            mob[i]->setHP(mob[i]->getHP()-bombe->getPuissance());
        }
    }

    bombe = joueur->getBombe();
    for(int i=0; i<joueur->getNbBombMax(); i++)
    {
        if(bombe[i].getPosition() == pos)
        {
            bombe[i].setTourExplosion(0);
        }
    }

    
    for(int i=0; i<map->getNbWallMap(); i++)
    {
        if(wall[i]->getPosition()==pos)
        {
            wall[i]->setHP(wall[i]->getHP()-1);
        }
    }
}




void System::exploserBombe(Bombe* bombe)
{
    string* tab = map->getTab();
    int positionBombe = bombe->getPosition();
    int* porteePossibleBombe;


    if(tab[positionBombe] == "0") // s'il n'y a qu'une bombe, on passe à la bombe qui explose
        tab[positionBombe] = "@"; 
    else if(tab[positionBombe] == "0M" || tab[positionBombe] == "M0")
        tab[positionBombe] = "@M";
    else if(tab[positionBombe] == "0B" || tab[positionBombe] == "B0")
        tab[positionBombe] = "@B";
    else if(tab[positionBombe] == "0<") // bombe + fleche gauche
        tab[positionBombe] = "@<";
    else if(tab[positionBombe] == "0>") // bombe + fleche droite
        tab[positionBombe] = "@>";
    else if(tab[positionBombe] == "0A") // bombe + fleche haut
        tab[positionBombe] = "@A";
    else if(tab[positionBombe] == "0V") // bombe + fleche bas
        tab[positionBombe] = "@V";
    else // sinon, il ne reste que le fantome qui peut etre sur la bombe donc on affiche la bombe qui explose en plus du fantome
        tab[positionBombe] = "@G";

    map->explosionBombe(positionBombe, bombe->getPortee());
    porteePossibleBombe = map->getPorteePossibleBombe();

    if(positionBombe>=0 && positionBombe<map->getNbCaractere()){   // 0 <= position bombe < 75
        for(int k=0; k<4; k++)// les 4 directions
        {
            if(k==0)
            {
                for(int j=0;j<=porteePossibleBombe[k];j++){
                    bombeInfligerDegats(positionBombe+j, bombe);
                }
            }
            else if(k==1)
            {
                for(int j=0;j<=porteePossibleBombe[k];j++){
                    bombeInfligerDegats(positionBombe-j, bombe);
                }
            }
            else if(k==2)
            {
                for(int j=0;j<=porteePossibleBombe[k];j++){
                    bombeInfligerDegats(positionBombe+(map->getNbColonne()*j), bombe);
                }
            }
            else if(k==3)
            {
                for(int j=0;j<=porteePossibleBombe[k];j++){
                    bombeInfligerDegats(positionBombe-(map->getNbColonne()*j), bombe);
                }
            }
            
        }
    }
}


void System::enleverExplosionBombe(int positionBombe)
{
    map->retirerExplosionBombe(positionBombe);
    if(joueurMort()){
        mortParBombe(joueur->getPosition());
        exit(EXIT_SUCCESS);
    }
    for(int i=0; i<nbMobMap; i++)
    {
        if(mobMort())
            mortParBombe(mob[i]->getPosition());
    }

    for(int i=0; i<map->getNbWallMap(); i++)
    {
        degatMurs(wall[i]->getPosition());
    }
    
}

void System::resetBomb(Bombe* bombe)
{
    bombe->setPosition(-1);
    bombe->setTourExplosion(0);
    joueur->setNbBombRestante(joueur->getNbBombRestante()+1);
}

void System::degatMurs(int position)
{
    string* tab = map->getTab();

    for(int i=0; i<map->getNbWallMap(); i++)
    {
        if(wall[i]->getPosition()==position)
        {
            if(wall[i]->getHP() == 1)
            {
                if(tab[position]=="W")
                    tab[position]="w";
                else if(tab[position]=="WG")
                    tab[position]=="wG";
            }
            else if(wall[i]->getHP() == 0)
            {
                if(tab[position]=="w")
                    tab[position]=" ";
                else if(tab[position]=="wG")
                    tab[position]=="G";

                wall[i]->setPosition(-1);
            }
        }
    }
}


void System::mortParBombe(int position)
{
    string* tab = map->getTab();

    if(joueur->getPosition() == position)
    {
        if(tab[position]=="P")
            tab[position]=" ";
        else if(tab[position]=="MP" || tab[position]=="PM")
            tab[position]="M";
        else if(tab[position]=="GP" || tab[position]=="PG")
            tab[position]="G";
        else if(tab[position]=="BP" || tab[position]=="PB")
            tab[position]="B";
    }

    for(int i=0; i<nbMobMap; i++)
    {
        if(mob[i]->getPosition() == position)
        {
            if(tab[position]=="M")
                tab[position]=" ";
            else if(tab[position]=="B")
                tab[position]=" ";
            else if(tab[position]=="G")
                tab[position]=" ";
            else if(tab[position]=="MP" || tab[position]=="PM")
                tab[position]="P";
            else if(tab[position]=="GP" || tab[position]=="PG")
                tab[position]="P";
            else if(tab[position]=="BP" || tab[position]=="PB")
                tab[position]="P";
            else if(tab[position]=="MLG" || tab[position]=="MLG")
                tab[position]="ML";
            else if(tab[position]=="MLB" || tab[position]=="MLB")
                tab[position]="ML";
            else if(tab[position]=="MLM" || tab[position]=="MLM")
                tab[position]="ML";
            else if(tab[position]=="MBG" || tab[position]=="MBG")
                tab[position]="MB";
            else if(tab[position]=="MBB" || tab[position]=="MBB")
                tab[position]="MB";
            else if(tab[position]=="MBM" || tab[position]=="MBM")
                tab[position]="MB";
            else if(tab[position]=="PUG" || tab[position]=="PUG")
                tab[position]="PU";
            else if(tab[position]=="PUB" || tab[position]=="PUB")
                tab[position]="PU";
            else if(tab[position]=="PUM" || tab[position]=="PUM")
                tab[position]="PU";
            else if(tab[position]=="SPG" || tab[position]=="SPG")
                tab[position]="SP";
            else if(tab[position]=="SPB" || tab[position]=="SPB")
                tab[position]="SP";
            else if(tab[position]=="SPM" || tab[position]=="SPM")
                tab[position]="SP";
            else if(tab[position]=="SCG" || tab[position]=="SCG")
                tab[position]="SC";
            else if(tab[position]=="SCB" || tab[position]=="SCB")
                tab[position]="SC";
            else if(tab[position]=="SCM" || tab[position]=="SCM")
                tab[position]="SC";
        }
    }
}


void System::actualiserCarte()
{
    map->actualiserMap();
}



bool System::verifFuturPosition(int position, char deplacement, int futurPosition, string lettreJoueur){
    string* tab = map->getTab();
    int nbLigne = map->getNbLigne();
    int nbColonne = map->getNbColonne();
    int nbCaractere = map->getNbCaractere();
    int i=0;
    bool peuxSeDeplacer=true;


    while(peuxSeDeplacer && i<=nbLigne){
        if(position==0)                     //position = 0
        {                    
            if(deplacement=='q' | deplacement=='z') peuxSeDeplacer=false;
        }
        if(position==nbCaractere-1)    //position = 75
        {
            if(deplacement=='s' || deplacement=='d') peuxSeDeplacer=false;
        }
        if(position==nbColonne*i)      //position = 15, 30, 45, 60 coté gauche
        {
            if(deplacement=='q') peuxSeDeplacer=false;
        }
        if(position==(nbColonne*i)-1)  //position = 14, 29, 44, 59  coté droite
        {
            if(deplacement=='d') peuxSeDeplacer=false;
        }
        if(position>=nbColonne*(nbLigne-1) && position<nbColonne*nbLigne)    // 75 > position >= 60
        {
            if(deplacement=='s') peuxSeDeplacer=false;
        }
        if(position>=0 && position<nbColonne)           // 15 > position >= 0
        {
            if(deplacement=='z') peuxSeDeplacer=false;
        }
        if(futurPosition>=0 && futurPosition<nbCaractere){ // 0 <= position < 75
            if(lettreJoueur=="P" && (tab[futurPosition]=="#" || tab[futurPosition]=="WG" || tab[futurPosition]=="wG" || tab[futurPosition]=="W" || tab[futurPosition]=="w" || tab[futurPosition]=="0" || tab[futurPosition]=="0B" || tab[futurPosition]=="0M" || tab[futurPosition]=="0G" || tab[futurPosition]=="B0" || tab[futurPosition]=="M0" || tab[futurPosition]=="G0" || tab[futurPosition]=="@" || tab[futurPosition]=="0<" || tab[futurPosition]=="0>" || tab[futurPosition]=="0A" || tab[futurPosition]=="0V" || tab[futurPosition]=="X0" || tab[futurPosition]=="XM0" || tab[futurPosition]=="XG0" || tab[futurPosition]=="XB0"))
            {                 
                peuxSeDeplacer=false;
            }
            else if((lettreJoueur=="G" || lettreJoueur=="MLG" || lettreJoueur=="MBG" || lettreJoueur=="PUG" || lettreJoueur=="SCG" || lettreJoueur=="SPG" || lettreJoueur=="XG" || lettreJoueur=="0G" || lettreJoueur=="WG" || lettreJoueur=="wG") && (tab[futurPosition]=="#" || tab[futurPosition]=="WG" || tab[futurPosition]=="wG" || tab[futurPosition]=="M" || tab[futurPosition]=="B" || tab[futurPosition]=="G" || tab[futurPosition]=="MLM" || tab[futurPosition]=="MLB" || tab[futurPosition]=="MLG" || tab[futurPosition]=="PUM" || tab[futurPosition]=="PUB" || tab[futurPosition]=="PUG" || tab[futurPosition]=="MBM" || tab[futurPosition]=="MBB" || tab[futurPosition]=="MBG" || tab[futurPosition]=="SPM" || tab[futurPosition]=="SPB" || tab[futurPosition]=="SPG" || tab[futurPosition]=="SCM" || tab[futurPosition]=="SCB" || tab[futurPosition]=="SCG" || tab[futurPosition]=="0G" || tab[futurPosition]=="G0" || tab[futurPosition]=="0B" || tab[futurPosition]=="B0" || tab[futurPosition]=="0M" || tab[futurPosition]=="M0" || tab[futurPosition]=="PG" || tab[futurPosition]=="GP" || tab[futurPosition]=="PB" || tab[futurPosition]=="BP" || tab[futurPosition]=="PM" || tab[futurPosition]=="MP" || tab[futurPosition]=="XM" || tab[futurPosition]=="XB" || tab[futurPosition]=="XG"))
            {      
                peuxSeDeplacer=false;
            }
            else if((lettreJoueur=="M" || lettreJoueur=="MLM" || lettreJoueur=="MBM" || lettreJoueur=="PUM" || lettreJoueur=="SCM" || lettreJoueur=="SPM" || lettreJoueur=="XM" || lettreJoueur=="0M") && (tab[futurPosition]=="#" || tab[futurPosition]=="WG" || tab[futurPosition]=="wG" || tab[futurPosition]=="W" || tab[futurPosition]=="w" || tab[futurPosition]=="0" || tab[futurPosition]=="@" || tab[futurPosition]=="G" || tab[futurPosition]=="M" || tab[futurPosition]=="B"  || tab[futurPosition]=="MLM" || tab[futurPosition]=="MLB" || tab[futurPosition]=="MLG" || tab[futurPosition]=="PUM" || tab[futurPosition]=="PUB" || tab[futurPosition]=="PUG" || tab[futurPosition]=="MBM" || tab[futurPosition]=="MBB" || tab[futurPosition]=="MBG" || tab[futurPosition]=="SPM" || tab[futurPosition]=="SPB" || tab[futurPosition]=="SPG" || tab[futurPosition]=="SCM" || tab[futurPosition]=="SCB" || tab[futurPosition]=="SCG" || tab[futurPosition]=="0G" || tab[futurPosition]=="G0" || tab[futurPosition]=="0B" || tab[futurPosition]=="B0" || tab[futurPosition]=="0M" || tab[futurPosition]=="M0" || tab[futurPosition]=="PG" || tab[futurPosition]=="GP" || tab[futurPosition]=="PB" || tab[futurPosition]=="BP" || tab[futurPosition]=="PM" || tab[futurPosition]=="MP" || tab[futurPosition]=="0<" || tab[futurPosition]=="0>" || tab[futurPosition]=="0A" || tab[futurPosition]=="0V" || tab[futurPosition]=="XM" || tab[futurPosition]=="XB" || tab[futurPosition]=="XG"))
            {      
                peuxSeDeplacer=false;
            }
            else if((lettreJoueur=="B" || lettreJoueur=="MLB" || lettreJoueur=="MBB" || lettreJoueur=="PUB" || lettreJoueur=="SCB" || lettreJoueur=="SPB" || lettreJoueur=="XB" || lettreJoueur=="0B") && (tab[futurPosition]=="#" || tab[futurPosition]=="WG" || tab[futurPosition]=="wG" || tab[futurPosition]=="W" || tab[futurPosition]=="w" || tab[futurPosition]=="0" || tab[futurPosition]=="@" || tab[futurPosition]=="G" || tab[futurPosition]=="M" || tab[futurPosition]=="B" || tab[futurPosition]=="MLM" || tab[futurPosition]=="MLB" || tab[futurPosition]=="MLG" || tab[futurPosition]=="PUM" || tab[futurPosition]=="PUB" || tab[futurPosition]=="PUG" || tab[futurPosition]=="MBM" || tab[futurPosition]=="MBB" || tab[futurPosition]=="MBG" || tab[futurPosition]=="SPM" || tab[futurPosition]=="SPB" || tab[futurPosition]=="SPG" || tab[futurPosition]=="SCM" || tab[futurPosition]=="SCB" || tab[futurPosition]=="SCG" || tab[futurPosition]=="0G" || tab[futurPosition]=="G0" || tab[futurPosition]=="0B" || tab[futurPosition]=="B0" || tab[futurPosition]=="0M" || tab[futurPosition]=="M0" || tab[futurPosition]=="PG" || tab[futurPosition]=="GP" || tab[futurPosition]=="PB" || tab[futurPosition]=="BP" || tab[futurPosition]=="PM" || tab[futurPosition]=="MP" || tab[futurPosition]=="0<" || tab[futurPosition]=="0>" || tab[futurPosition]=="0A" || tab[futurPosition]=="0V" || tab[futurPosition]=="XM" || tab[futurPosition]=="XB" || tab[futurPosition]=="XG"))
            {                 
                peuxSeDeplacer=false;
            }
        }
        i++;
    }

    return peuxSeDeplacer;
}


int System::conversionDeplacementArrow(char direction)
{
    int deplacement=1;
    if(direction == '<'){deplacement=-1;}
    else if(direction == '>'){deplacement=1;}
    else if(direction == 'A'){deplacement=-map->getNbColonne();}
    else if(direction == 'V'){deplacement=map->getNbColonne();}
    return deplacement;
}

char System::conversionDirectionArrow(char direction)
{
    char dir=' ';
    if(direction == '<'){dir='q';}
    else if(direction == '>'){dir='d';}
    else if(direction == 'A'){dir='z';}
    else if(direction == 'V'){dir='s';}
    return dir;
}



bool System::gagner()
{
    int cptMortMob=0;
    bool gagne=false;
    
    for(int i=0; i<nbMobMap; i++)
    {
        if(mob[i]->getMort())
            cptMortMob++;
    }
    if(cptMortMob==nbMobMap && joueur->getPosition()==objectif->getPosition())
    {
        gagne=true;
    }
    return gagne;
}




void System::jouer(string nomFichier)
{
    bool quitter = false;
    int porteePossibleBombe[4];
    bool joueurBloque;
    bool win=false;
    int i;


    map->setNomFichier(nomFichier);
    map->infoMap();
    
    
    string tab[map->getNbCaractere()];
    map->setTab(tab);
     


    map->lectureMap();
    map->alloueMurs();
    wall = map->getWall();
    map->positionObjectif();
    objectif= map->getObjectif();
    alloueMob();
    setNbMobMap(nombreMobMap());
    alloueBomb();
    lirePositionJoueur();
    alloueItem();

    while(!quitter)
    {
        i=0;
        while(i<joueur->getSpeed() && !quitter)
        {
            afficherCarte(joueur->getHP(), joueur->getBombe()->getPuissance(), joueur->getNbBombMax(), joueur->getSpeed(), joueur->getBombe()->getPortee());

            if(joueurMort()){
                cout << "Vous êtes mort !" << endl;
                exit(EXIT_SUCCESS);
            }

            if(map->verifJoueurBloque(joueur->getPosition()))
            {
                quitter = demanderAction();
            }
                
            i++;
        }
        
        if(!quitter)
        {
            win = gagner();
            if(win)
            {
                quitter=true;
                afficherCarte(joueur->getHP(), joueur->getBombe()->getPuissance(), joueur->getNbBombMax(), joueur->getSpeed(), joueur->getBombe()->getPortee());
                cout << "   _____                     __ " << endl;
                cout << "  / ____|                   /_/ " << endl;
                cout << " | |  __  __ _  __ _ _ __   ___ " << endl;
                cout << " | | |_ |/ _` |/ _` | '_ \\ / _ \\" << endl;
                cout << " | |__| | (_| | (_| | | | |  __/" << endl;
                cout << "  \\_____|\\__,_|\\__, |_| |_|\\___|" << endl;
                cout << "                __/ |           " << endl;
                cout << "               |___/            " << endl;
                exit(EXIT_SUCCESS);
            }
                
        }

        if(!quitter)
        {
            //tour des bombes
            joueur = getJoueur();

            if(joueur->getNbBombRestante()!=joueur->getNbBombMax())
            {
                Bombe* bombe = joueur->getBombe(); // recupere le tableau des bombes du joueurs
                for(int i=0; i<joueur->getNbBombMax(); i++)
                {
                    if(bombe[i].getPosition()!=-1) // si une bombe est placée (!=-1)
                    {
                        bombe[i].setTourExplosion(bombe[i].getTourExplosion()-1); // on reduit de 1 tour l'attente avant explosion

                        if(bombe[i].getTourExplosion()<=0) // si l'attente est à 0
                        {
                            exploserBombe(&bombe[i]); // on fait exploser la bombe
                            afficherCarte(joueur->getHP(), joueur->getBombe()->getPuissance(), joueur->getNbBombMax(), joueur->getSpeed(), joueur->getBombe()->getPortee());

                            std::this_thread::sleep_for(2s); // attente de 2 secondes pour voir l'explosion

                            enleverExplosionBombe(bombe[i].getPosition()); // et on retire tout ce qui est lié à l'explosion
                            afficherCarte(joueur->getHP(), joueur->getBombe()->getPuissance(), joueur->getNbBombMax(), joueur->getSpeed(), joueur->getBombe()->getPortee());

                            resetBomb(&bombe[i]);
                        }
                    }
                }
            }


            // tour des monstres
            for(int i=0; i<nombreMobMap(); i++)
            {
                if(mob[i]->getHP()>0)
                {

                    afficherCarte(joueur->getHP(), joueur->getBombe()->getPuissance(), joueur->getNbBombMax(), joueur->getSpeed(), joueur->getBombe()->getPortee());

                    std::this_thread::sleep_for(1s);
                    
                    deplacerMonstres(i);
                }
            }


            for(int i=0; i<nombreMobMap(); i++)
            {
                if(mob[i]->getHP()>0 && mob[i]->isBowman())
                {
                    if(mob[i]->getArrow()->getPosition() != -1)
                    {
                        afficherCarte(joueur->getHP(), joueur->getBombe()->getPuissance(), joueur->getNbBombMax(), joueur->getSpeed(), joueur->getBombe()->getPortee());

                        std::this_thread::sleep_for(1s);
                        
                        map->deplacementFleche(mob[i]->getArrow()->getPosition(), conversionDirectionArrow(mob[i]->getArrow()->getDirection()));
                        mob[i]->getArrow()->seDeplacer(conversionDeplacementArrow(mob[i]->getArrow()->getDirection()));
                        joueurItemFlecheMonstre(mob[i]->getArrow()->getPosition());
                    }
                    
                }
            }
        }
    }

    //return 0;
}