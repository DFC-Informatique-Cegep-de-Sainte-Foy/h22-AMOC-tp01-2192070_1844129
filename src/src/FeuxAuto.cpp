#include <Arduino.h>
#include <EEPROM.h>
#include "FeuxAuto.h"

FeuxAuto::FeuxAuto(DEL* p_DELRouge, DEL* p_DELJaune, DEL* p_DELVert,
FeuxPieton* p_feuxPieton,ActionEEPROM* p_eeprom)
: m_DELRouge(p_DELRouge), m_DELJaune(p_DELJaune), m_DELVert(p_DELVert),m_feuxPieton(p_feuxPieton)
,m_actionEEPROM(p_eeprom)
{
    this->m_pietonDemande = 0;
    this->m_etatLumiereActuel = 0;
    this->m_dernierChangement = 0;
}

void FeuxAuto::demanderPieton()
{
    this->m_pietonDemande = 1;
    this->m_pietonStats++;
    this->m_actionEEPROM->ecrireStatistiquePieton();
}

void FeuxAuto::tick()
{
    long dateActuelle = millis();

    if(this->m_etatLumiereActuel == 0)
    {
        this->m_DELJaune->allumer();
        this->m_etatLumiereActuel = 3;
    }

    else if(dateActuelle - this->m_dernierChangement > 2000 && this->m_etatLumiereActuel == 3 && this->m_pietonDemande == 0)
    {                                                   //5000
        this->m_DELJaune->eteindre();
        this->m_DELRouge->allumer();
        this->m_etatLumiereActuel = 1;
        this->m_dernierChangement = dateActuelle;
    }

    else if(dateActuelle - this->m_dernierChangement > 2000 && this->m_etatLumiereActuel == 1)
    {                                                  //15000
        this->m_DELRouge->eteindre();
        this->m_DELVert->allumer();
        this->m_etatLumiereActuel = 2;
        this->m_dernierChangement = dateActuelle;
        this->m_autoStats++;
        this->m_actionEEPROM->ecrireStatistiqueAuto();
    }

    else if(dateActuelle - this->m_dernierChangement > 2000 && this->m_etatLumiereActuel == 2)
    {                                                   //30000
        this->m_DELVert->eteindre();
        this->m_DELJaune->allumer();
        this->m_etatLumiereActuel = 3;
        this->m_dernierChangement = dateActuelle;
    }

    else if(dateActuelle - this->m_dernierChangement > 2000 && this->m_etatLumiereActuel == 3 && this->m_pietonDemande == 1)
    {                                                   //5000
        this->m_DELJaune->eteindre();
        this->m_DELRouge->allumer();

        this->m_etatLumiereActuel = this->m_feuxPieton->activerPieton();
        this->m_dernierChangement = dateActuelle;
    }

    else if(dateActuelle - this->m_dernierChangement > 4000 && this->m_etatLumiereActuel == 4)
    {                                                   //30000
        this->m_DELRouge->eteindre();
        this->m_DELVert->allumer();
        this->m_etatLumiereActuel = 2;
        this->m_pietonDemande = 0;
        this->m_dernierChangement = dateActuelle;
    }
}