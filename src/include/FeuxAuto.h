#pragma once

#include <Arduino.h>
#include "DEL.h"

class FeuxAuto
{
private:
    FeuxPieton* m_feuxPieton;
    DEL* m_DELRouge;
    DEL* m_DELJaune;
    DEL* m_DELVert;
    int m_pietonDemande;
    int m_etatLumiereActuel;
public:
    
    FeuxAuto(DEL* p_DELRouge, DEL* p_DELJaune, DEL* p_DELVert);
    void tick();
    void demanderPieton();
};