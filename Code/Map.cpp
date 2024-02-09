#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "Map.h"

using namespace std;


Map::Map(int nbLigne, int nbColonne, int nbCaractere, string* tab, string nomFichier, bool emoji, Wall** wall, int nbWallMap, Objectif* objectif): nbLigne(nbLigne), nbColonne(nbColonne), nbCaractere(nbCaractere), tab(tab), nomFichier(nomFichier), emoji(emoji), wall(wall), nbWallMap(nbWallMap), objectif(objectif){}


//Affiche la map dans le terminal
void Map::affichageMap(int nbHP, int puissanceBombe, int nbBombMax, int speed, int portee){
    int ligne=0, cptLigne=0, i=0, y=0, taille;
    bool boole=false, haut=false, bas=false;
    string espace="   ", murInvincibleHaut="###", murInvincibleBas="###", corpsFleche=" | ", flecheDroite="-->", flecheGauche="<--";

    string str1="", strHaut="", strBas="";
    for(int i=0;i<nbColonne;i++){
        if(i==0){
            str1+="├───";
            strHaut+="┌───";
            strBas+="└───";
        }else{
            str1+="┼───";
            strHaut+="┬───";
            strBas+="┴───";
        }
    }
    str1+="┤";
    strHaut+="┐";
    strBas+="┘";


    while(boole==false){
        if(ligne==0 || ligne==4){
            if(haut==false){
                cout << strHaut << endl;
                haut=true;
            }else if(bas==false && cptLigne==(nbLigne-1)){
                cout << strBas << endl;
                bas=true;
            }else{
                cout << str1;
                if(y==3){
                    if(emoji==true) cout << "  Nombre de déplacement (👟) = " << speed;
                    else cout << "  Nombre de déplacement (SP) = " << speed;
                    y++;
                }
                cout << endl;
            }
            ligne++;
            if(ligne==5){
                ligne=1;
                cptLigne++;
                if(cptLigne==nbLigne) boole=true;
            }
        }else if(ligne==1 || ligne==3){
            if(ligne==1){
                for(int k=nbColonne*cptLigne;k<nbColonne+(nbColonne*cptLigne);k++){
                    if((tab[k]=="XMP" || tab[k]=="XBP" || tab[k]=="XGP" || tab[k]=="XP0") && emoji==true){
                        cout << "│ 😀";
                    }else if(tab[k]=="#" || tab[k]=="#1" || tab[k]=="#2" || tab[k]=="#3" || tab[k]=="#4" || tab[k]=="#5" || tab[k]=="#6" || tab[k]=="#7"){
                        cout << "│" << murInvincibleHaut;
                    }else if((tab[k]=="@G" || tab[k]=="G@" || tab[k]=="0G" || tab[k]=="G0" || tab[k]=="wG" || tab[k]=="WG") && emoji==true){
                        cout << "│ 👻";
                    }else if((tab[k]=="@M" || tab[k]=="M@" || tab[k]=="0M" || tab[k]=="M0") && emoji==true){
                        cout << "│ 👹";
                    }else if((tab[k]=="@B" || tab[k]=="B@" || tab[k]=="0B" || tab[k]=="B0") && emoji==true){
                        cout << "│ 🏹";
                    }else if(tab[k]=="@" || tab[k]=="@G" || tab[k]=="G@" || tab[k]=="V" || tab[k]=="4" || tab[k]=="5"){
                        cout << "│" << corpsFleche;
                    }else if(tab[k]=="V4" || tab[k]=="V5"){
                        cout << "│ ||";
                    }else if(tab[k]=="V6" || tab[k]=="XV" || tab[k]=="VX"){
                        cout << "│  |";
                    }else if(tab[k]=="V1" || tab[k]=="V2" || tab[k]=="V3" || tab[k]=="V7"){
                        cout << "│ | ";
                    }else if((tab[k]=="PG1" || tab[k]=="PG2" || tab[k]=="PG3" || tab[k]=="PG7" || tab[k]=="PG6" || tab[k]=="PG4" || tab[k]=="GP1" || tab[k]=="GP2" || tab[k]=="GP3" || tab[k]=="GP7" || tab[k]=="GP6" || tab[k]=="GP4" || tab[k]=="XG4") && emoji==true){
                        cout << "│ 👻";
                    }else if((tab[k]=="PM1" || tab[k]=="PM2" || tab[k]=="PM3" || tab[k]=="PM7" || tab[k]=="PM6" || tab[k]=="PM4" || tab[k]=="MP1" || tab[k]=="MP2" || tab[k]=="MP3" || tab[k]=="MP7" || tab[k]=="MP6" || tab[k]=="MP4" || tab[k]=="XM4") && emoji==true){
                        cout << "│ 👹";
                    }else if((tab[k]=="PB1" || tab[k]=="PB2" || tab[k]=="PB3" || tab[k]=="PB7" || tab[k]=="PB6" || tab[k]=="PB4" || tab[k]=="BP1" || tab[k]=="BP2" || tab[k]=="BP3" || tab[k]=="BP7" || tab[k]=="BP6" || tab[k]=="BP4" || tab[k]=="XB4") && emoji==true){
                        cout << "│ 🏹";
                    }else if(tab[k]=="XP4" && emoji==true){
                        cout << "│ 😀";
                    }else if(tab[k].size()==2 && (tab[k][1]=='5' || tab[k][1]=='4')){
                        cout << "│ | ";
                    }else if(tab[k].size()==3 && (tab[k][2]=='5' || tab[k][2]=='4')){
                        cout << "│ | ";
                    }else if(tab[k]=="0V" || tab[k]=="MLV" || tab[k]=="MBV" || tab[k]=="PUV" || tab[k]=="SCV" || tab[k]=="SPV"){
                        cout << "│  |";
                    }else if((tab[k]=="MLG" || tab[k]=="SPG" || tab[k]=="PUG" || tab[k]=="MBG" || tab[k]=="SCG" || tab[k]=="PG" || tab[k]=="GP" || tab[k]=="GP0" || tab[k]=="PG0" || tab[k]=="XG1" || tab[k]=="XG2" || tab[k]=="XG3" || tab[k]=="XG7" || tab[k]=="XG6") && emoji==true){
                        cout << "│ 👻";
                    }else if((tab[k]=="MLB" || tab[k]=="SPB" || tab[k]=="PUB" || tab[k]=="MBB" || tab[k]=="SCB" || tab[k]=="PB" || tab[k]=="BP" || tab[k]=="BP0" || tab[k]=="PB0" || tab[k]=="XB1" || tab[k]=="XB2" || tab[k]=="XB3" || tab[k]=="XB7" || tab[k]=="XB6") && emoji==true){
                        cout << "│ 🏹";
                    }else if((tab[k]=="MLM" || tab[k]=="SPM" || tab[k]=="PUM" || tab[k]=="MBM" || tab[k]=="SCM" || tab[k]=="PM" || tab[k]=="MP" || tab[k]=="MP0" || tab[k]=="PM0" || tab[k]=="XM1" || tab[k]=="XM2" || tab[k]=="XM3" || tab[k]=="XM7" || tab[k]=="XM6") && emoji==true){
                        cout << "│ 👹";
                    }else if((tab[k]=="P0" || tab[k]=="0P" || tab[k]=="XP1" || tab[k]=="XP2" || tab[k]=="XP3" || tab[k]=="XP7" || tab[k]=="XP6") && emoji==true){
                        cout << "│ 😀";
                    }else if(tab[k]=="MLA4" || tab[k]=="MLA5"){
                        cout << "│ | ";
                    }else if(tab[k]=="MLV4" || tab[k]=="MLV5"){
                        cout << "│ ||";
                    }else if(tab[k]=="MLV6" || tab[k]=="MLV1" || tab[k]=="MLV2" || tab[k]=="MLV3" || tab[k]=="MLV7"){
                        cout << "│  |";
                    }else if(tab[k]=="ML<4" || tab[k]=="ML<5" || tab[k]=="ML>4" || tab[k]=="ML>5"){
                        cout << "│ | ";
                    }else if(tab[k]=="PUA4" || tab[k]=="PUA5"){
                        cout << "│ | ";
                    }else if(tab[k]=="PUV4" || tab[k]=="PUV5"){
                        cout << "│ ||";
                    }else if(tab[k]=="PUV6" || tab[k]=="PUV1" || tab[k]=="PUV2" || tab[k]=="PUV3" || tab[k]=="PUV7"){
                        cout << "│  |";
                    }else if(tab[k]=="PU<4" || tab[k]=="PU<5" || tab[k]=="PU>4" || tab[k]=="PU>5"){
                        cout << "│ | ";
                    }else if(tab[k]=="MBA4" || tab[k]=="MBA5"){
                        cout << "│ | ";
                    }else if(tab[k]=="MBV4" || tab[k]=="MBV5"){
                        cout << "│ ||";
                    }else if(tab[k]=="MBV6" || tab[k]=="MBV1" || tab[k]=="MBV2" || tab[k]=="MBV3" || tab[k]=="MBV7"){
                        cout << "│  |";
                    }else if(tab[k]=="MB<4" || tab[k]=="MB<5" || tab[k]=="MB>4" || tab[k]=="MB>5"){
                        cout << "│ | ";
                    }else if(tab[k]=="SPA4" || tab[k]=="SPA5"){
                        cout << "│ | ";
                    }else if(tab[k]=="SPV4" || tab[k]=="SPV5"){
                        cout << "│ ||";
                    }else if(tab[k]=="SPV6" || tab[k]=="SPV1" || tab[k]=="SPV2" || tab[k]=="SPV3" || tab[k]=="SPV7"){
                        cout << "│  |";
                    }else if(tab[k]=="SP<4" || tab[k]=="SP<5" || tab[k]=="SP>4" || tab[k]=="SP>5"){
                        cout << "│ | ";
                    }else if(tab[k]=="SCA4" || tab[k]=="SCA5"){
                        cout << "│ | ";
                    }else if(tab[k]=="SCV4" || tab[k]=="SCV5"){
                        cout << "│ ||";
                    }else if(tab[k]=="SCV6" || tab[k]=="SCV1" || tab[k]=="SCV2" || tab[k]=="SCV3" || tab[k]=="SCV7"){
                        cout << "│  |";
                    }else if(tab[k]=="SC<4" || tab[k]=="SC<5" || tab[k]=="SC>4" || tab[k]=="SC>5"){
                        cout << "│ | ";
                    }else if((tab[k]=="MLB1" || tab[k]=="MLB2" || tab[k]=="MLB4"|| tab[k]=="MLB6" || tab[k]=="PUB1" || tab[k]=="PUB2" || tab[k]=="PUB4"|| tab[k]=="PUB6" || tab[k]=="PUB1" || tab[k]=="PUB2" || tab[k]=="PUB4"|| tab[k]=="PUB6" || tab[k]=="MBB1" || tab[k]=="MBB2" || tab[k]=="MBB4"|| tab[k]=="MBB6" || tab[k]=="SCB1" || tab[k]=="SCB2" || tab[k]=="SCB4"|| tab[k]=="SCB6" || tab[k]=="SPB1" || tab[k]=="SPB2" || tab[k]=="SPB4"|| tab[k]=="SPB6") && emoji==true){
                        cout << "│ 🏹";
                    }else if((tab[k]=="MLB3" || tab[k]=="MLB7" || tab[k]=="PUB3" || tab[k]=="PUB7" || tab[k]=="MBB3" || tab[k]=="MBB7" || tab[k]=="SCB3" || tab[k]=="SCB7" || tab[k]=="SPB3" || tab[k]=="SPB7") && emoji==true){
                        cout << "│🏹 ";
                    }else if((tab[k]=="MLG1" || tab[k]=="MLG2" || tab[k]=="MLG4"|| tab[k]=="MLG6" || tab[k]=="PUG1" || tab[k]=="PUG2" || tab[k]=="PUG4"|| tab[k]=="PUG6" || tab[k]=="PUG1" || tab[k]=="PUG2" || tab[k]=="PUG4"|| tab[k]=="PUG6" || tab[k]=="MBG1" || tab[k]=="MBG2" || tab[k]=="MBG4"|| tab[k]=="MBG6" || tab[k]=="SCG1" || tab[k]=="SCG2" || tab[k]=="SCG4"|| tab[k]=="SCG6" || tab[k]=="SPG1" || tab[k]=="SPG2" || tab[k]=="SPG4"|| tab[k]=="SPG6") && emoji==true){
                        cout << "│ 👻";
                    }else if((tab[k]=="MLG3" || tab[k]=="MLG7" || tab[k]=="PUG3" || tab[k]=="PUG7" || tab[k]=="MBG3" || tab[k]=="MBG7" || tab[k]=="SCG3" || tab[k]=="SCG7" || tab[k]=="SPG3" || tab[k]=="SPG7") && emoji==true){
                        cout << "│👻 ";
                    }else if((tab[k]=="MLM1" || tab[k]=="MLM2" || tab[k]=="MLM4"|| tab[k]=="MLM6" || tab[k]=="PUM1" || tab[k]=="PUM2" || tab[k]=="PUM4"|| tab[k]=="PUM6" || tab[k]=="PUM1" || tab[k]=="PUM2" || tab[k]=="PUM4"|| tab[k]=="PUM6" || tab[k]=="MBM1" || tab[k]=="MBM2" || tab[k]=="MBM4"|| tab[k]=="MBM6" || tab[k]=="SCM1" || tab[k]=="SCM2" || tab[k]=="SCM4"|| tab[k]=="SCM6" || tab[k]=="SPM1" || tab[k]=="SPM2" || tab[k]=="SPM4"|| tab[k]=="SPM6") && emoji==true){
                        cout << "│ 👹";
                    }else if((tab[k]=="MLM3" || tab[k]=="MLM7" || tab[k]=="PUM3" || tab[k]=="PUM7" || tab[k]=="MBM3" || tab[k]=="MBM7" || tab[k]=="SCM3" || tab[k]=="SCM7" || tab[k]=="SPM3" || tab[k]=="SPM7") && emoji==true){
                        cout << "│👹 ";
                    }else if(tab[k]=="MLB5" || tab[k]=="MLB4" || tab[k]=="MLG4" || tab[k]=="MLG5" || tab[k]=="MLM4" || tab[k]=="MLM5" || tab[k]=="PUB5" || tab[k]=="PUB4" || tab[k]=="PUG4" || tab[k]=="PUG5" || tab[k]=="PUM4" || tab[k]=="PUM5" || tab[k]=="MBB5" || tab[k]=="MBB4" || tab[k]=="MBG4" || tab[k]=="MBG5" || tab[k]=="MBM4" || tab[k]=="MBM5" || tab[k]=="SCB5" || tab[k]=="SCB4" || tab[k]=="SCG4" || tab[k]=="SCG5" || tab[k]=="SCM4" || tab[k]=="SCM5" || tab[k]=="SPB5" || tab[k]=="SPB4" || tab[k]=="SPG4" || tab[k]=="SPG5" || tab[k]=="SPM4" || tab[k]=="SPM5"){
                        cout << "│ | ";
                    }else if(tab[k]=="MLB1" || tab[k]=="MLB2" || tab[k]=="MLB3" || tab[k]=="MLB7" || tab[k]=="PUB1" || tab[k]=="PUB2" || tab[k]=="PUB3" || tab[k]=="PUB7" || tab[k]=="MBB1" || tab[k]=="MBB2" || tab[k]=="MBB3" || tab[k]=="MBB7" || tab[k]=="SCB1" || tab[k]=="SCB2" || tab[k]=="SCB3" || tab[k]=="SCB7" || tab[k]=="SPB1" || tab[k]=="SPB2" || tab[k]=="SPB3" || tab[k]=="SPB7"){
                        cout << "│ B ";
                    }else if(tab[k]=="MLG1" || tab[k]=="MLG2" || tab[k]=="MLG3" || tab[k]=="MLG7" || tab[k]=="PUG1" || tab[k]=="PUG2" || tab[k]=="PUG3" || tab[k]=="PUG7" || tab[k]=="MBG1" || tab[k]=="MBG2" || tab[k]=="MBG3" || tab[k]=="MBG7" || tab[k]=="SCG1" || tab[k]=="SCG2" || tab[k]=="SCG3" || tab[k]=="SCG7" || tab[k]=="SPG1" || tab[k]=="SPG2" || tab[k]=="SPG3" || tab[k]=="SPG7"){
                        cout << "│ G ";
                    }else if(tab[k]=="MLM1" || tab[k]=="MLM2" || tab[k]=="MLM3" || tab[k]=="MLM7" || tab[k]=="PUM1" || tab[k]=="PUM2" || tab[k]=="PUM3" || tab[k]=="PUM7" || tab[k]=="MBM1" || tab[k]=="MBM2" || tab[k]=="MBM3" || tab[k]=="MBM7" || tab[k]=="SCM1" || tab[k]=="SCM2" || tab[k]=="SCM3" || tab[k]=="SCM7" || tab[k]=="SPM1" || tab[k]=="SPM2" || tab[k]=="SPM3" || tab[k]=="SPM7"){
                        cout << "│ M ";
                    }else if((tab[k]=="WG1" || tab[k]=="WG2" || tab[k]=="WG3" || tab[k]=="WG7" || tab[k]=="wG1" || tab[k]=="wG2" || tab[k]=="wG3" || tab[k]=="wG7" || tab[k]=="wG4" || tab[k]=="wG6" || tab[k]=="WG4" || tab[k]=="WG6" || tab[k]=="wG" || tab[k]=="WG") && emoji==true){
                        cout << "│ 👻";
                    }else cout << "│" << espace;
                }
                cout<<"│";
                if(y==0){
                    if(emoji==true) cout << "  Point de vie (💖) = " << nbHP;
                    else cout << "  Point de vie (ML) = " << nbHP;
                    y++;
                }else if(y==4){
                    if(emoji==true) cout << "  Porter des bombes (📏) = " << portee;
                    else cout << "  Porter des bombes (SC) = " << portee;
                    y++;
                }
                cout << endl;
            }else if(ligne==3){
                for(int k=nbColonne*cptLigne;k<nbColonne+(nbColonne*cptLigne);k++){
                    if(tab[k]=="#" || tab[k]=="#1" || tab[k]=="#2" || tab[k]=="#3" || tab[k]=="#4" || tab[k]=="#5" || tab[k]=="#6" || tab[k]=="#7"){
                        cout << "│" << murInvincibleBas;
                    }else if(tab[k]=="XP5" && emoji==true){
                        cout << "│ 😀";
                    }else if(tab[k]=="XM5" && emoji==true){
                        cout << "│ 👹";
                    }else if(tab[k]=="XB5" && emoji==true){
                        cout << "│ 🏹";
                    }else if(tab[k]=="XG5" && emoji==true){
                        cout << "│ 👻";
                    }else if(tab[k]=="@" || tab[k]=="@G" || tab[k]=="G@" || tab[k]=="A" || tab[k]=="4" || tab[k]=="6" || tab[k]=="A2" || tab[k]=="A1" || tab[k]=="A7" || tab[k]=="A3"){
                        cout << "│" << corpsFleche;
                    }else if(tab[k]=="A4" || tab[k]=="A6"){
                        cout << "│ ||";
                    }else if(tab[k].size()==2 && (tab[k][1]=='4' || tab[k][1]=='6')){
                        cout << "│ | ";
                    }else if(tab[k].size()==3 && (tab[k][2]=='4' || tab[k][2]=='6')){
                        cout << "│ | ";
                    }else if(tab[k]=="XA" || tab[k]=="XA5" || tab[k]=="A5" || tab[k]=="0A" || tab[k]=="MLA" || tab[k]=="MBA" || tab[k]=="PUA" || tab[k]=="SCA" || tab[k]=="SPA"){
                        cout << "│  |";
                    }else if(tab[k]=="X>" || tab[k]==">1" || tab[k]==">2" || tab[k]==">3" || tab[k]==">7" || tab[k]=="0>" || tab[k]=="ML>" || tab[k]=="MB>" || tab[k]=="PU>" || tab[k]=="SC>" || tab[k]=="SP>" || tab[k]=="ML>1" || tab[k]=="ML>2" || tab[k]=="ML>3" || tab[k]=="ML>7" || tab[k]=="ML>4" || tab[k]=="ML>5" || tab[k]=="ML>6" || tab[k]=="PU>1" || tab[k]=="PU>2" || tab[k]=="PU>3" || tab[k]=="PU>7" || tab[k]=="PU>4" || tab[k]=="PU>5" || tab[k]=="PU>6" || tab[k]=="MB>1" || tab[k]=="MB>2" || tab[k]=="MB>3" || tab[k]=="MB>7" || tab[k]=="MB>4" || tab[k]=="MB>5" || tab[k]=="MB>6" || tab[k]=="SP>1" || tab[k]=="SP>2" || tab[k]=="SP>3" || tab[k]=="SP>7" || tab[k]=="SP>4" || tab[k]=="SP>5" || tab[k]=="SP>6" || tab[k]=="SC>1" || tab[k]=="SC>2" || tab[k]=="SC>3" || tab[k]=="SC>7" || tab[k]=="SC>4" || tab[k]=="SC>5" || tab[k]=="SC>6" || tab[k]=="X>1" || tab[k]=="X>2" || tab[k]=="X>3" || tab[k]=="X>7" || tab[k]=="X>4" || tab[k]=="X>5" || tab[k]=="X>6"){
                        cout << "│" << flecheDroite;
                    }else if(tab[k]=="X<" || tab[k]=="<1" || tab[k]=="<2" || tab[k]=="<3" || tab[k]=="<7" || tab[k]=="0<" || tab[k]=="ML<" || tab[k]=="MB<" || tab[k]=="PU<" || tab[k]=="SC<" || tab[k]=="SP<" || tab[k]=="ML<1" || tab[k]=="ML<2" || tab[k]=="ML<3" || tab[k]=="ML<7" || tab[k]=="ML<4" || tab[k]=="ML<5" || tab[k]=="ML<6" || tab[k]=="PU<1" || tab[k]=="PU<2" || tab[k]=="PU<3" || tab[k]=="PU<7" || tab[k]=="PU<4" || tab[k]=="PU<5" || tab[k]=="PU<6" || tab[k]=="MB<1" || tab[k]=="MB<2" || tab[k]=="MB<3" || tab[k]=="MB<7" || tab[k]=="MB<4" || tab[k]=="MB<5" || tab[k]=="MB<6" || tab[k]=="SP<1" || tab[k]=="SP<2" || tab[k]=="SP<3" || tab[k]=="SP<7" || tab[k]=="SP<4" || tab[k]=="SP<5" || tab[k]=="SP<6" || tab[k]=="SC<1" || tab[k]=="SC<2" || tab[k]=="SC<3" || tab[k]=="SC<7" || tab[k]=="SC<4" || tab[k]=="SC<5" || tab[k]=="SC<6" || tab[k]=="X<1" || tab[k]=="X<2" || tab[k]=="X<3" || tab[k]=="X<7" || tab[k]=="X<4" || tab[k]=="X<5" || tab[k]=="X<6"){
                        cout << "│" << flecheGauche;
                    }else if((tab[k]=="MLA1" || tab[k]=="MLA2" || tab[k]=="MLA7" || tab[k]=="MLA3") && emoji==true){
                        cout << "│💖|";
                    }else if(tab[k]=="MLA1" || tab[k]=="MLA2" || tab[k]=="MLA7" || tab[k]=="MLA3"){
                        cout << "│ML|";
                    }else if(tab[k]=="MLA4" || tab[k]=="MLA6"){
                        cout << "│ ||";
                    }else if(tab[k]=="MLA6" || tab[k]=="MLA5"){
                        cout << "│  |";
                    }else if((tab[k]=="MLV1" || tab[k]=="MLV2" || tab[k]=="MLV7" || tab[k]=="MLV3") && emoji==true){
                        cout << "│💖 ";
                    }else if(tab[k]=="MLV1" || tab[k]=="MLV2" || tab[k]=="MLV7" || tab[k]=="MLV3"){
                        cout << "│ML ";
                    }else if(tab[k]=="MLV4" || tab[k]=="MLV6"){
                        cout << "│ | ";
                    }else if((tab[k]=="PUA1" || tab[k]=="PUA2" || tab[k]=="PUA7" || tab[k]=="PUA3") && emoji==true){
                        cout << "│🔥|";
                    }else if(tab[k]=="PUA1" || tab[k]=="PUA2" || tab[k]=="PUA7" || tab[k]=="PUA3"){
                        cout << "│PU|";
                    }else if(tab[k]=="PUA4" || tab[k]=="PUA6"){
                        cout << "│ ||";
                    }else if(tab[k]=="PUA6" || tab[k]=="PUA5"){
                        cout << "│  |";
                    }else if((tab[k]=="PUV1" || tab[k]=="PUV2" || tab[k]=="PUV7" || tab[k]=="PUV3") && emoji==true){
                        cout << "│🔥 ";
                    }else if(tab[k]=="PUV1" || tab[k]=="PUV2" || tab[k]=="PUV7" || tab[k]=="PUV3"){
                        cout << "│PU ";
                    }else if(tab[k]=="PUV4" || tab[k]=="PUV6"){
                        cout << "│ | ";
                    }else if((tab[k]=="MBA1" || tab[k]=="MBA2" || tab[k]=="MBA7" || tab[k]=="MBA3") && emoji==true){
                        cout << "│🔮|";
                    }else if(tab[k]=="MBA1" || tab[k]=="MBA2" || tab[k]=="MBA7" || tab[k]=="MBA3"){
                        cout << "│MB|";
                    }else if(tab[k]=="MBA4" || tab[k]=="MBA6"){
                        cout << "│ ||";
                    }else if(tab[k]=="MBA6" || tab[k]=="MBA5"){
                        cout << "│  |";
                    }else if((tab[k]=="MBV1" || tab[k]=="MBV2" || tab[k]=="MBV7" || tab[k]=="MBV3") && emoji==true){
                        cout << "│🔮 ";
                    }else if(tab[k]=="MBV1" || tab[k]=="MBV2" || tab[k]=="MBV7" || tab[k]=="MBV3"){
                        cout << "│MB ";
                    }else if(tab[k]=="MBV4" || tab[k]=="MBV6"){
                        cout << "│ | ";
                    }else if((tab[k]=="SPA1" || tab[k]=="SPA2" || tab[k]=="SPA7" || tab[k]=="SPA3") && emoji==true){
                        cout << "│👟|";
                    }else if(tab[k]=="SPA1" || tab[k]=="SPA2" || tab[k]=="SPA7" || tab[k]=="SPA3"){
                        cout << "│SP|";
                    }else if(tab[k]=="SPA4" || tab[k]=="SPA6"){
                        cout << "│ ||";
                    }else if(tab[k]=="SPA6" || tab[k]=="SPA5"){
                        cout << "│  |";
                    }else if((tab[k]=="SPV1" || tab[k]=="SPV2" || tab[k]=="SPV7" || tab[k]=="SPV3") && emoji==true){
                        cout << "│👟 ";
                    }else if(tab[k]=="SPV1" || tab[k]=="SPV2" || tab[k]=="SPV7" || tab[k]=="SPV3"){
                        cout << "│SP ";
                    }else if(tab[k]=="SPV4" || tab[k]=="SPV6"){
                        cout << "│ | ";
                    }else if((tab[k]=="SCA1" || tab[k]=="SCA2" || tab[k]=="SCA7" || tab[k]=="SCA3") && emoji==true){
                        cout << "│📏|";
                    }else if(tab[k]=="SCA1" || tab[k]=="SCA2" || tab[k]=="SCA7" || tab[k]=="SCA3"){
                        cout << "│SC|";
                    }else if(tab[k]=="SCA4" || tab[k]=="SCA6"){
                        cout << "│ ||";
                    }else if(tab[k]=="SCA6" || tab[k]=="SCA5"){
                        cout << "│  |";
                    }else if((tab[k]=="SCV1" || tab[k]=="SCV2" || tab[k]=="SCV7" || tab[k]=="SCV3") && emoji==true){
                        cout << "│📏 ";
                    }else if(tab[k]=="SCV1" || tab[k]=="SCV2" || tab[k]=="SCV7" || tab[k]=="SCV3"){
                        cout << "│SC ";
                    }else if(tab[k]=="SCV4" || tab[k]=="SCV6"){
                        cout << "│ | ";
                    }else if(tab[k]=="MLB4" || tab[k]=="MLB6" || tab[k]=="MLG4" || tab[k]=="MLG6" || tab[k]=="MLM4" || tab[k]=="MLM6" || tab[k]=="PUB4" || tab[k]=="PUB6" || tab[k]=="PUG4" || tab[k]=="PUG6" || tab[k]=="PUM4" || tab[k]=="PUM6" || tab[k]=="MBB4" || tab[k]=="MBB6" || tab[k]=="MBG4" || tab[k]=="MBG6" || tab[k]=="MBM4" || tab[k]=="MBM6" || tab[k]=="SPB4" || tab[k]=="SPB6" || tab[k]=="SPG4" || tab[k]=="SPG6" || tab[k]=="SPM4" || tab[k]=="SPM6" || tab[k]=="SCB4" || tab[k]=="SCB6" || tab[k]=="SCG4" || tab[k]=="SCG6" || tab[k]=="SCM4" || tab[k]=="SCM6"){
                        cout << "│ | ";
                    }else if((tab[k]=="MLB5" || tab[k]=="MLG5" || tab[k]=="MLM5") && emoji==true){
                        cout << "│ 💖";
                    }else if((tab[k]=="PUB5" || tab[k]=="PUG5" || tab[k]=="PUM5") && emoji==true){
                        cout << "│ 🔥";
                    }else if((tab[k]=="SPB5" || tab[k]=="SPG5" || tab[k]=="SPM5") && emoji==true){
                        cout << "│ 👟";
                    }else if((tab[k]=="MBB5" || tab[k]=="MBG5" || tab[k]=="MBM5") && emoji==true){
                        cout << "│ 🔮";
                    }else if((tab[k]=="SCB5" || tab[k]=="SCG5" || tab[k]=="SCM5") && emoji==true){
                        cout << "│ 📏";
                    }else if((tab[k]=="WG5" || tab[k]=="wG5" ) && emoji==true){
                        cout << "│ 👻";
                    }else if((tab[k]=="GP0" || tab[k]=="PG0" || tab[k]=="BP0" || tab[k]=="PB0" || tab[k]=="MP0" || tab[k]=="PM0") && emoji==true){
                        cout << "│ 😀";
                    }else if((tab[k]=="PG5" || tab[k]=="GP5") && emoji==true){
                        cout << "│ 👻";
                    }else if((tab[k]=="PM5" || tab[k]=="MP5") && emoji==true){
                        cout << "│ 👹";
                    }else if((tab[k]=="PB5" || tab[k]=="BP5") && emoji==true){
                        cout << "│ 🏹";
                    }else cout << "│" << espace;
                }
                cout << "│";
                if(y==2){
                    if(emoji==true) cout << "  Nombre de bombe max (🔮) = " << nbBombMax;
                    else cout << "  Nombre de bombe max (MB) = " << nbBombMax;
                    y++;
                }   
                cout << endl;
            }
            ligne++;
        }else if(ligne==2){
            for(int j=i;j<i+nbColonne;j++){
                taille = tab[j].size();
                if(taille==1){
                    if(tab[j]=="<"){
                        cout << "│" << flecheGauche;
                    }else if(tab[j]==">"){
                        cout << "│" << flecheDroite;
                    }else if(tab[j]=="#"){
                        cout << "│###";
                    }else if(tab[j]=="P" && emoji==true){
                        cout << "│ 😀";
                    }else if(tab[j]=="G" && emoji==true){
                        cout << "│ 👻";
                    }else if(tab[j]=="B" && emoji==true){
                        cout << "│ 🏹";
                    }else if(tab[j]=="0" && emoji==true){
                        cout << "│ 💣";
                    }else if(tab[j]=="M" && emoji==true){
                        cout << "│ 👹";
                    }else if(tab[j]=="4" || tab[j]=="5" || tab[j]=="6"){
                        cout << "│ | ";
                    }else if(tab[j]=="1"){
                        cout << "│---";
                    }else if(tab[j]=="2"){
                        cout << "│-- ";
                    }else if(tab[j]=="3"){
                        cout << "│ --";
                    }else if(tab[j]=="7"){
                        cout << "│---";
                    }else if(tab[j]=="@" && emoji==true){
                        cout << "│-💥";
                    }else if(tab[j]=="@"){
                        cout << "│-@-";
                    }else cout << "│ " << tab[j] << " ";
                }else if(taille==2){
                    if(tab[j]=="X<" || tab[j]=="X>"){
                        cout << "│ X ";
                    }else if(tab[j]=="#1" || tab[j]=="#2" || tab[j]=="#3" || tab[j]=="#4" || tab[j]=="#5" || tab[j]=="#6" || tab[j]=="#7"){
                        cout << "│###";
                    }else if(tab[j]=="XP0" && emoji==true){
                        cout << "│X💣";
                    }else if((tab[j]=="WG" || tab[j]=="wG") && !emoji){
                        cout << "│ " << tab[j][0] << tab[j][1];
                    }else if(tab[j]=="XP" && emoji==true){
                        cout << "│X😀";
                    }else if(tab[j]=="XM" && emoji==true){
                        cout << "│X👹";
                    }else if(tab[j]=="XG" && emoji==true){
                        cout << "│X👻";
                    }else if(tab[j]=="XB" && emoji==true){
                        cout << "│X🏹";
                    }else if(tab[j]=="X0" && emoji==true){
                        cout << "│X💣";
                    }else if((tab[j]=="0<" || tab[j]=="0>" || tab[j]=="0G" || tab[j]=="G0" || tab[j]=="0M" || tab[j]=="M0" || tab[j]=="0B" || tab[j]=="B0" || tab[j]=="P0") && emoji==true){
                        cout << "│ 💣";
                    }else if(tab[j]=="0<" || tab[j]=="0>"){
                        cout << "│ 0 ";
                    }else if(tab[j]=="0A" && emoji==true){
                        cout << "│💣A";
                    }else if(tab[j]=="0V" && emoji==true){
                        cout << "│💣V";
                    }else if((tab[j]=="ML") && emoji==true){
                        cout << "│ 💖";
                    }else if((tab[j]=="SP") && emoji==true){
                        cout << "│ 👟";
                    }else if((tab[j]=="PU") && emoji==true){
                        cout << "│ 🔥";
                    }else if((tab[j]=="MB") && emoji==true){
                        cout << "│ 🔮";
                    }else if((tab[j]=="SC") && emoji==true){
                        cout << "│ 📏";
                    }else if(tab[j]=="X4" || tab[j]=="X5" || tab[j]=="X6"){
                        cout << "│ X ";
                    }else if(tab[j]=="X1" || tab[j]=="X7"){
                        cout << "│-X-";
                    }else if(tab[j]=="X2"){
                        cout << "│-X ";
                    }else if(tab[j]=="X3"){
                        cout << "│ X-";
                    }else if((tab[j]=="P5" || tab[j]=="P4" || tab[j]=="P6" || tab[j]=="PB" || tab[j]=="PG" || tab[j]=="PM") && emoji==true){
                        cout << "│ 😀";
                    }else if((tab[j]=="P1" || tab[j]=="P2") && emoji==true){
                        cout << "│-😀";
                    }else if((tab[j]=="P3" || tab[j]=="P7") && emoji==true){
                        cout << "│😀-";
                    }else if(tab[j]=="P4" || tab[j]=="P5" || tab[j]=="P6"){
                        cout << "│ P ";
                    }else if(tab[j]=="P1" || tab[j]=="P7"){
                        cout << "│-P-";
                    }else if(tab[j]=="P2"){
                        cout << "│-P ";
                    }else if(tab[j]=="P3"){
                        cout << "│ P-";
                    }else if((tab[j]=="M5" || tab[j]=="M4" || tab[j]=="M6") && emoji==true){
                        cout << "│ 👹";
                    }else if((tab[j]=="M1" || tab[j]=="M2") && emoji==true){
                        cout << "│-👹";
                    }else if((tab[j]=="M3" || tab[j]=="M7") && emoji==true){
                        cout << "│👹-";
                    }else if(tab[j]=="M4" || tab[j]=="M5" || tab[j]=="M6"){
                        cout << "│ M ";
                    }else if(tab[j]=="M1" || tab[j]=="M7"){
                        cout << "│-M-";
                    }else if(tab[j]=="M2"){
                        cout << "│-M ";
                    }else if(tab[j]=="M3"){
                        cout << "│ M-";
                    }else if((tab[j]=="B5" || tab[j]=="B4" || tab[j]=="B6") && emoji==true){
                        cout << "│ 🏹";
                    }else if((tab[j]=="B1" || tab[j]=="B2") && emoji==true){
                        cout << "│-🏹";
                    }else if((tab[j]=="B3" || tab[j]=="B7") && emoji==true){
                        cout << "│🏹-";
                    }else if(tab[j]=="B4" || tab[j]=="B5" || tab[j]=="B6"){
                        cout << "│ B ";
                    }else if(tab[j]=="B1" || tab[j]=="B7"){
                        cout << "│-B-";
                    }else if(tab[j]=="B2"){
                        cout << "│-B ";
                    }else if(tab[j]=="B3"){
                        cout << "│ B-";
                    }else if((tab[j]=="G5" || tab[j]=="G4" || tab[j]=="G6") && emoji==true){
                        cout << "│ 👻";
                    }else if((tab[j]=="G1" || tab[j]=="G2") && emoji==true){
                        cout << "│-👻";
                    }else if((tab[j]=="G3" || tab[j]=="G7") && emoji==true){
                        cout << "│👻-";
                    }else if(tab[j]=="G4" || tab[j]=="G5" || tab[j]=="G6"){
                        cout << "│ G ";
                    }else if(tab[j]=="G1" || tab[j]=="G7"){
                        cout << "│-G-";
                    }else if(tab[j]=="G2"){
                        cout << "│-G ";
                    }else if(tab[j]=="G3"){
                        cout << "│ G-";
                    }else if(tab[j]=="A7" || tab[j]=="A1"){
                        cout << "│-A-";
                    }else if(tab[j]=="A2"){
                        cout << "│-A ";
                    }else if(tab[j]=="A3"){
                        cout << "│ A-";
                    }else if(tab[j]=="A4" || tab[j]=="A5" || tab[j]=="A6"){
                        cout << "│ |A";
                    }else if(tab[j]=="V7" || tab[j]=="V1"){
                        cout << "│-V-";
                    }else if(tab[j]=="V2"){
                        cout << "│-V ";
                    }else if(tab[j]=="V3"){
                        cout << "│ V-";
                    }else if(tab[j]=="V4" || tab[j]=="V5" || tab[j]=="V6"){
                        cout << "│ |V";
                    }else if(tab[j]=="<4" || tab[j]=="<5" || tab[j]=="<6"){
                        cout << "│" << flecheGauche;
                    }else if(tab[j]=="<1" || tab[j]=="<7" || tab[j]==">1" || tab[j]==">7"){
                        cout << "│---";
                    }else if(tab[j]=="<2" || tab[j]==">2"){
                        cout << "│-- ";
                    }else if(tab[j]=="<3" || tab[j]==">3"){
                        cout << "│ --";
                    }else if(tab[j]==">4" || tab[j]==">5" || tab[j]==">6"){
                        cout << "│" << flecheDroite;
                    }else if((tab[j]=="@G" || tab[j]=="G@") && emoji==true){
                        cout << "│-💥";
                    }else if(tab[j]=="@G" || tab[j]=="G@"){
                        cout << "│-@G";
                    }else if((tab[j]=="MP" || tab[j]=="PM" || tab[j]=="GP" || tab[j]=="PG" || tab[j]=="BP" || tab[j]=="BP" ) && emoji==true){
                        cout << "│ 😀";
                    }else if(tab[j]=="w2"){
                        cout << "│-w ";
                    }else if(tab[j]=="w3"){
                        cout << "│ w-";
                    }else if(tab[j]=="w6" || tab[j]=="w5"){
                        cout << "│ w ";
                    }else if(tab[j]=="W2"){
                        cout << "│-W ";
                    }else if(tab[j]=="W3"){
                        cout << "│ W-";
                    }else if(tab[j]=="W6" || tab[j]=="W5"){
                        cout << "│ W ";
                    }else if((tab[j]=="04" || tab[j]=="05" || tab[j]=="06") && emoji==true){
                        cout << "│ 💣";
                    }else if((tab[j]=="01" || tab[j]=="02")  && emoji==true){
                        cout << "│-💣";
                    }else if((tab[j]=="07" || tab[j]=="03")  && emoji==true){
                        cout << "│💣-";
                    }else if(tab[j]=="04" || tab[j]=="05" || tab[j]=="06"){
                        cout << "│ 0 ";
                    }else if(tab[j]=="01" || tab[j]=="07"){
                        cout << "│-0-";
                    }else if(tab[j]=="02"){
                        cout << "│-0 ";
                    }else if(tab[j]=="03"){
                        cout << "│ 0-";
                    }else if(tab[j]=="X1" || tab[j]=="X7"){
                        cout << "│-X-";
                    }else if(tab[j]=="X2"){
                        cout << "│-X ";
                    }else if(tab[j]=="X3"){
                        cout << "│ X-";
                    }else if((tab[j]=="WG" || tab[j]=="wG" && emoji==true)){
                        cout << "│ " << tab[j][0] << " ";
                    }else cout << "│ " << tab[j][0] << tab[j][1];
                }else if(taille==3){
                    if(tab[j]=="XP0" && emoji==true){
                        cout << "│X💣";
                    }else if(tab[j]=="XP0"){
                        cout << "│XP0";
                    }else if((tab[j]=="XMP" || tab[j]=="XPM") && emoji==true){
                        cout << "│X👹";
                    }else if((tab[j]=="XBP" || tab[j]=="XPB") && emoji==true){
                        cout << "│X🏹";
                    }else if((tab[j]=="XGP" || tab[j]=="XPG") && emoji==true){
                        cout << "│X👻";
                    }else if((tab[j]=="XP2" || tab[j]=="XP1" || tab[j]=="XM2" || tab[j]=="XM1" || tab[j]=="XG2" || tab[j]=="XG1" || tab[j]=="XB2" || tab[j]=="XB1") && emoji==true){
                        cout << "│-X ";
                    }else if((tab[j]=="XP3" || tab[j]=="XP7" || tab[j]=="XM3" || tab[j]=="XM7" || tab[j]=="XG3" || tab[j]=="XG7" || tab[j]=="XB3" || tab[j]=="XB7") && emoji==true){
                        cout << "│ X-";
                    }else if((tab[j]=="XP4" || tab[j]=="XP5" || tab[j]=="XP6" || tab[j]=="XM4" || tab[j]=="XM5" || tab[j]=="XM6" || tab[j]=="XB4" || tab[j]=="XB5" || tab[j]=="XB6" || tab[j]=="XG4" || tab[j]=="XG5" || tab[j]=="XG6" || tab[j]=="XB4" || tab[j]=="XB5" || tab[j]=="XB6") && emoji==true){
                        cout << "│ X ";
                    }else if(tab[j][0]=='X' && (tab[j][2]=='1' ||tab[j][2]=='2')){ 
                        cout << "│-X"<<tab[j][1];
                    }else if(tab[j][0]=='X' && (tab[j][2]=='7' ||tab[j][2]=='3')){
                        cout << "│X"<<tab[j][1]<<"-";
                    }else if(tab[j][0]=='X' && (tab[j][2]='4' || tab[j][2]=='5' ||tab[j][2]=='6')){
                        cout << "│ X"<<tab[j][1];
                    }else if((tab[j]=="MLG" || tab[j]=="MLM" || tab[j]=="MLB" || tab[j]=="ML>" || tab[j]=="ML<" || tab[j]=="MLA" || tab[j]=="MLV" || tab[j]=="ML4" || tab[j]=="ML5" || tab[j]=="ML6") && emoji==true){
                        if(tab[j][2]=='A') cout << "│💖A";
                        else if (tab[j][2]=='V') cout << "│💖V";
                        else cout << "│ 💖";
                    }else if((tab[j]=="SPG" || tab[j]=="SPM" || tab[j]=="SPB" || tab[j]=="SP>" || tab[j]=="SP<" || tab[j]=="SPA" || tab[j]=="SPV" || tab[j]=="SP4" || tab[j]=="SP5" || tab[j]=="SP6") && emoji==true){
                        if(tab[j][2]=='A') cout << "│👟A";
                        else if (tab[j][2]=='V') cout << "│👟V";
                        else cout << "│ 👟";
                    }else if((tab[j]=="PUG" || tab[j]=="PUB" || tab[j]=="PUM" || tab[j]=="PU>" || tab[j]=="PU<" || tab[j]=="PUA" || tab[j]=="PUV" || tab[j]=="PU4" || tab[j]=="PU5" || tab[j]=="PU6") && emoji==true){
                        if(tab[j][2]=='A') cout << "│🔥A";
                        else if (tab[j][2]=='V') cout << "│🔥V";
                        else cout << "│ 🔥";
                    }else if((tab[j]=="MBG" || tab[j]=="MBM" || tab[j]=="MBB" || tab[j]=="MB>" || tab[j]=="MB<" || tab[j]=="MBA" || tab[j]=="MBV" || tab[j]=="MB4" || tab[j]=="MB5" || tab[j]=="MB6") && emoji==true){
                        if(tab[j][2]=='A') cout << "│🔮A";
                        else if (tab[j][2]=='V') cout << "│🔮V";
                        else cout << "│ 🔮";
                    }else if((tab[j]=="SCG" || tab[j]=="SCM" || tab[j]=="SCB" || tab[j]=="SC>" || tab[j]=="SC<" || tab[j]=="SCA" || tab[j]=="SCV" || tab[j]=="SC4" || tab[j]=="SC5" || tab[j]=="SC6") && emoji==true){
                        if(tab[j][2]=='A') cout << "│📏A";
                        else if (tab[j][2]=='V') cout << "│📏V";
                        else cout << "│ 📏";
                    }else if((tab[j]=="ML2" || tab[j]=="ML1") && emoji==true){
                        cout << "│-💖";
                    }else if((tab[j]=="ML3" || tab[j]=="ML7") && emoji==true){
                        cout << "│💖-";
                    }else if((tab[j]=="PU2" || tab[j]=="PU1") && emoji==true){
                        cout << "│-🔥";
                    }else if((tab[j]=="PU3" || tab[j]=="PU7") && emoji==true){
                        cout << "│🔥-";
                    }else if((tab[j]=="MB2" || tab[j]=="MB1") && emoji==true){
                        cout << "│-🔮";
                    }else if((tab[j]=="MB3" || tab[j]=="MB7") && emoji==true){
                        cout << "│🔮-";
                    }else if((tab[j]=="SP2" || tab[j]=="SP1") && emoji==true){
                        cout << "│-👟";
                    }else if((tab[j]=="SP3" || tab[j]=="SP7") && emoji==true){
                        cout << "│👟-";
                    }else if((tab[j]=="SC2" || tab[j]=="SC1") && emoji==true){
                        cout << "│-📏";
                    }else if((tab[j]=="SC3" || tab[j]=="SC7") && emoji==true){
                        cout << "│📏-";
                    }else if(tab[j]=="ML1" || tab[j]=="ML2" || tab[j]=="PU1" || tab[j]=="PU2" || tab[j]=="MB1" || tab[j]=="MB2" || tab[j]=="SP1" || tab[j]=="SP2" || tab[j]=="SC1" || tab[j]=="SC2"){
                        cout << "│-" << tab[j][0] << tab[j][1];
                    }else if(tab[j]=="ML7" || tab[j]=="ML3" || tab[j]=="PU7" || tab[j]=="PU3" || tab[j]=="MB7" || tab[j]=="MB3" || tab[j]=="SP7" || tab[j]=="SP3" || tab[j]=="SC7" || tab[j]=="SC3"){
                        cout << "│" << tab[j][0] << tab[j][1] << "-";
                    }else if(tab[j]=="ML4" || tab[j]=="ML5" || tab[j]=="ML6" || tab[j]=="PU4" || tab[j]=="PU5" || tab[j]=="PU6" || tab[j]=="MB4" || tab[j]=="MB5" || tab[j]=="MB6" || tab[j]=="SP4" || tab[j]=="SP5" || tab[j]=="SP6"  || tab[j]=="SC4" || tab[j]=="SC5" || tab[j]=="SC6"){
                        cout << "│ " << tab[j][0] << tab[j][1];
                    }else if(tab[j]=="PU1" || tab[j]=="PU2" || tab[j]=="PU1" || tab[j]=="PU2" || tab[j]=="MB1" || tab[j]=="MB2" || tab[j]=="SP1" || tab[j]=="SP2" || tab[j]=="SC1" || tab[j]=="SC2"){
                        cout << "│-" << tab[j][0] << tab[j][1];
                    }else if(tab[j]=="PU7" || tab[j]=="PU3" || tab[j]=="PU7" || tab[j]=="PU3" || tab[j]=="MB7" || tab[j]=="MB3" || tab[j]=="SP7" || tab[j]=="SP3" || tab[j]=="SC7" || tab[j]=="SC3"){
                        cout << "│" << tab[j][0] << tab[j][1] << "-";
                    }else if(tab[j]=="PU4" || tab[j]=="PU5" || tab[j]=="PU6" || tab[j]=="PU4" || tab[j]=="PU5" || tab[j]=="PU6" || tab[j]=="MB4" || tab[j]=="MB5" || tab[j]=="MB6" || tab[j]=="SP4" || tab[j]=="SP5" || tab[j]=="SP6"  || tab[j]=="SC4" || tab[j]=="SC5" || tab[j]=="SC6"){
                        cout << "│ " << tab[j][0] << tab[j][1];
                    }else if(tab[j]=="ML>" ||tab[j]=="ML<"){
                        cout << "│ ML";
                    }else if(tab[j]=="PU>" ||tab[j]=="PU<"){
                        cout << "│ PU";
                    }else if(tab[j]=="MB>" ||tab[j]=="MB<"){
                        cout << "│ MB";
                    }else if(tab[j]=="SP>" ||tab[j]=="SP<"){
                        cout << "│ SP";
                    }else if(tab[j]=="SC>" ||tab[j]=="SC<"){
                        cout << "│ SC";
                    }else if((tab[j]=="WG2" || tab[j]=="wG2") && emoji==true){
                        cout << "│-" << tab[j][0] << " ";
                    }else if((tab[j]=="WG3" || tab[j]=="wG3") && emoji==true){
                        cout << "│ " << tab[j][0] << "-";
                    }else if(tab[j]=="WG2" || tab[j]=="wG2"){
                        cout << "│-" << tab[j][0] << tab[j][1];
                    }else if(tab[j]=="WG3" || tab[j]=="wG3"){
                        cout << "│" << tab[j][0] << tab[j][1] << "-";
                    }else if((tab[j]=="WG5" || tab[j]=="WG6" || tab[j]=="wG5" || tab[j]=="wG6") && emoji==true){
                        cout << "│ " << tab[j][0] << " ";
                    }else if(tab[j]=="WG5" || tab[j]=="WG6" || tab[j]=="wG5" || tab[j]=="wG6"){
                        cout << "│ " << tab[j][0] << tab[j][1];
                    }else if((tab[j]=="GP0" || tab[j]=="PG0" || tab[j]=="BP0" || tab[j]=="PB0" || tab[j]=="MP0" || tab[j]=="PM0") && emoji==true){
                        cout << "│ 💣";
                    }else if((tab[j]=="PG1" || tab[j]=="PG2" || tab[j]=="PM1" || tab[j]=="PM2" || tab[j]=="PB1" || tab[j]=="PB2" || tab[j]=="GP1" || tab[j]=="GP2" || tab[j]=="MP1" || tab[j]=="MP2" || tab[j]=="BP1" || tab[j]=="BP2") && emoji==true){
                        cout << "│-😀";
                    }else if((tab[j]=="PG3" || tab[j]=="PG7" || tab[j]=="PM3" || tab[j]=="PM7" || tab[j]=="PB3" || tab[j]=="PB7" || tab[j]=="GP3" || tab[j]=="GP7" || tab[j]=="MP3" || tab[j]=="MP7" || tab[j]=="BP3" || tab[j]=="BP7") && emoji==true){
                        cout << "│😀-";
                    }else if((tab[j]=="PG4" || tab[j]=="PG5" || tab[j]=="PG6" || tab[j]=="PM4" || tab[j]=="PM5" || tab[j]=="PM6" || tab[j]=="PB4" || tab[j]=="PB5" || tab[j]=="PB6" || tab[j]=="GP4" || tab[j]=="GP5" || tab[j]=="GP6" || tab[j]=="MP4" || tab[j]=="MP5" || tab[j]=="MP6" || tab[j]=="BP4" || tab[j]=="BP5" || tab[j]=="BP6") && emoji==true){
                        cout << "│ 😀";
                    }else if(tab[j]=="PG1" || tab[j]=="PG2" || tab[j]=="PM1" || tab[j]=="PM2" || tab[j]=="PB1" || tab[j]=="PB2" || tab[j]=="GP1" || tab[j]=="GP2" || tab[j]=="MP1" || tab[j]=="MP2" || tab[j]=="BP1" || tab[j]=="BP2"){
                        cout << "│-" << tab[j][0] << tab[j][1];
                    }else if(tab[j]=="PG3" || tab[j]=="PG7" || tab[j]=="PM3" || tab[j]=="PM7" || tab[j]=="PB3" || tab[j]=="PB7" || tab[j]=="GP3" || tab[j]=="GP7" || tab[j]=="MP3" || tab[j]=="MP7" || tab[j]=="BP3" || tab[j]=="BP7"){
                        cout << "│" << tab[j][0] << tab[j][1] << "-";
                    }else if(tab[j]=="PG4" || tab[j]=="PG5" || tab[j]=="PG6" || tab[j]=="PM4" || tab[j]=="PM5" || tab[j]=="PM6" || tab[j]=="PB4" || tab[j]=="PB5" || tab[j]=="PB6" || tab[j]=="GP4" || tab[j]=="GP5" || tab[j]=="GP6" || tab[j]=="MP4" || tab[j]=="MP5" || tab[j]=="MP6" || tab[j]=="BP4" || tab[j]=="BP5" || tab[j]=="BP6"){
                        cout << "│ " << tab[j][0] << tab[j][1];
                    }else{
                        cout << "│" << tab[j];
                    }
                }else if(taille==4){
                    if((tab[j]=="ML<1" || tab[j]=="ML>1" || tab[j]=="ML<2" || tab[j]=="ML>2") && emoji==true){
                        cout << "│-💖";
                    }else if(tab[j]=="ML<1" || tab[j]=="ML>1" || tab[j]=="ML<2" || tab[j]=="ML>2"){
                        cout << "│-ML";
                    }else if((tab[j]=="ML<4" || tab[j]=="ML>4" || tab[j]=="ML<6" || tab[j]=="ML>6" || tab[j]=="ML<5" || tab[j]=="ML>5") && emoji==true){
                        cout << "│ 💖";
                    }else if((tab[j]=="ML<3" || tab[j]=="ML>3" || tab[j]=="ML<7" || tab[j]=="ML>7") && emoji==true){
                        cout << "│💖-";
                    }else if(tab[j]=="ML<3" || tab[j]=="ML>3" || tab[j]=="ML<7" || tab[j]=="ML>7"){
                        cout << "│ML-";
                    }else if(tab[j]=="MLA1" || tab[j]=="MLA2" || tab[j]=="MLA7"){
                        cout << "│--A";
                    }else if(tab[j]=="MLA3"){
                        cout << "│ -A";
                    }else if((tab[j]=="MLA4" || tab[j]=="MLA5" || tab[j]=="MLA6") && emoji==true){
                        cout << "│💖A";
                    }else if(tab[j]=="MLA4" || tab[j]=="MLA5" || tab[j]=="MLA6"){
                        cout << "│MLA";
                    }else if((tab[j]=="MLV4" || tab[j]=="MLV5" || tab[j]=="MLV6") && emoji==true){
                        cout << "│💖V";
                    }else if(tab[j]=="MLV4" || tab[j]=="MLV5" || tab[j]=="MLV6"){
                        cout << "│MLV";
                    }else if(tab[j]=="MLV1" || tab[j]=="MLV2" || tab[j]=="MLV7"){
                        cout << "│--V";
                    }else if(tab[j]=="MLV3"){
                        cout << "│ -V";
                    }else if(tab[j]=="ML>4" || tab[j]=="ML>5" || tab[j]=="ML>6" || tab[j]=="ML<4" || tab[j]=="ML<5" || tab[j]=="ML<6"){
                        cout << "│ ML";
                    }else if((tab[j]=="PU<1" || tab[j]=="PU>1" || tab[j]=="PU<2" || tab[j]=="PU>2") && emoji==true){
                        cout << "│-🔥";
                    }else if(tab[j]=="PU<1" || tab[j]=="PU>1" || tab[j]=="PU<2" || tab[j]=="PU>2"){
                        cout << "│-PU";
                    }else if((tab[j]=="PU<4" || tab[j]=="PU>4" || tab[j]=="PU<6" || tab[j]=="PU>6" || tab[j]=="PU<5" || tab[j]=="PU>5") && emoji==true){
                        cout << "│ 🔥";
                    }else if((tab[j]=="PU<3" || tab[j]=="PU>3" || tab[j]=="PU<7" || tab[j]=="PU>7") && emoji==true){
                        cout << "│🔥-";
                    }else if(tab[j]=="PU<3" || tab[j]=="PU>3" || tab[j]=="PU<7" || tab[j]=="PU>7"){
                        cout << "│PU-";
                    }else if(tab[j]=="PUA1" || tab[j]=="PUA2" || tab[j]=="PUA7"){
                        cout << "│--A";
                    }else if(tab[j]=="PUA3"){
                        cout << "│ -A";
                    }else if((tab[j]=="PUA4" || tab[j]=="PUA5" || tab[j]=="PUA6") && emoji==true){
                        cout << "│🔥A";
                    }else if(tab[j]=="PUA4" || tab[j]=="PUA5" || tab[j]=="PUA6"){
                        cout << "│PUA";
                    }else if((tab[j]=="PUV4" || tab[j]=="PUV5" || tab[j]=="PUV6") && emoji==true){
                        cout << "│🔥V";
                    }else if(tab[j]=="PUV4" || tab[j]=="PUV5" || tab[j]=="PUV6"){
                        cout << "│PUV";
                    }else if(tab[j]=="PUV1" || tab[j]=="PUV2" || tab[j]=="PUV7"){
                        cout << "│--V";
                    }else if(tab[j]=="PUV3"){
                        cout << "│ -V";
                    }else if(tab[j]=="PU>4" || tab[j]=="PU>5" || tab[j]=="PU>6" || tab[j]=="PU<4" || tab[j]=="PU<5" || tab[j]=="PU<6"){
                        cout << "│ PU";
                    }else if((tab[j]=="MB<1" || tab[j]=="MB>1" || tab[j]=="MB<2" || tab[j]=="MB>2") && emoji==true){
                        cout << "│-🔮";
                    }else if(tab[j]=="MB<1" || tab[j]=="MB>1" || tab[j]=="MB<2" || tab[j]=="MB>2"){
                        cout << "│-MB";
                    }else if((tab[j]=="MB<4" || tab[j]=="MB>4" || tab[j]=="MB<6" || tab[j]=="MB>6" || tab[j]=="MB<5" || tab[j]=="MB>5") && emoji==true){
                        cout << "│ 🔮";
                    }else if((tab[j]=="MB<3" || tab[j]=="MB>3" || tab[j]=="MB<7" || tab[j]=="MB>7") && emoji==true){
                        cout << "│🔮-";
                    }else if(tab[j]=="MB<3" || tab[j]=="MB>3" || tab[j]=="MB<7" || tab[j]=="MB>7"){
                        cout << "│MB-";
                    }else if(tab[j]=="MBA1" || tab[j]=="MBA2" || tab[j]=="MBA7"){
                        cout << "│--A";
                    }else if(tab[j]=="MBA3"){
                        cout << "│ -A";
                    }else if((tab[j]=="MBA4" || tab[j]=="MBA5" || tab[j]=="MBA6") && emoji==true){
                        cout << "│🔮A";
                    }else if(tab[j]=="MBA4" || tab[j]=="MBA5" || tab[j]=="MBA6"){
                        cout << "│MBA";
                    }else if((tab[j]=="MBV4" || tab[j]=="MBV5" || tab[j]=="MBV6") && emoji==true){
                        cout << "│🔮V";
                    }else if(tab[j]=="MBV4" || tab[j]=="MBV5" || tab[j]=="MBV6"){
                        cout << "│MBV";
                    }else if(tab[j]=="MBV1" || tab[j]=="MBV2" || tab[j]=="MBV7"){
                        cout << "│--V";
                    }else if(tab[j]=="MBV3"){
                        cout << "│ -V";
                    }else if(tab[j]=="MB>4" || tab[j]=="MB>5" || tab[j]=="MB>6" || tab[j]=="MB<4" || tab[j]=="MB<5" || tab[j]=="MB<6"){
                        cout << "│ MB";
                    }else if((tab[j]=="SP<1" || tab[j]=="SP>1" || tab[j]=="SP<2" || tab[j]=="SP>2") && emoji==true){
                        cout << "│-👟";
                    }else if(tab[j]=="SP<1" || tab[j]=="SP>1" || tab[j]=="SP<2" || tab[j]=="SP>2"){
                        cout << "│-SP";
                    }else if((tab[j]=="SP<4" || tab[j]=="SP>4" || tab[j]=="SP<6" || tab[j]=="SP>6" || tab[j]=="SP<5" || tab[j]=="SP>5") && emoji==true){
                        cout << "│ 👟";
                    }else if((tab[j]=="SP<3" || tab[j]=="SP>3" || tab[j]=="SP<7" || tab[j]=="SP>7") && emoji==true){
                        cout << "│👟-";
                    }else if(tab[j]=="SP<3" || tab[j]=="SP>3" || tab[j]=="SP<7" || tab[j]=="SP>7"){
                        cout << "│SP-";
                    }else if(tab[j]=="SPA1" || tab[j]=="SPA2" || tab[j]=="SPA7"){
                        cout << "│--A";
                    }else if(tab[j]=="SPA3"){
                        cout << "│ -A";
                    }else if((tab[j]=="SPA4" || tab[j]=="SPA5" || tab[j]=="SPA6") && emoji==true){
                        cout << "│👟A";
                    }else if(tab[j]=="SPA4" || tab[j]=="SPA5" || tab[j]=="SPA6"){
                        cout << "│SPA";
                    }else if((tab[j]=="SPV4" || tab[j]=="SPV5" || tab[j]=="SPV6") && emoji==true){
                        cout << "│👟V";
                    }else if(tab[j]=="SPV4" || tab[j]=="SPV5" || tab[j]=="SPV6"){
                        cout << "│SPV";
                    }else if(tab[j]=="SPV1" || tab[j]=="SPV2" || tab[j]=="SPV7"){
                        cout << "│--V";
                    }else if(tab[j]=="SPV3"){
                        cout << "│ -V";
                    }else if(tab[j]=="SP>4" || tab[j]=="SP>5" || tab[j]=="SP>6" || tab[j]=="SP<4" || tab[j]=="SP<5" || tab[j]=="SP<6"){
                        cout << "│ SP";
                    }else if((tab[j]=="SC<1" || tab[j]=="SC>1" || tab[j]=="SC<2" || tab[j]=="SC>2") && emoji==true){
                        cout << "│-📏";
                    }else if(tab[j]=="SC<1" || tab[j]=="SC>1" || tab[j]=="SC<2" || tab[j]=="SC>2"){
                        cout << "│-SC";
                    }else if((tab[j]=="SC<4" || tab[j]=="SC>4" || tab[j]=="SC<6" || tab[j]=="SC>6" || tab[j]=="SC<5" || tab[j]=="SC>5") && emoji==true){
                        cout << "│ 📏";
                    }else if((tab[j]=="SC<3" || tab[j]=="SC>3" || tab[j]=="SC<7" || tab[j]=="SC>7") && emoji==true){
                        cout << "│📏-";
                    }else if(tab[j]=="SC<3" || tab[j]=="SC>3" || tab[j]=="SC<7" || tab[j]=="SC>7"){
                        cout << "│SC-";
                    }else if(tab[j]=="SCA1" || tab[j]=="SCA2" || tab[j]=="SCA7"){
                        cout << "│--A";
                    }else if(tab[j]=="SCA3"){
                        cout << "│ -A";
                    }else if((tab[j]=="SCA4" || tab[j]=="SCA5" || tab[j]=="SCA6") && emoji==true){
                        cout << "│📏A";
                    }else if(tab[j]=="SCA4" || tab[j]=="SCA5" || tab[j]=="SCA6"){
                        cout << "│SCA";
                    }else if((tab[j]=="SCV4" || tab[j]=="SCV5" || tab[j]=="SCV6") && emoji==true){
                        cout << "│📏V";
                    }else if(tab[j]=="SCV4" || tab[j]=="SCV5" || tab[j]=="SCV6"){
                        cout << "│SCV";
                    }else if(tab[j]=="SCV1" || tab[j]=="SCV2" || tab[j]=="SCV7"){
                        cout << "│--V";
                    }else if(tab[j]=="SCV3"){
                        cout << "│ -V";
                    }else if(tab[j]=="SC>4" || tab[j]=="SC>5" || tab[j]=="SC>6" || tab[j]=="SC<4" || tab[j]=="SC<5" || tab[j]=="SC<6"){
                        cout << "│ SP";
                    }else if((tab[j]=="MLB1" || tab[j]=="MLB2" || tab[j]=="MLG1" || tab[j]=="MLG2" || tab[j]=="MLM1" || tab[j]=="MLM2") && emoji==true){
                        cout << "│-💖";
                    }else if((tab[j]=="MLB3" || tab[j]=="MLB7" || tab[j]=="MLG3" || tab[j]=="MLG7" || tab[j]=="MLM3" || tab[j]=="MLM7") && emoji==true){
                        cout << "│💖-";
                    }else if((tab[j]=="MLB4" || tab[j]=="MLB6" || tab[j]=="MLG4" || tab[j]=="MLG6" || tab[j]=="MLM4" || tab[j]=="MLM6") && emoji==true){
                        cout << "│ 💖";
                    }else if((tab[j]=="PUB1" || tab[j]=="PUB2" || tab[j]=="PUG1" || tab[j]=="PUG2" || tab[j]=="PUM1" || tab[j]=="PUM2") && emoji==true){
                        cout << "│-🔥";
                    }else if((tab[j]=="PUB3" || tab[j]=="PUB7" || tab[j]=="PUG3" || tab[j]=="PUG7" || tab[j]=="PUM3" || tab[j]=="PUM7") && emoji==true){
                        cout << "│🔥-";
                    }else if((tab[j]=="PUB4" || tab[j]=="PUB6" || tab[j]=="PUG4" || tab[j]=="PUG6" || tab[j]=="PUM4" || tab[j]=="PUM6") && emoji==true){
                        cout << "│ 🔥";
                    }else if((tab[j]=="MBB1" || tab[j]=="MBB2" || tab[j]=="MBG1" || tab[j]=="MBG2" || tab[j]=="MBM1" || tab[j]=="MBM2") && emoji==true){
                        cout << "│-🔮";
                    }else if((tab[j]=="MBB3" || tab[j]=="MBB7" || tab[j]=="MBG3" || tab[j]=="MBG7" || tab[j]=="MBM3" || tab[j]=="MBM7") && emoji==true){
                        cout << "│🔮-";
                    }else if((tab[j]=="MBB4" || tab[j]=="MBB6" || tab[j]=="MBG4" || tab[j]=="MBG6" || tab[j]=="MBM4" || tab[j]=="MBM6") && emoji==true){
                        cout << "│ 🔮";
                    }else if((tab[j]=="SPB1" || tab[j]=="SPB2" || tab[j]=="SPG1" || tab[j]=="SPG2" || tab[j]=="SPM1" || tab[j]=="SPM2") && emoji==true){
                        cout << "│-👟";
                    }else if((tab[j]=="SPB3" || tab[j]=="SPB7" || tab[j]=="SPG3" || tab[j]=="SPG7" || tab[j]=="SPM3" || tab[j]=="SPM7") && emoji==true){
                        cout << "│👟-";
                    }else if((tab[j]=="SPB4" || tab[j]=="SPB6" || tab[j]=="SPG4" || tab[j]=="SPG6" || tab[j]=="SPM4" || tab[j]=="SPM6") && emoji==true){
                        cout << "│ 👟";
                    }else if((tab[j]=="SCB1" || tab[j]=="SCB2" || tab[j]=="SCG1" || tab[j]=="SCG2" || tab[j]=="SCM1" || tab[j]=="SCM2") && emoji==true){
                        cout << "│-📏";
                    }else if((tab[j]=="SCB3" || tab[j]=="SCB7" || tab[j]=="SCG3" || tab[j]=="SCG7" || tab[j]=="SCM3" || tab[j]=="SCM7") && emoji==true){
                        cout << "│📏-";
                    }else if((tab[j]=="SCB4" || tab[j]=="SCB6" || tab[j]=="SCG4" || tab[j]=="SCG6" || tab[j]=="SCM4" || tab[j]=="SCM6") && emoji==true){
                        cout << "│ 📏";
                    }else if((tab[j]=="MLB5" || tab[j]=="PUB5" || tab[j]=="MBB5" || tab[j]=="SCB5" || tab[j]=="SPB5") && emoji==true){
                        cout << "│ 🏹";
                    }else if((tab[j]=="MLG5" || tab[j]=="PUG5" || tab[j]=="MBG5" || tab[j]=="SCG5" || tab[j]=="SPG5") && emoji==true){
                        cout << "│ 👻";
                    }else if((tab[j]=="MLM5" || tab[j]=="PUM5" || tab[j]=="MBM5" || tab[j]=="SCM5" || tab[j]=="SPM5") && emoji==true){
                        cout << "│ 👹";
                    }else if(tab[j]=="MLB1" || tab[j]=="MLB2" || tab[j]=="MLG1" || tab[j]=="MLG2" || tab[j]=="MLM1" || tab[j]=="MLM2"){
                        cout << "│-ML";
                    }else if(tab[j]=="MLB3" || tab[j]=="MLB7" || tab[j]=="MLG3" || tab[j]=="MLG7" || tab[j]=="MLM3" || tab[j]=="MLM7"){
                        cout << "│ML-";
                    }else if(tab[j]=="MLB4" || tab[j]=="MLB6" || tab[j]=="MLB5" || tab[j]=="MLG4" || tab[j]=="MLG6" || tab[j]=="MLG5" || tab[j]=="MLM4" || tab[j]=="MLM6" || tab[j]=="MLM5"){
                        cout << "│ML" << tab[j][2];
                    }else if(tab[j]=="PUB1" || tab[j]=="PUB2" || tab[j]=="PUG1" || tab[j]=="PUG2" || tab[j]=="PUM1" || tab[j]=="PUM2"){
                        cout << "│-PU";
                    }else if(tab[j]=="PUB3" || tab[j]=="PUB7" || tab[j]=="PUG3" || tab[j]=="PUG7" || tab[j]=="PUM3" || tab[j]=="PUM7"){
                        cout << "│PU-";
                    }else if(tab[j]=="PUB4" || tab[j]=="PUB6" || tab[j]=="PUB5" || tab[j]=="PUG4" || tab[j]=="PUG6" || tab[j]=="PUG5" || tab[j]=="PUM4" || tab[j]=="PUM6" || tab[j]=="PUM5"){
                        cout << "│PU" << tab[j][2];
                    }else if(tab[j]=="SCB1" || tab[j]=="SCB2" || tab[j]=="SCG1" || tab[j]=="SCG2" || tab[j]=="SCM1" || tab[j]=="SCM2"){
                        cout << "│-SC";
                    }else if(tab[j]=="SCB3" || tab[j]=="SCB7" || tab[j]=="SCG3" || tab[j]=="SCG7" || tab[j]=="SCM3" || tab[j]=="SCM7"){
                        cout << "│SC-";
                    }else if(tab[j]=="SCB4" || tab[j]=="SCB6" || tab[j]=="SCB5" || tab[j]=="SCG4" || tab[j]=="SCG6" || tab[j]=="SCG5" || tab[j]=="SCM4" || tab[j]=="SCM6" || tab[j]=="SCM5"){
                        cout << "│SC" << tab[j][2];
                    }else if(tab[j]=="SPB1" || tab[j]=="SPB2" || tab[j]=="SPG1" || tab[j]=="SPG2" || tab[j]=="SPM1" || tab[j]=="SPM2"){
                        cout << "│-SP";
                    }else if(tab[j]=="SPB3" || tab[j]=="SPB7" || tab[j]=="SPG3" || tab[j]=="SPG7" || tab[j]=="SPM3" || tab[j]=="SPM7"){
                        cout << "│SP-";
                    }else if(tab[j]=="SPB4" || tab[j]=="SPB6" || tab[j]=="SPB5" || tab[j]=="SPG4" || tab[j]=="SPG6" || tab[j]=="SPG5" || tab[j]=="SPM4" || tab[j]=="SPM6" || tab[j]=="SPM5"){
                        cout << "│SP" << tab[j][2];
                    }else if(tab[j]=="MBB1" || tab[j]=="MBB2" || tab[j]=="MBG1" || tab[j]=="MBG2" || tab[j]=="MBM1" || tab[j]=="MBM2"){
                        cout << "│-MB";
                    }else if(tab[j]=="MBB3" || tab[j]=="MBB7" || tab[j]=="MBG3" || tab[j]=="MBG7" || tab[j]=="MBM3" || tab[j]=="MBM7"){
                        cout << "│MB-";
                    }else if(tab[j]=="MBB4" || tab[j]=="MBB6" || tab[j]=="MBB5" || tab[j]=="MBG4" || tab[j]=="MBG6" || tab[j]=="MBG5" || tab[j]=="MBM4" || tab[j]=="MBM6" || tab[j]=="MBM5"){
                        cout << "│MB" << tab[j][2];
                    }else{
                        cout << "│" << tab[j][0] << tab[j][1] << tab[j][2];
                    }
                }
            }
            cout << "│";
            if(y==1){
                if(emoji==true) cout << "  Puissance des bombes (🔥) = " << puissanceBombe;
                else cout << "  Puissance des bombes (PU) = " << puissanceBombe;
                y++;
            }
            cout << endl;
            i+=nbColonne;
            ligne++;
        }
    }
}


