#pragma once
#include "Action.h"

class ActionEEPROM : public Action
{
private:
    int m_pietonStats;
    int m_autoStats;
    int m_emplacementAuto;
    int m_emplacementPieton;
public:
    ActionEEPROM();
    virtual void executer();
    void afficherStatistiques();
    void effacerStatistiques();
    void lireStatistiques();
    void ecrireStatistiqueAuto();
    void ecrireStatistiquePieton();
    virtual void maintenirCycle();
    virtual void effacer();
};