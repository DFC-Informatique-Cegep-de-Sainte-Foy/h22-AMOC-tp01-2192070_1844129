#pragma once
#include "Action.h"
#include "FeuxAuto.h"
#include "FeuxPieton.h"

class ActionDemandePieton : public Action
{
private:
    FeuxAuto* m_feuxAuto;
    FeuxPieton* m_feuxPieton;
public:
    ActionDemandePieton(FeuxAuto* p_feuxAuto,FeuxPieton* p_feuxPieton);
    virtual void executer();
    virtual void maintenirCycle();
    virtual void effacer();
};