//Lecture du fichier map.txt, valeur envoyer dans le tableau tab
void Map::lectureMap(){
    monFlux.open(nomFichier, fstream::in);
    if(monFlux.is_open()){
        string ligne;
        int i=0;
        while(getline(monFlux, ligne)){
            for(int j=0;j<ligne.size();j++){
                if(ligne[j]!=',' && ligne[j]!='\n' && ligne[j]!='\0'){
                    tab[i]=ligne[j];
                    if(ligne[j+1]!=',' && ligne[j+1]!='\n' && ligne[j+1]!='\0'){
                        tab[i]+=ligne[j+1];
                        if(ligne[j+2]!=',' && ligne[j+2]!='\n' && ligne[j+2]!='\0'){
                            tab[i]+=ligne[j+2];
                            if(ligne[j+3]!=',' && ligne[j+3]!='\n' && ligne[j+3]!='\0'){
                                tab[i]+=ligne[j+3];
                                j++;
                            }
                            j++;
                        }
                        j++;
                    }
                    i++;
                }
            }
        }
        monFlux.close();
    }else cout << "Impossible d'ouvrir le fichier " << nomFichier << endl;
}



//Actualise le fichier map.txt
void Map::actualiserMap(){
    monFlux.open(nomFichier, fstream::out);
    if(monFlux.is_open()){
        for(int i=0, j=0, k=0;i<nbCaractere;i++){
            monFlux << tab[i];

            if(i!=nbColonne+(nbColonne*k)-1){
                monFlux << ',';
                k++;
            }
            
            if(i==nbColonne+(nbColonne*j)-1){
                monFlux << endl;
                j++;
            }
        }
        monFlux.close();
    }else cout << "Impossible d'ouvrir le fichier " << nomFichier << endl;
}



