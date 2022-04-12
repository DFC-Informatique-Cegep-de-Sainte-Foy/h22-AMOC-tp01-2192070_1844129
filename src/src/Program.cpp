#include <Arduino.h>
#include "Program.h"
#include "DEL.h"
#include "Bouton.h"
#include "ActionDemandePieton.h"
#include "ActionEEPROM.h"

int const pinVertAuto = 3;
int const pinJauneAuto = 5;
int const pinRougeAuto = 6;

int const pinVertPieton = 11;
int const pinRougePieton = 10;

int const pinBouton1 = 2;
int const pinBouton2 = 4;
int const pinBouton3 = 7;

Program::Program()
{
    DEL* delVertAuto = new DEL(pinVertAuto);
    DEL* delJauneAuto = new DEL(pinJauneAuto);
    DEL* delRougeAuto = new DEL(pinRougeAuto);

    DEL* delVertPieton = new DEL(pinVertPieton);
    DEL* delRougePieton = new DEL(pinRougePieton);

    this->m_feuxPieton = new FeuxPieton(delRougePieton,delVertPieton);

    ActionEEPROM* actionEEPROM = new ActionEEPROM();

    FeuxAuto* feuxAuto = new FeuxAuto(delRougeAuto,delJauneAuto,delVertAuto,this->m_feuxPieton,actionEEPROM);

    ActionDemandePieton* actPieton = new ActionDemandePieton(feuxAuto,this->m_feuxPieton);

    this->m_bouton1 = new Bouton(pinBouton1,actPieton);
    this->m_bouton2 = new Bouton(pinBouton2,actPieton);
    this->m_bouton3 = new Bouton(pinBouton3,actionEEPROM);
}

void Program::loop()
{
   this->m_bouton1->tick();
   this->m_bouton2->tick();
   this->m_bouton3->tick();
   this->m_feuxPieton->tick();
}
