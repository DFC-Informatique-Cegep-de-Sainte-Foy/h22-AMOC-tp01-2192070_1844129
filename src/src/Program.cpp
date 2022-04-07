#include <Arduino.h>
#include "Program.h"
#include "DEL.h"
#include "Bouton.h"
#include "ActionDemandePieton.h"

Program::Program()
{
    DEL* delVertAuto = new DEL(3);
    DEL* delJauneAuto = new DEL(5);
    DEL* delRougeAuto = new DEL(6);

    DEL* delVertPieton = new DEL(11);
    DEL* delRougePieton = new DEL(10);

    this->m_feuxPieton = new FeuxPieton(delRougePieton,delVertPieton);

    FeuxAuto* feuxAuto = new FeuxAuto(delRougeAuto,delJauneAuto,delVertAuto,this->m_feuxPieton);

    ActionDemandePieton* actPieton = new ActionDemandePieton(feuxAuto,this->m_feuxPieton);

    this->m_bouton = new Bouton(2,4,actPieton);
}

void Program::loop()
{
   this->m_bouton->tick();
   this->m_feuxPieton->tick();
}
