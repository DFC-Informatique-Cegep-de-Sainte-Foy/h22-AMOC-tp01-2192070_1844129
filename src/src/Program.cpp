#include <Arduino.h>
#include "Program.h"
#include "DEL.h"
#include "Bouton.h"
#include "ActionDemandePieton.h"

Program::Program()
{
    DEL* delVert = new DEL(3);
    DEL* delJaune = new DEL(5);
    DEL* delRouge = new DEL(6);
    FeuxAuto* feuxAuto = new FeuxAuto(delRouge,delJaune,delVert);
    ActionDemandePieton* actPieton = new ActionDemandePieton(feuxAuto);
    this->m_bouton = new Bouton(2,4,actPieton);
}

void Program::loop()
{
   this->m_bouton->tick();
}
