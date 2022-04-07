#include <Arduino.h>
#include "DEL.h"

DEL::DEL(int p_pin) : m_pin(p_pin)
{
    pinMode(m_pin,OUTPUT);
}

void DEL::allumer()
{
    digitalWrite(m_pin,HIGH);
}

void DEL::eteindre()
{
    digitalWrite(m_pin,LOW);
}