#pragma once
#include "Action.h"

class Bouton
{
private:
    int m_pin;
    Action* m_actionBouton;
    long m_derniereDateChangement;
    int m_dernierEtatBouton;
    int m_dernierEtatStableBouton;
    int m_delaiMinPression;
    long m_tempsAppuye;
public:
    Bouton(int p_pinBouton,Action* p_actionBouton);
    void tick();
};
