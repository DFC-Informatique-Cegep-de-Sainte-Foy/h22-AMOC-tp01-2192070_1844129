#pragma once
#include "Action.h"

class Bouton
{
private:
    int m_pin1;
    int m_pin2;
    Action* m_actionBouton;
    long m_derniereDateChangement;
    int m_dernierEtatBouton;
    int m_dernierEtatStableBouton;
    int m_delaiMinPression;
public:
    Bouton(int p_pinBouton1,int p_pinBouton2,Action* p_actionBouton);
    void tick();
};