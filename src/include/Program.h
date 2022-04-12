#pragma once
#include "Bouton.h"
#include "FeuxPieton.h"

class Program
{
private:
    Bouton* m_bouton1;
    Bouton* m_bouton2;
    Bouton* m_bouton3;
    FeuxPieton* m_feuxPieton;
public:
    Program();
    void loop();
};
