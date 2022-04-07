#pragma once

class Action
{
public:
    Action();
    virtual void Executer() = 0;
    virtual void maintenirClignotement() = 0;
};
