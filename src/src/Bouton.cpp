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
    this->m_dernierEtatBouton = HIGH;
    this->m_dernierEtatStableBouton = HIGH;
    this->m_delaiMinPression = 25;
}

void Bouton::tick()
{
    int etatBouton = digitalRead(m_pin1);
    int etatBouton = digitalRead(m_pin2);
    long dateActuelle = millis();
    
    if (etatBouton != m_dernierEtatBouton)
    {
        m_derniereDateChangement = dateActuelle;
        m_dernierEtatBouton = etatBouton;
    }

    if (dateActuelle - m_derniereDateChangement > m_delaiMinPression)
    {
        if (m_dernierEtatStableBouton == HIGH && etatBouton == LOW)
        {
            this->m_actionBouton->Executer();
        }
        m_dernierEtatStableBouton = etatBouton;
    }

    this->m_actionBouton->maintenirCycle();
}