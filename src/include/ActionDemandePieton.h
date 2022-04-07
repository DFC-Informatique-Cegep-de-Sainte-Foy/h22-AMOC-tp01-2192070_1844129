#pragma once
#include "Action.h"
#include "FeuxAuto.h"

class ActionDemandePieton : public Action
{
private:
    FeuxAuto* m_feuxAuto;
public:
    ActionDemandePieton(FeuxAuto* p_feuxAuto);
    virtual void executer();
    virtual void maintenirCycle();
};

