#pragma once
#include "DEL.h"

class FeuxPieton
{
private:
    DEL* m_delRouge;
    DEL* m_delVert;
    long m_derniereDateChangement;
    int m_dernierEtatPieton;
    int m_etatPieton;
public:
    FeuxPieton(DEL* p_delRouge,DEL* p_delVert);
    int activerPieton();
    void tick();
};