//Permet de savoir le nombre de ligne, le nombre de colonne et la taille du tableau
void Map::infoMap(){
    monFlux.open(nomFichier, fstream::in);
    if(monFlux.is_open()){
        int nbLignes=0, nbColonnes=0, nbCaracteres=0;
        string ligne;
        while(getline(monFlux, ligne)){
            for(int j=0;j<ligne.size();j++){
                if(ligne[j]!=',' && ligne[j]!='\n' && ligne[j]!='\0'){
                    nbCaracteres++;
                    if(ligne[j+1]!=',' && ligne[j+1]!='\n' && ligne[j+1]!='\0'){
                        if(ligne[j+2]!=',' && ligne[j+2]!='\n' && ligne[j+2]!='\0'){
                            j++;
                        }
                        j++;
                    }
                }
            }
            nbLignes++;
        }
        if(nbLignes!=0) nbColonnes=nbCaracteres/nbLignes;
        nbLigne=nbLignes;
        nbCaractere=nbCaracteres;
        nbColonne=nbColonnes;
        monFlux.close();
    }else cout << "Impossible d'ouvrir le fichier " << nomFichier << endl;
}


void Map::afficherPersoObjet(int pos, char lettre)
{
    if(tab[pos] == " ")
        tab[pos] = lettre;
    else
        tab[pos] += lettre;
}





