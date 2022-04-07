#include <Arduino.h>
#include "ActionDemandePieton.h"

ActionDemandePieton::ActionDemandePieton(FeuxAuto* p_feuxAuto) : m_feuxAuto(p_feuxAuto)
{

}

void ActionDemandePieton::maintenirCycle()
{
    this->m_feuxAuto->tick();
}

void ActionDemandePieton::executer()
{
    this->m_feuxAuto.demanderPieton();
}