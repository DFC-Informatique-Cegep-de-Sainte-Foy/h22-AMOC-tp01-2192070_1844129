#pragma once

class DEL
{
private:
    int m_pin;
public:
    DEL(int p_pin);
    void allumer();
    void eteindre();
};