// Permet de bouger la position du personnage dans le tableau de la map en adaptant les cases selon les différents élements rencontrés
void Map::gestionDeplacementMap(int pos, int x)
{
    if(tab[pos+x]==" "){                            //si case d'arriver est vide
        if(tab[pos].size()==1){                     //si 1 seul lettre dans case depart
            tab[pos+x]=tab[pos];                    //case d'arriver = case de depart
            tab[pos]=' ';                           //case de depart = vide
        }else if(tab[pos].size()==2){               //si 2 lettres dans case depart
            if((tab[pos][0]=='W' && tab[pos][1]=='G') || (tab[pos][0]=='w' && tab[pos][1]=='G') || (tab[pos][0]=='0' && tab[pos][1]=='<') || (tab[pos][0]=='0' && tab[pos][1]=='>') || (tab[pos][0]=='0' && tab[pos][1]=='A') || (tab[pos][0]=='0' && tab[pos][1]=='V') || (tab[pos][0]=='0' && tab[pos][1]=='G') || (tab[pos][0]=='M' && tab[pos][1]=='P') || (tab[pos][0]=='X' && tab[pos][1]=='G') || (tab[pos][0]=='X' && tab[pos][1]=='B') || (tab[pos][0]=='X' && tab[pos][1]=='M') || (tab[pos][0]=='X' && tab[pos][1]=='P') || (tab[pos][0]=='X' && tab[pos][1]=='V') || (tab[pos][0]=='X' && tab[pos][1]=='A') || (tab[pos][0]=='X' && tab[pos][1]=='<') || (tab[pos][0]=='X' && tab[pos][1]=='>')){ //si 'WG' ou 'wG' ou '0<' ou '0>' ou '0G'
                tab[pos+x]=tab[pos][1];
                tab[pos]=tab[pos][0];
            }else if((tab[pos][0]=='P' && tab[pos][1]=='0') || (tab[pos][0]=='G' && tab[pos][1]=='W') || (tab[pos][0]=='G' && tab[pos][1]=='W') || (tab[pos][0]=='G' && tab[pos][1]=='X')){
                tab[pos+x]=tab[pos][0];
                tab[pos]=tab[pos][1];
            }else if(tab[pos][0]=='P' && tab[pos][1]=='M' || tab[pos][0]=='P' && tab[pos][1]=='G' || tab[pos][0]=='P' && tab[pos][1]=='B'){
                tab[pos+x]=tab[pos][0];
                tab[pos]=tab[pos][1];               
            }else if(tab[pos][0]=='M' && tab[pos][1]=='P' || tab[pos][0]=='G' && tab[pos][1]=='P' || tab[pos][0]=='B' && tab[pos][1]=='P'){
                tab[pos+x]=tab[pos][1];
                tab[pos]=tab[pos][0];               
            }
        }else if(tab[pos].size()==3){               //si 3 lettres dans case depart
            if(tab[pos][0]=='M' && tab[pos][1]=='L' && (tab[pos][2]=='G'|| tab[pos][2]=='M' || tab[pos][2]=='B'|| tab[pos][2]=='<' || tab[pos][2]=='>' || tab[pos][2]=='A' || tab[pos][2]=='V')){
                tab[pos+x]=tab[pos][2];
                tab[pos]="ML";
            }else if(tab[pos][0]=='P' && tab[pos][1]=='U' && (tab[pos][2]=='G'|| tab[pos][2]=='M' || tab[pos][2]=='B'|| tab[pos][2]=='<' || tab[pos][2]=='>' || tab[pos][2]=='A' || tab[pos][2]=='V')){
                tab[pos+x]=tab[pos][2];
                tab[pos]="PU";
            }else if(tab[pos][0]=='M' && tab[pos][1]=='B' && (tab[pos][2]=='G'|| tab[pos][2]=='M' || tab[pos][2]=='B'|| tab[pos][2]=='<' || tab[pos][2]=='>' || tab[pos][2]=='A' || tab[pos][2]=='V')){
                tab[pos+x]=tab[pos][2];
                tab[pos]="MB";
            }else if(tab[pos][0]=='S' && tab[pos][1]=='C' && (tab[pos][2]=='G'|| tab[pos][2]=='M' || tab[pos][2]=='B'|| tab[pos][2]=='<' || tab[pos][2]=='>' || tab[pos][2]=='A' || tab[pos][2]=='V')){
                tab[pos+x]=tab[pos][2];
                tab[pos]="SC";
            }else if(tab[pos][0]=='S' && tab[pos][1]=='P' && (tab[pos][2]=='G'|| tab[pos][2]=='M' || tab[pos][2]=='B'|| tab[pos][2]=='<' || tab[pos][2]=='>' || tab[pos][2]=='A' || tab[pos][2]=='V')){
                tab[pos+x]=tab[pos][2];
                tab[pos]="SP";
            }else if(tab[pos]=="XP0"){
                tab[pos+x]="P";
                tab[pos]="X0";
            }else if(tab[pos]=="XMP"){
                tab[pos+x]="P";
                tab[pos]="XM";
            }else if(tab[pos]=="XBP"){
                tab[pos+x]="P";
                tab[pos]="XB";
            }else if(tab[pos]=="XGP"){
                tab[pos+x]="P";
                tab[pos]="XG";
            }else if(tab[pos]=="MP0"){
                tab[pos+x]="P";
                tab[pos]="M0";
            }else if(tab[pos]=="BP0"){
                tab[pos+x]="P";
                tab[pos]="B0";
            }else if(tab[pos]=="GP0"){
                tab[pos+x]="P";
                tab[pos]="G0";
            }else if(tab[pos]=="PM0"){
                tab[pos+x]="P";
                tab[pos]="M0";
            }else if(tab[pos]=="PB0"){
                tab[pos+x]="P";
                tab[pos]="B0";
            }else if(tab[pos]=="PG0"){
                tab[pos+x]="P";
                tab[pos]="G0";
            }
        }
    }else{                                          //sinon si case d'arriver est contient deja une lettre
        if(tab[pos].size()==1){                     //si 1 seul lettre dans case depart
            tab[pos+x]+=tab[pos];                   //case d'arriver = case d'arriver + case de depart
            tab[pos]=' ';                           //case de depart = vide
        }else if(tab[pos].size()==2){               //si 2 lettres dans case depart
            if((tab[pos][0]=='W' && tab[pos][1]=='G') || (tab[pos][0]=='w' && tab[pos][1]=='G') || (tab[pos][0]=='0' && tab[pos][1]=='<') || (tab[pos][0]=='0' && tab[pos][1]=='>') || (tab[pos][0]=='0' && tab[pos][1]=='A') || (tab[pos][0]=='0' && tab[pos][1]=='V') || (tab[pos][0]=='0' && tab[pos][1]=='G')  || (tab[pos][0]=='X' && tab[pos][1]=='G') || (tab[pos][0]=='X' && tab[pos][1]=='B') || (tab[pos][0]=='X' && tab[pos][1]=='M') || (tab[pos][0]=='X' && tab[pos][1]=='P') || (tab[pos][0]=='X' && tab[pos][1]=='V') || (tab[pos][0]=='X' && tab[pos][1]=='A') || (tab[pos][0]=='X' && tab[pos][1]=='<') || (tab[pos][0]=='X' && tab[pos][1]=='>')){ //si 'WG' ou 'wg' ou '0<' ou '0>' ou '0G'
                tab[pos+x]+=tab[pos][1];            //case d'arriver = case d'arriver + case de depart[1]
                tab[pos]=tab[pos][0];               //case de depart = case de depart[0]
            }else if((tab[pos][0]=='P' && tab[pos][1]=='M') || (tab[pos][0]=='P' && tab[pos][1]=='G') || (tab[pos][0]=='P' && tab[pos][1]=='B')   || (tab[pos][0]=='G' && tab[pos][1]=='X')){
                tab[pos+x]+=tab[pos][0];
                tab[pos]=tab[pos][1];               
            }else if(tab[pos][0]=='M' && tab[pos][1]=='P' || tab[pos][0]=='G' && tab[pos][1]=='P' || tab[pos][0]=='B' && tab[pos][1]=='P'){
                tab[pos+x]+=tab[pos][1];
                tab[pos]=tab[pos][0];               
            }
        }else if(tab[pos].size()==3){               //si 3 lettres dans case depart
            if(tab[pos][0]=='M' && tab[pos][1]=='L' && (tab[pos][2]=='G'|| tab[pos][2]=='M' || tab[pos][2]=='B'|| tab[pos][2]=='<' || tab[pos][2]=='>' || tab[pos][2]=='A' || tab[pos][2]=='V')){
                tab[pos+x]+=tab[pos][2];
                tab[pos]="ML";
            }else if(tab[pos][0]=='P' && tab[pos][1]=='U' && (tab[pos][2]=='G'|| tab[pos][2]=='M' || tab[pos][2]=='B'|| tab[pos][2]=='<' || tab[pos][2]=='>' || tab[pos][2]=='A' || tab[pos][2]=='V')){
                tab[pos+x]+=tab[pos][2];
                tab[pos]="PU";
            }else if(tab[pos][0]=='M' && tab[pos][1]=='B' && (tab[pos][2]=='G'|| tab[pos][2]=='M' || tab[pos][2]=='B'|| tab[pos][2]=='<' || tab[pos][2]=='>' || tab[pos][2]=='A' || tab[pos][2]=='V')){
                tab[pos+x]+=tab[pos][2];
                tab[pos]="MB";
            }else if(tab[pos][0]=='S' && tab[pos][1]=='P' && (tab[pos][2]=='G'|| tab[pos][2]=='M' || tab[pos][2]=='B'|| tab[pos][2]=='<' || tab[pos][2]=='>' || tab[pos][2]=='A' || tab[pos][2]=='V')){
                tab[pos+x]+=tab[pos][2];
                tab[pos]="SP";
            }else if(tab[pos][0]=='S' && tab[pos][1]=='C' && (tab[pos][2]=='G'|| tab[pos][2]=='M' || tab[pos][2]=='B'|| tab[pos][2]=='<' || tab[pos][2]=='>' || tab[pos][2]=='A' || tab[pos][2]=='V')){
                tab[pos+x]+=tab[pos][2];
                tab[pos]="SC";
            }else if(tab[pos]=="MP0" || tab[pos]=="GP0" || tab[pos]=="BP0"){
                tab[pos+x]=tab[pos][1];
                if(tab[pos][0]='M') tab[pos]="M0";
                else if(tab[pos][0]='G') tab[pos]="G0";
                else if(tab[pos][0]='B') tab[pos]="B0";
            }else if(tab[pos]=="PM0" || tab[pos]=="PB0" || tab[pos]=="PG0"){
                tab[pos+x]=tab[pos][0];
                if(tab[pos][1]='M') tab[pos]="M0";
                else if(tab[pos][1]='G') tab[pos]="G0";
                else if(tab[pos][1]='B') tab[pos]="B0";
            }else if(tab[pos]=="XP0"){
                tab[pos+x]+="P";
                tab[pos]="X0";
            }else if(tab[pos]=="XMP"){
                tab[pos+x]+="P";
                tab[pos]="XM";
            }else if(tab[pos]=="XBP"){
                tab[pos+x]+="P";
                tab[pos]="XB";
            }else if(tab[pos]=="XGP"){
                tab[pos+x]+="P";
                tab[pos]="XG";
            }else if(tab[pos]=="MP0"){
                tab[pos+x]+="P";
                tab[pos]="M0";
            }else if(tab[pos]=="BP0"){
                tab[pos+x]+="P";
                tab[pos]="B0";
            }else if(tab[pos]=="GP0"){
                tab[pos+x]+="P";
                tab[pos]="G0";
            }else if(tab[pos]=="PM0"){
                tab[pos+x]+="P";
                tab[pos]="M0";
            }else if(tab[pos]=="PB0"){
                tab[pos+x]+="P";
                tab[pos]="B0";
            }else if(tab[pos]=="PG0"){
                tab[pos+x]+="P";
                tab[pos]="G0";
            }
        }    
    }
}






