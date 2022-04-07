#include <Arduino.h>
#include "FeuxAuto.h"


FeuxAuto::FeuxAuto(DEL* p_DELRouge, DEL* p_DELJaune, DEL* p_DELVert):m_DELRouge(p_DELRouge), m_DELJaune(p_DELJaune), m_DELVert(p_DELVert)
{
    m_pietonDemande = 0;
    m_etatLumiereActuel = 0;
}

void FeuxAuto::demanderPieton()
{
    m_pietonDemande = 1;
}

void FeuxAuto::tick()
{
    long dateActuelle = millis();
    long dernierChangement = 0;
    if(m_etatLumiereActuel == 0)
    {
        m_DELJaune->allumer();
        m_etatLumiereActuel = 3;
    }

    else if(dateActuelle - dernierChangement > 5000 && m_etatLumiereActuel == 3 && m_pietonDemande == 0)
    {
        m_DELJaune->eteindre();
        m_DELRouge->allumer();
        m_etatLumiereActuel = 1;
        dernierChangement = dateActuelle;
    }

    else if(dateActuelle - dernierChangement > 15000 && m_etatLumiereActuel == 1)
    {
        m_DELRouge->eteindre();
        m_DELVert->allumer();
        m_etatLumiereActuel = 2;
        dernierChangement = dateActuelle;
    }

    else if(dateActuelle - dernierChangement > 30000 && m_etatLumiereActuel == 2)
    {
        m_DELVert->eteindre();
        m_DELJaune->allumer();
        m_etatLumiereActuel = 3;
        dernierChangement = dateActuelle;
    }

    else if(dateActuelle - dernierChangement > 5000 && m_etatLumiereActuel == 3 && m_pietonDemande == 1)
    {
        m_DELJaune->eteindre();
        m_DELRouge->allumer();

        m_etatLumiereActuel = m_feuxPieton->activerPieton();
        dernierChangement = dateActuelle;
    }

    else if(dateActuelle - dernierChangement > 30000 && m_etatLumiereActuel == 4)
    {
        m_DELRouge->eteindre();
        m_DELVert->allumer();
        m_etatLumiereActuel = 2;
        dernierChangement = dateActuelle;
    }
}