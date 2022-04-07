#pragma once
#include "Bouton.h"
#include "FeuxPieton.h"

class Program
{
private:
    Bouton* m_bouton;
    FeuxPieton* m_feuxPieton;
public:
    Program();
    void loop();
};