int Map::getLigne(int positionPerso, int nbLigne, int nbColonne)
{
    int ligne=-1, x=nbColonne, i=0;
    bool trouver = false;

    while(!trouver || i<nbLigne){
        if(positionPerso>=x*i && positionPerso<=(x*(i+1))-1){
            ligne = i;
            trouver=true;
        }
        i++; 
    }
    
    return ligne; 
}

int Map::getColonne(int positionPerso, int nbColonne)
{
    return positionPerso%nbColonne;
}




int Map::recupPorteeMaxBombe(int pos, char direction, int porteeBombe){
    int i=0, porterDeLaBombe, ligneDeLaBombe, posTMP, ligneDeLaBombeTMP;
    bool boole=false;

    if(tab[pos]=="@" || tab[pos]=="@G" || tab[pos]=="G@")
    {
        while(i<=nbLigne){
            if(pos==0)                     //position = 0
            {                    
                if(direction=='G' || direction=='H') return 0;
            }
            if(pos==nbCaractere-1)    //position = 75-1
            {
                if(direction=='D' || direction=='B') return 0;
            }
            if(pos==nbColonne*i)      //position = 15, 30, 45, 60 coté gauche
            {
                if(direction=='G') return 0;
            }
            if(pos==(nbColonne*i)-1)      //position = 14, 29, 44, 59  coté droite
            {
                if(direction=='D') return 0;
            }
            if(pos>=nbColonne*(nbLigne-1) && pos<nbColonne*nbLigne)    // 75 > position >= 60
            {
                if(direction=='B') return 0;
            }
            if(pos>=0 && pos<nbColonne)           // 15 > position >= 0
            {
                if(direction=='H') return 0;
            }
            i++;
        }

        if(pos>=0 && pos<nbCaractere){   // 0 <= position bombe < 75
            if(direction=='D')
            {
                while(boole==false && porteeBombe!=0){
                    posTMP = pos + porteeBombe;
                    ligneDeLaBombeTMP = getLigne(posTMP, nbLigne, nbColonne);

                    if(getLigne(pos, nbLigne, nbColonne) == ligneDeLaBombeTMP ) boole=true;
                    else porteeBombe--;
                }

                for(int j=1;j<=porteeBombe;j++){
                    if(tab[pos+j]=="W" || tab[pos+j]=="w" || tab[pos+j]=="#" || tab[pos+j]=="0" || tab[pos+j]=="0G" || tab[pos+j]=="WG" || tab[pos+j]=="wG") return j;
                }

                if(boole==true) return porteeBombe;

            }
            else if(direction=='G')
            {
                porterDeLaBombe = getColonne(pos, nbColonne);
                if(porterDeLaBombe>porteeBombe) porterDeLaBombe=porteeBombe;
                for(int j=1;j<=porterDeLaBombe;j++){
                    if(tab[pos-j]=="W" || tab[pos-j]=="w" || tab[pos-j]=="#" || tab[pos-j]=="0" || tab[pos-j]=="0G" || tab[pos-j]=="WG" || tab[pos-j]=="wG") return j;
                }
            }
            else if(direction=='H')
            {
                porterDeLaBombe = getLigne(pos, nbLigne, nbColonne);
                if(porterDeLaBombe>porteeBombe) porterDeLaBombe=porteeBombe;
                for(int j=1;j<=porterDeLaBombe;j++){
                    if(tab[pos-(nbColonne*j)]=="W" || tab[pos-(nbColonne*j)]=="w" || tab[pos-(nbColonne*j)]=="#" || tab[pos-(nbColonne*j)]=="0" || tab[pos-(nbColonne*j)]=="0G" || tab[pos-(nbColonne*j)]=="WG" || tab[pos-(nbColonne*j)]=="wG") return j;
                }
            }
            else if(direction=='B')
            {
                porterDeLaBombe = (nbLigne-1) - getLigne(pos, nbLigne, nbColonne);
                if(porterDeLaBombe>porteeBombe) porterDeLaBombe=porteeBombe;
                for(int j=1;j<=porterDeLaBombe;j++){
                    if(tab[pos+(nbColonne*j)]=="W" || tab[pos+(nbColonne*j)]=="w" || tab[pos+(nbColonne*j)]=="#" || tab[pos+(nbColonne*j)]=="0" || tab[pos+(nbColonne*j)]=="0G" || tab[pos+(nbColonne*j)]=="WG" || tab[pos+(nbColonne*j)]=="wG") return j;
                }
            }
        }
    }
    return porterDeLaBombe;
}





