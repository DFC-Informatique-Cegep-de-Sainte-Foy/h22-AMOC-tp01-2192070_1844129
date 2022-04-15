#include <Arduino.h>
#include "FeuxPieton.h"

const int tempsDureeVerte = 20000;

FeuxPieton::FeuxPieton(DEL* p_delRouge,DEL* p_delVert) : m_delRouge(p_delRouge),
                                                         m_delVert(p_delVert)
{
    this->m_derniereDateChangement = 0;
    this->m_dernierEtatPieton = HIGH;
    this->m_etatPieton = 0;
    this->m_delRouge->allumer();
}

int FeuxPieton::activerPieton()
{
    this->m_etatPieton = 1;
    this->m_derniereDateChangement = millis();
    return 4;
}

void FeuxPieton::tick()
{
    long dateActuelle = millis();

    if (this->m_etatPieton == 1)
    {                                         
        this->m_delRouge->eteindre();
        this->m_delVert->allumer();
        this->m_derniereDateChangement = dateActuelle;
        this->m_etatPieton = 0;
    }
    

    if (this->m_etatPieton == 0 && dateActuelle - this->m_derniereDateChangement > tempsDureeVerte)
    {                                                                     
        this->m_derniereDateChangement = dateActuelle;
        this->m_delVert->eteindre();
        this->m_delRouge->allumer();
    }
}