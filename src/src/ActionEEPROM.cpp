#include <Arduino.h>
#include <EEPROM.h>
#include "ActionEEPROM.h"

ActionEEPROM::ActionEEPROM() 
{
    Serial.begin(9600);
    this->m_emplacementPieton = 22;
    this->m_emplacementAuto = 12;
    this->lireStatistiques();
    this->afficherStatistiques();
}

void ActionEEPROM::executer()
{
    this->afficherStatistiques();
}

void ActionEEPROM::effacer()
{
    this->effacerStatistiques();
}

void ActionEEPROM::effacerStatistiques()
{
    byte byte1Pieton = (0 >> 8) & 0xFF;
    byte byte2Pieton = 0 & 0XFF;

    EEPROM.update(this->m_emplacementPieton,byte1Pieton);
    EEPROM.update(this->m_emplacementPieton + 1,byte2Pieton);

    byte byte1Auto = (0 >> 8) & 0xFF;
    byte byte2Auto = 0 & 0XFF;

    EEPROM.update(this->m_emplacementAuto,byte1Auto);
    EEPROM.update(this->m_emplacementAuto + 1,byte2Auto);

    this->lireStatistiques();
}

void ActionEEPROM::afficherStatistiques()
{
    if (m_autoStats <= 0)
    {
        Serial.print("0");
        Serial.println("%");
    }
    else 
    {
        Serial.print(100 * this->m_pietonStats / this->m_autoStats);
        Serial.println("%");
    }
    
    Serial.print(this->m_autoStats);
    Serial.println(" Cycle voiture");

    Serial.print(this->m_pietonStats);
    Serial.println(" Cycle pieton");

    Serial.println();
}

void ActionEEPROM::lireStatistiques()
{
    byte byte1Auto = EEPROM.read(this->m_emplacementAuto);
    byte byte2Auto = EEPROM.read(this->m_emplacementAuto + 1);

    this->m_autoStats = (byte1Auto << 8 ) + byte2Auto;

    byte byte1Pieton = EEPROM.read(this->m_emplacementPieton);
    byte byte2Pieton = EEPROM.read(this->m_emplacementPieton + 1);

    this->m_pietonStats = (byte1Pieton << 8 ) + byte2Pieton;
}

void ActionEEPROM::ecrireStatistiqueAuto()
{
    this->m_autoStats++;
    byte byte1Auto = (this->m_autoStats >>8 ) & 0xFF;
    byte byte2Auto = this->m_autoStats & 0XFF;

    EEPROM.update(this->m_emplacementAuto,byte1Auto);
    EEPROM.update(this->m_emplacementAuto + 1,byte2Auto);
}

void ActionEEPROM::ecrireStatistiquePieton()
{
    this->m_pietonStats++;
    byte byte1Pieton = (this->m_pietonStats >> 8) & 0xFF;
    byte byte2Pieton = this->m_pietonStats & 0XFF;

    EEPROM.update(this->m_emplacementPieton,byte1Pieton);
    EEPROM.update(this->m_emplacementPieton + 1,byte2Pieton);
}

void ActionEEPROM::maintenirCycle()
{
    ;
}