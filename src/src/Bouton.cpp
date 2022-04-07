#include <Arduino.h>
#include "Bouton.h"


Bouton::Bouton(int p_pinBouton1,int p_pinBouton2,Action* p_actionBouton)
                                                    : m_pin1(p_pinBouton1),
                                                    m_pin2(p_pinBouton2),
                                                    m_actionBouton(p_actionBouton)
{
    pinMode(p_pinBouton1,INPUT);
    pinMode(p_pinBouton2,INPUT);
    this->m_derniereDateChangement = 0;
    this->m_dernierEtatBouton1 = HIGH;
    this->m_dernierEtatBouton2 = HIGH;
    this->m_dernierEtatStableBouton1 = HIGH;
    this->m_dernierEtatStableBouton2 = HIGH;
    this->m_delaiMinPression = 25;
}

void Bouton::tick()
{
    int etatBouton1 = digitalRead(m_pin1);
    int etatBouton2 = digitalRead(m_pin2);
    long dateActuelle = millis();
    
    if (etatBouton1 != m_dernierEtatBouton1 || etatBouton2 != m_dernierEtatBouton2)
    {
        m_derniereDateChangement = dateActuelle;
        m_dernierEtatBouton1 = etatBouton1;
        m_dernierEtatBouton2 = etatBouton2;
    }

    if (dateActuelle - m_derniereDateChangement > m_delaiMinPression)
    {
        if ((m_dernierEtatStableBouton1 == HIGH && etatBouton1 == LOW) || (m_dernierEtatStableBouton2 == HIGH && etatBouton2 == LOW))
        {
            this->m_actionBouton->executer();
        }
        m_dernierEtatStableBouton1 = etatBouton1;
        m_dernierEtatStableBouton2 = etatBouton2;
    }

    this->m_actionBouton->maintenirCycle();
}