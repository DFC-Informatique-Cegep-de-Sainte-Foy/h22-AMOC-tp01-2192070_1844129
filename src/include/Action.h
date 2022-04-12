#pragma once

class Action
{
public:
    Action();
    virtual void executer() = 0;
    virtual void maintenirCycle() = 0;
    virtual void effacer() = 0;
};
