#include "..\Headers\Genetic.h"

using namespace std;

bool compareFitnessValue(Tire* firstTire, Tire* secondTire)
{
    return (firstTire->getFitness() < secondTire->getFitness());
}

bool compareEnergy(Tire* firstTire, Tire* secondTire)
{
    return (firstTire->getEnergy() < secondTire->getEnergy());
}

void Genetic::reproducePopulation(vector<Tire*> remainingPopulation)
{
    int totalReproductions = 0;
    int populationSize = remainingPopulation.size();
    vector<Tire*> newPopulation;

    while (totalReproductions != 20)
    {
        Tire* first = remainingPopulation.at(rand() % populationSize);
        Tire* second = remainingPopulation.at(rand() % populationSize);

        // 75% 
        unsigned short int firstMask = 65472;
        // 25%
        unsigned short int secondMask = 63;

        newPopulation.push_back(new Tire(((first->getTorque() & firstMask) | (second->getTorque() & secondMask)),
                                         ((second->getFolding() & firstMask) | (second->getFolding() & secondMask))));

        totalReproductions++;
    }

    population = newPopulation;
}

Tire* Genetic::getBestCombination()
{
    // create individuals
    for (int counter = 0; counter < populationNumber; counter++)
    {
        unsigned short int torque = rand() % 65536 + 1;
        unsigned short int folding = rand() % 65536 + 1;
        population.push_back(new Tire(torque, folding));
    }
    for (int firstIndex = 0; firstIndex < 10; firstIndex++)
    {
        // score each individual based on the fitness function
        for (int index = 0; index < populationNumber; index++)
        {
            calculateFitness(population.at(index));
        }
        // sort based on it's fitness value
        sort(population.begin(), population.end(), compareFitnessValue);
        // select the top 60%
        auto topFitness = population.begin() + (populationNumber * 60) / 100;
        vector<Tire*> topFitnessVector(population.begin(), topFitness);
        // sort remaining based on it's energy consumption
        sort(topFitnessVector.begin(), topFitnessVector.end(), compareEnergy);
        // select the top 50%
        auto topEnergy = topFitnessVector.begin() + (topFitnessVector.size() * 50) / 100;
        vector<Tire*> topEnergyVector(topFitnessVector.begin(), topEnergy);
        // reproduce the remaining to get a new population
        reproducePopulation(topEnergyVector);
    }
    // return the best ranked tire configuration
    return population.at(0);
}

void Genetic::calculateFitness(Tire* pTire)
{
    // calculate torque index
    int torqueIndex = (pTire->getTorque() * 7) / 65536;
    // calculate torque percentage
    int torquePercentage = ((pTire->getTorque() - (9362 * torqueIndex)) * 100) / 9362;
    // calculate firmness, humidity and grip of the torque
    vector<Range> torqueTableIndex = torqueTable->at(torqueIndex);
    int torqueFirmness = ((torqueTableIndex.at(0).max - torqueTableIndex.at(0).min) * (torquePercentage / 100)) + torqueTableIndex.at(0).min;
    int torqueHumidity = ((torqueTableIndex.at(1).max - torqueTableIndex.at(1).min) * (torquePercentage / 100)) + torqueTableIndex.at(1).min;
    int torqueGrip = ((torqueTableIndex.at(2).max - torqueTableIndex.at(2).min) * (torquePercentage / 100)) + torqueTableIndex.at(2).min;
    // calculate fitness value of the torque
    int torqueFitnessValue = abs(torqueFirmness - section->getFirmness()) + abs(torqueHumidity - section->getHumidity()) + abs(torqueGrip - section->getGrip());
    // calculate folding index
    int foldingIndex = (pTire->getFolding() * 7) / 65535;
    // calculate folding percentage
    int foldingPercentage = ((pTire->getFolding() - (9362 * foldingIndex)) * 100) / 9362;
    // calculate firmness, humidity and grip of the folding
    vector<Range> foldingTableIndex = foldingTable->at(foldingIndex);
    int foldingFirmness = ((foldingTableIndex.at(0).max - foldingTableIndex.at(0).min) * (foldingPercentage / 100)) + foldingTableIndex.at(0).min;
    int foldingHumidity = ((foldingTableIndex.at(1).max - foldingTableIndex.at(1).min) * (foldingPercentage / 100)) + foldingTableIndex.at(1).min;
    int foldingGrip = ((foldingTableIndex.at(2).max - foldingTableIndex.at(2).min) * (foldingPercentage / 100)) + foldingTableIndex.at(2).min;
    // calculate fitness value of the folding
    int foldingFitnessValue = abs(foldingFirmness - section->getFirmness()) + abs(foldingHumidity - section->getHumidity()) + abs(foldingGrip - section->getGrip());
    // set fitness value of the tire configuration
    pTire->setFitness(torqueFitnessValue + foldingFitnessValue);
    // set energy consumption of the tire configuration
    pTire->setEnergy(torqueEnergyTable->at(torqueIndex) + torqueEnergyTable->at(foldingIndex));
}