void Map::explosionBombe(int pos, int porteeBombe){

    if(tab[pos]=="@" || tab[pos]=="@G" || tab[pos]=="G@")
    {

        //exlosion droite
        porteePossibleBombe[0]=recupPorteeMaxBombe(pos, 'D', porteeBombe);
        if(porteePossibleBombe[0]!=0){
            for(int i=1;i<=porteePossibleBombe[0];i++){
                if(tab[pos+i]==" "){
                    if(i!=porteePossibleBombe[0]) tab[pos+i]='0'+1;
                    else tab[pos+i]='0'+2;
                }else if(tab[pos+i]!=" "){
                    if(i!=porteePossibleBombe[0]) tab[pos+i]+='0'+1;
                    else tab[pos+i]+='0'+2;
                }
            }
        }

        //exlosion gauche
        porteePossibleBombe[1]=recupPorteeMaxBombe(pos, 'G', porteeBombe);
        if(porteePossibleBombe[1]!=0){
            for(int i=1;i<=porteePossibleBombe[1];i++){
                if(tab[pos-i]==" "){
                    if(i!=porteePossibleBombe[1]) tab[pos-i]='0'+7;
                    else tab[pos-i]='0'+3;
                }else if(tab[pos-i]!=" "){
                    if(i!=porteePossibleBombe[1]) tab[pos-i]+='0'+7;
                    else tab[pos-i]+='0'+3;
                }
            }
        }

        //exlosion bas
        porteePossibleBombe[2]=recupPorteeMaxBombe(pos, 'B', porteeBombe);
        if(porteePossibleBombe[2]!=0){
            for(int i=1;i<=porteePossibleBombe[2];i++){
                if(tab[pos+(nbColonne*i)]==" "){
                    if(i!=porteePossibleBombe[2]) tab[pos+(nbColonne*i)]='0'+4;
                    else tab[pos+(nbColonne*i)]='0'+5;
                }else if(tab[pos+(nbColonne*i)]!=" "){
                    if(i!=porteePossibleBombe[2]) tab[pos+(nbColonne*i)]+='0'+4;
                    else tab[pos+(nbColonne*i)]+='0'+5;
                }
            }
        }

        //exlosion haut
        porteePossibleBombe[3]=recupPorteeMaxBombe(pos, 'H', porteeBombe);
        if(porteePossibleBombe[3]!=0){
            for(int i=1;i<=porteePossibleBombe[3];i++){
                if(tab[pos-(nbColonne*i)]==" "){
                    if(i!=porteePossibleBombe[3]) tab[pos-(nbColonne*i)]='0'+4;
                    else tab[pos-(nbColonne*i)]='0'+6;
                }else if(tab[pos-(nbColonne*i)]!=" "){
                    if(i!=porteePossibleBombe[3]) tab[pos-(nbColonne*i)]+='0'+4;
                    else tab[pos-(nbColonne*i)]+='0'+6;
                }
            }
        }
    }
}





