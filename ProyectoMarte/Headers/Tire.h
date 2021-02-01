#include <iostream>

class Tire
{
private:
    unsigned short int torque;
    unsigned short int folding;
    int energy;
    int fitnessValue;

public:
    Tire(unsigned short int pTorque, unsigned short int pFolding)
    {
        torque = pTorque;
        folding = pFolding;
        energy = 0;
        fitnessValue = 0;
    }

    unsigned short int getTorque()
    {
        return torque;
    }

    unsigned short int getFolding()
    {
        return folding;
    }

    int getEnergy()
    {
        return energy;
    }

    int getFitness()
    {
        return fitnessValue;
    }

    void setFitness(int pFitnessValue)
    {
        this->fitnessValue = pFitnessValue;
    }

    void setEnergy(int pEnergy)
    {
        this->energy = pEnergy;
    }
};