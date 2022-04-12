#include <Arduino.h>
#include "Bouton.h"


Bouton::Bouton(int p_pinBouton,Action* p_actionBouton)
                                                    : m_pin(p_pinBouton),                                                   
                                                    m_actionBouton(p_actionBouton)
{
    pinMode(p_pinBouton,INPUT);
    this->m_derniereDateChangement = 0;
    this->m_dernierEtatBouton = HIGH;
    this->m_dernierEtatStableBouton = HIGH;
    this->m_delaiMinPression = 25;
    this->m_tempsAppuye = 0;
}

void Bouton::tick()
{
    int etatBouton = digitalRead(m_pin);

    long dateActuelle = millis();
    
    if (etatBouton != this->m_dernierEtatBouton)
    {
        this->m_derniereDateChangement = dateActuelle;
        this->m_dernierEtatBouton = etatBouton;
    }

    if (dateActuelle - this->m_derniereDateChangement > this->m_delaiMinPression)
    {
        if (this->m_dernierEtatStableBouton == HIGH && etatBouton == LOW)
        {
            this->m_tempsAppuye = millis();
            this->m_actionBouton->executer();
        }
        this->m_dernierEtatStableBouton = etatBouton;
        if (this->m_dernierEtatStableBouton == LOW && etatBouton == LOW)
        {
            if (dateActuelle - this->m_tempsAppuye > 5000)
            {
                this->m_actionBouton->effacer();
            }
        }
    }
    this->m_actionBouton->maintenirCycle();
}