void Map::retirerExplosionBombe(int pos){
    string tmp;

    if(tab[pos]=="@" || tab[pos]=="@G" || tab[pos]=="G@")
    {
        //droite
        for(int i=1;i<=porteePossibleBombe[0];i++){
            if(tab[pos+i]=="1" || tab[pos+i]=="2"){
                tab[pos+i]=" ";
            }else if(tab[pos+i].size()==2){
                tab[pos+i]=tab[pos+i][0];
            }else if(tab[pos+i].size()==3){
                if(tab[pos+i][2]=='1' || tab[pos+i][2]=='2'){
                    tmp=tab[pos+i][0];
                    tmp+=tab[pos+i][1];
                    tab[pos+i]=tmp;
                }
            } else if(tab[pos+i].size()==4){
                if(tab[pos+i][3]=='1' || tab[pos+i][3]=='2'){
                    tmp=tab[pos+i][0];
                    tmp+=tab[pos+i][1];
                    tmp+=tab[pos+i][2];
                    tab[pos+i]=tmp;
                }
            }    
        }

        //gauche
        for(int i=1;i<=porteePossibleBombe[1];i++){
            if(tab[pos-i]=="7" || tab[pos-i]=="3"){
                tab[pos-i]=" ";
            }else if(tab[pos-i].size()==2){
                tab[pos-i]=tab[pos-i][0];
            }else if(tab[pos-i].size()==3){
                if(tab[pos-i][2]=='7' || tab[pos-i][2]=='3'){
                    tmp=tab[pos-i][0];
                    tmp+=tab[pos-i][1];
                    tab[pos-i]=tmp;
                }
            }else if(tab[pos-i].size()==4){
                if(tab[pos-i][3]=='7' || tab[pos-i][3]=='3'){
                    tmp=tab[pos-i][0];
                    tmp+=tab[pos-i][1];
                    tmp+=tab[pos-i][2];
                    tab[pos-i]=tmp;
                }
            }
        }

        //bas
        for(int i=1;i<=porteePossibleBombe[2];i++){
            if(tab[pos+(i*nbColonne)]=="4" || tab[pos+(i*nbColonne)]=="5"){
                tab[pos+(i*nbColonne)]=" ";
            }else if(tab[pos+(i*nbColonne)].size()==2){
                tab[pos+(i*nbColonne)]=tab[pos+(i*nbColonne)][0];
            }else if(tab[pos+(i*nbColonne)].size()==3){
                if(tab[pos+(i*nbColonne)][2]=='4' || tab[pos+(i*nbColonne)][2]=='5'){
                    tmp=tab[pos+(i*nbColonne)][0];
                    tmp+=tab[pos+(i*nbColonne)][1];
                    tab[pos+(i*nbColonne)]=tmp;
                }
            }else if(tab[pos+(i*nbColonne)].size()==4){
                if(tab[pos+(i*nbColonne)][3]=='4' || tab[pos+(i*nbColonne)][3]=='5'){
                    tmp=tab[pos+(i*nbColonne)][0];
                    tmp+=tab[pos+(i*nbColonne)][1];
                    tmp+=tab[pos+(i*nbColonne)][2];
                    tab[pos+(i*nbColonne)]=tmp;
                }
            }    
        }

        //haut
        for(int i=1;i<=porteePossibleBombe[3];i++){
            if(tab[pos-(i*nbColonne)]=="4" || tab[pos-(i*nbColonne)]=="6"){
                tab[pos-(i*nbColonne)]=" ";
            }else if(tab[pos-(i*nbColonne)].size()==2){
                tab[pos-(i*nbColonne)]=tab[pos-(i*nbColonne)][0];
            }else if(tab[pos-(i*nbColonne)].size()==3){
                if(tab[pos-(i*nbColonne)][2]=='4' || tab[pos-(i*nbColonne)][2]=='6'){
                    tmp=tab[pos-(i*nbColonne)][0];
                    tmp+=tab[pos-(i*nbColonne)][1];
                    tab[pos-(i*nbColonne)]=tmp;
                }
            }else if(tab[pos-(i*nbColonne)].size()==4){
                if(tab[pos-(i*nbColonne)][3]=='4' || tab[pos-(i*nbColonne)][3]=='6'){
                    tmp=tab[pos-(i*nbColonne)][0];
                    tmp+=tab[pos-(i*nbColonne)][1];
                    tmp+=tab[pos-(i*nbColonne)][2];
                    tab[pos-(i*nbColonne)]=tmp;
                }
            }   
        }
        if(tab[pos] == "@M" || tab[pos] == "M@")
            tab[pos] = "M";
        else if(tab[pos] == "@B" || tab[pos] == "B@")
            tab[pos] = "B";
        else if(tab[pos]=="@G" || tab[pos] =="G@")
            tab[pos] = "G";
        else if(tab[pos] == "@<") // bombe + fleche gauche
            tab[pos] = "<";
        else if(tab[pos] == "@>") // bombe + fleche droite
            tab[pos] = ">";
        else if(tab[pos] == "@A") // bombe + fleche haut
            tab[pos] = "A";
        else if(tab[pos] == "@V") // bombe + fleche bas
            tab[pos] = "V";
        else // sinon, ni a que la bombe 
            tab[pos]=' ';   
    }
}




