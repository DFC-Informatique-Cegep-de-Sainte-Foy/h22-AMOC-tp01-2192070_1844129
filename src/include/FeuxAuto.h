#pragma once

#include <Arduino.h>
#include "DEL.h"
#include "FeuxPieton.h"

class FeuxAuto
{
private:
    FeuxPieton* m_feuxPieton;
    DEL* m_DELRouge;
    DEL* m_DELJaune;
    DEL* m_DELVert;
    int m_pietonDemande;
    int m_etatLumiereActuel;
    long m_dernierChangement;
public:
    
    FeuxAuto(DEL* p_DELRouge, DEL* p_DELJaune, DEL* p_DELVert,FeuxPieton* p_feuxPieton);
    void tick();
    void demanderPieton();
};