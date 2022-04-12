#include <Arduino.h>
#include "ActionDemandePieton.h"
#include "FeuxPieton.h"

ActionDemandePieton::ActionDemandePieton(FeuxAuto* p_feuxAuto,FeuxPieton* p_feuxPieton) 
                                                                        : m_feuxAuto(p_feuxAuto),
                                                                        m_feuxPieton(p_feuxPieton)
{

}

void ActionDemandePieton::maintenirCycle()
{
    this->m_feuxAuto->tick();
}

void ActionDemandePieton::executer()
{
    this->m_feuxAuto->demanderPieton();
}

void ActionDemandePieton::effacer()
{
    ;
}