bool Map::verifJoueurBloque(int position){
    int i=0, gauche=1, droite=1, haut=1, bas=1;
    while(i<=nbLigne){
        if(position==0)                  //position = 0
        {                    
            gauche=0;
            haut=0;
        }
        if(position==nbCaractere-1)    //position = 75
        {
            droite=0;
            bas=0;
        }
        if(position==nbColonne*i)      //position = 15, 30, 45, 60 coté gauche
        {
            gauche=0;
        }
        if(position==(nbColonne*i)-1)  //position = 14, 29, 44, 59  coté droite
        {
            droite=0;
        }
        if(position>=nbColonne*(nbLigne-1) && position<nbColonne*nbLigne)    // 75 > position >= 60
        {
            bas=0;
        }
        if(position>=0 && position<nbColonne)           // 15 > position >= 0
        {
            haut=0;
        }
        i++;
    }
    if(position>=0 && position<nbCaractere){        // 0 <= position < 75
        if(gauche!=0){
            if(tab[position-1]=="#" || tab[position-1]=="W" || tab[position-1]=="w" || tab[position-1]=="WG" || tab[position-1]=="wG" || tab[position-1]=="0" || tab[position-1]=="0G" || tab[position-1]=="@" || tab[position-1]=="@G"){
                gauche=0;
            }
        }
        if(droite!=0){
            if(tab[position+1]=="#" || tab[position+1]=="W" || tab[position+1]=="w" || tab[position+1]=="WG" || tab[position+1]=="wG" || tab[position+1]=="0" || tab[position+1]=="0G" || tab[position+1]=="@" || tab[position+1]=="@G"){
                droite=0;
            }
        }
        if(haut!=0){
            if(tab[position-nbColonne]=="#" || tab[position-nbColonne]=="W" || tab[position-nbColonne]=="w" || tab[position-nbColonne]=="WG" || tab[position-nbColonne]=="wG" || tab[position-nbColonne]=="0" || tab[position-nbColonne]=="0G" || tab[position-nbColonne]=="@" || tab[position-nbColonne]=="@G"){
                haut=0;
            }
        }
        if(bas!=0){
            if(tab[position+nbColonne]=="#" || tab[position+nbColonne]=="W" || tab[position+nbColonne]=="w" || tab[position+nbColonne]=="WG" || tab[position+nbColonne]=="wG" || tab[position+nbColonne]=="0" || tab[position+nbColonne]=="0G" || tab[position+nbColonne]=="@" || tab[position+nbColonne]=="@G"){
                bas=0;
            }
        }
    }

    
    if(gauche==0 && droite==0 && haut==0 && bas==0) return false;
    else return true;
}



void Map::deplacementFleche(int pos, char direction){
    int x;
    char lettre;

    
    if(direction=='z') {x = -nbColonne;}
    else if(direction=='q') {x = -1;}
    else if(direction=='s') {x = nbColonne;}
    else if(direction=='d') {x = 1;}

    if(!flecheBloquer(pos, direction)){
        if(tab[pos+x]==" "){                            //si case d'arriver est vide
            if(tab[pos].size()==1){                     //si 1 seul lettre dans case depart
                tab[pos+x]=tab[pos];                    //case d'arriver = case de depart
                tab[pos]=' ';                           //case de depart = vide
            }else if(tab[pos].size()==2){               //si 2 lettres dans case depart
                if((tab[pos][0]=='W' && tab[pos][1]=='G') || (tab[pos][0]=='w' && tab[pos][1]=='G') || (tab[pos][0]=='0' && tab[pos][1]=='<') || (tab[pos][0]=='0' && tab[pos][1]=='>') || (tab[pos][0]=='0' && tab[pos][1]=='A') || (tab[pos][0]=='0' && tab[pos][1]=='V') || (tab[pos][0]=='0' && tab[pos][1]=='G') || (tab[pos][0]=='M' && tab[pos][1]=='P') || (tab[pos][0]=='X' && tab[pos][1]=='V') || (tab[pos][0]=='X' && tab[pos][1]=='A') || (tab[pos][0]=='X' && tab[pos][1]=='<') || (tab[pos][0]=='X' && tab[pos][1]=='>')){ //si 'WG' ou 'wG' ou '0<' ou '0>' ou '0G'
                    tab[pos+x]=tab[pos][1];
                    tab[pos]=tab[pos][0];
                }else if((tab[pos][0]=='P' && tab[pos][1]=='0') || (tab[pos][0]=='G' && tab[pos][1]=='W') || (tab[pos][0]=='G' && tab[pos][1]=='W')){ //si 'GW' ou 'gw'
                    tab[pos+x]=tab[pos][0];
                    tab[pos]=tab[pos][1];
                }else if(tab[pos][0]=='P' && tab[pos][1]=='M' || tab[pos][0]=='P' && tab[pos][1]=='G' || tab[pos][0]=='P' && tab[pos][1]=='B'){
                    tab[pos+x]=tab[pos][0];
                    tab[pos]=tab[pos][1];               
                }else if(tab[pos][0]=='M' && tab[pos][1]=='P' || tab[pos][0]=='G' && tab[pos][1]=='P' || tab[pos][0]=='B' && tab[pos][1]=='P'){
                    tab[pos+x]=tab[pos][1];
                    tab[pos]=tab[pos][0];               
                }
            }else if(tab[pos].size()==3){               //si 3 lettres dans case depart
                if(tab[pos][0]=='M' && tab[pos][1]=='L' && (tab[pos][2]=='G'|| tab[pos][2]=='M' || tab[pos][2]=='B'|| tab[pos][2]=='<' || tab[pos][2]=='>' || tab[pos][2]=='A' || tab[pos][2]=='V')){
                    tab[pos+x]=tab[pos][2];
                    tab[pos]="ML";
                }else if(tab[pos][0]=='P' && tab[pos][1]=='U' && (tab[pos][2]=='G'|| tab[pos][2]=='M' || tab[pos][2]=='B'|| tab[pos][2]=='<' || tab[pos][2]=='>' || tab[pos][2]=='A' || tab[pos][2]=='V')){
                    tab[pos+x]=tab[pos][2];
                    tab[pos]="PU";
                }else if(tab[pos][0]=='M' && tab[pos][1]=='B' && (tab[pos][2]=='G'|| tab[pos][2]=='M' || tab[pos][2]=='B'|| tab[pos][2]=='<' || tab[pos][2]=='>' || tab[pos][2]=='A' || tab[pos][2]=='V')){
                    tab[pos+x]=tab[pos][2];
                    tab[pos]="MB";
                }else if(tab[pos][0]=='S' && tab[pos][1]=='C' && (tab[pos][2]=='G'|| tab[pos][2]=='M' || tab[pos][2]=='B'|| tab[pos][2]=='<' || tab[pos][2]=='>' || tab[pos][2]=='A' || tab[pos][2]=='V')){
                    tab[pos+x]=tab[pos][2];
                    tab[pos]="SC";
                }else if(tab[pos][0]=='S' && tab[pos][1]=='P' && (tab[pos][2]=='G'|| tab[pos][2]=='M' || tab[pos][2]=='B'|| tab[pos][2]=='<' || tab[pos][2]=='>' || tab[pos][2]=='A' || tab[pos][2]=='V')){
                    tab[pos+x]=tab[pos][2];
                    tab[pos]="SP";
                }
            }
        }else{                                          //sinon si case d'arriver est contient deja une lettre
            if(tab[pos].size()==1){                     //si 1 seul lettre dans case depart
                tab[pos+x]+=tab[pos];                   //case d'arriver = case d'arriver + case de depart
                tab[pos]=' ';                           //case de depart = vide
            }else if(tab[pos].size()==2){               //si 2 lettres dans case depart
                if((tab[pos][0]=='W' && tab[pos][1]=='G') || (tab[pos][0]=='w' && tab[pos][1]=='G') || (tab[pos][0]=='0' && tab[pos][1]=='<') || (tab[pos][0]=='0' && tab[pos][1]=='>') || (tab[pos][0]=='0' && tab[pos][1]=='A') || (tab[pos][0]=='0' && tab[pos][1]=='V') || (tab[pos][0]=='0' && tab[pos][1]=='G') || (tab[pos][0]=='X' && tab[pos][1]=='V') || (tab[pos][0]=='X' && tab[pos][1]=='A') || (tab[pos][0]=='X' && tab[pos][1]=='<') || (tab[pos][0]=='X' && tab[pos][1]=='>')){ //si 'WG' ou 'wg' ou '0<' ou '0>' ou '0G'
                    tab[pos+x]+=tab[pos][1];            //case d'arriver = case d'arriver + case de depart[1]
                    tab[pos]=tab[pos][0];               //case de depart = case de depart[0]
                }else if(tab[pos][0]=='P' && tab[pos][1]=='M' || tab[pos][0]=='P' && tab[pos][1]=='G' || tab[pos][0]=='P' && tab[pos][1]=='B'){
                    tab[pos+x]+=tab[pos][0];
                    tab[pos]=tab[pos][1];               
                }else if(tab[pos][0]=='M' && tab[pos][1]=='P' || tab[pos][0]=='G' && tab[pos][1]=='P' || tab[pos][0]=='B' && tab[pos][1]=='P'){
                    tab[pos+x]+=tab[pos][1];
                    tab[pos]=tab[pos][0];               
                }
            }else if(tab[pos].size()==3){               //si 3 lettres dans case depart
                if(tab[pos][0]=='M' && tab[pos][1]=='L' && (tab[pos][2]=='G'|| tab[pos][2]=='M' || tab[pos][2]=='B'|| tab[pos][2]=='<' || tab[pos][2]=='>' || tab[pos][2]=='A' || tab[pos][2]=='V')){
                    tab[pos+x]+=tab[pos][2];
                    tab[pos]="ML";
                }else if(tab[pos][0]=='P' && tab[pos][1]=='U' && (tab[pos][2]=='G'|| tab[pos][2]=='M' || tab[pos][2]=='B'|| tab[pos][2]=='<' || tab[pos][2]=='>' || tab[pos][2]=='A' || tab[pos][2]=='V')){
                    tab[pos+x]+=tab[pos][2];
                    tab[pos]="PU";
                }else if(tab[pos][0]=='M' && tab[pos][1]=='B' && (tab[pos][2]=='G'|| tab[pos][2]=='M' || tab[pos][2]=='B'|| tab[pos][2]=='<' || tab[pos][2]=='>' || tab[pos][2]=='A' || tab[pos][2]=='V')){
                    tab[pos+x]+=tab[pos][2];
                    tab[pos]="MB";
                }else if(tab[pos][0]=='S' && tab[pos][1]=='P' && (tab[pos][2]=='G'|| tab[pos][2]=='M' || tab[pos][2]=='B'|| tab[pos][2]=='<' || tab[pos][2]=='>' || tab[pos][2]=='A' || tab[pos][2]=='V')){
                    tab[pos+x]+=tab[pos][2];
                    tab[pos]="SP";
                }else if(tab[pos][0]=='S' && tab[pos][1]=='C' && (tab[pos][2]=='G'|| tab[pos][2]=='M' || tab[pos][2]=='B'|| tab[pos][2]=='<' || tab[pos][2]=='>' || tab[pos][2]=='A' || tab[pos][2]=='V')){
                    tab[pos+x]+=tab[pos][2];
                    tab[pos]="SC";
                }
            }
        }
    }
}


bool Map::flecheBloquer(int pos, char deplacement){
    int i=0;
    while(i<=nbLigne){
        if(pos==-1){                     //pos = 0
            if(deplacement=='q' || deplacement=='z'){
                retirerFleche(pos);
                return true;
            }
        }
        if(pos==nbCaractere-1){    //pos = 75
            if(deplacement=='s' || deplacement=='d'){
                retirerFleche(pos);
                return true;
            }
        }
        if(pos==nbColonne*i){      //pos = 0, 15, 30, 45, 60 coté gauche
            if(deplacement=='q'){
                retirerFleche(pos);
                return true;
            }
        }
        if(pos==(nbColonne*i)-1){  //pos = 14, 29, 44, 59  coté droite
            if(deplacement=='d'){
                retirerFleche(pos);
                return true;
            }
        }
        if(pos>=nbColonne*(nbLigne-1) && pos<nbColonne*nbLigne){    // 75 > pos >= 60
            if(deplacement=='s'){
                retirerFleche(pos);
                return true;
            }
        }
        if(pos>=0 && pos<nbColonne){           // 15 > pos >= 0
            if(deplacement=='z'){
                retirerFleche(pos);
                return true;
            }
        }
        i++;
    }
    return false;
}


void Map::retirerFleche(int pos){
    string tmp;
    if(tab[pos]=="<" || tab[pos]==">" || tab[pos]=="A" || tab[pos]=="V"){
        tab[pos]=" ";
    }else if(tab[pos]=="0<" || tab[pos]=="0>" || tab[pos]=="0A" || tab[pos]=="0V" || tab[pos]=="WA" || tab[pos]=="wA" || tab[pos]=="WV" || tab[pos]=="wV" || tab[pos]=="W<" || tab[pos]=="w<" || tab[pos]=="W>" || tab[pos]=="w>"){
        tmp=tab[pos][0];
        tab[pos]=tmp;
    }else if(tab[pos]=="ML<" || tab[pos]=="ML>" || tab[pos]=="MLA" || tab[pos]=="MLV" || tab[pos]=="PU<" || tab[pos]=="PU>" || tab[pos]=="PUA" || tab[pos]=="PUV" || tab[pos]=="MB<" || tab[pos]=="MB>" || tab[pos]=="MBA" || tab[pos]=="MBV" || tab[pos]=="SC<" || tab[pos]=="SC>" || tab[pos]=="SCA" || tab[pos]=="SCV" || tab[pos]=="SP<" || tab[pos]=="SP>" || tab[pos]=="SPA" || tab[pos]=="SPV" || tab[pos]=="wGA" || tab[pos]=="wGV" || tab[pos]=="wG<" || tab[pos]=="wG>" || tab[pos]=="WGA" || tab[pos]=="WGV" || tab[pos]=="WG<" || tab[pos]=="WG>"){
        tmp=tab[pos][0];
        tmp+=tab[pos][1];
        tab[pos]=tmp;
    }
}


int Map::compteMurs()
{
    int nbWall=0;
    for(int i=0; i<nbCaractere; i++)
    {
        if(tab[i]=="W" || tab[i]=="w")
        {
            nbWall++;
        }
    }
    return nbWall;
}

void Map::alloueMurs()
{
    nbWallMap = compteMurs();
    wall = new Wall*[nbWallMap];
    int j=0;
    for(int i=0; i<nbCaractere; i++)
    {
        if(tab[i]=="W")
        {
            wall[j] = new Wall(2, i);
            j++;
        }
        else if(tab[i]=="w")
        {
            wall[j] = new Wall(1, i);
            j++;
        }
    }
}

void Map::positionObjectif()
{
    for(int i=0; i<nbCaractere; i++)
    {
        if(tab[i]=="X")
        {
            objectif->setPosition(i);
        }
    }
}