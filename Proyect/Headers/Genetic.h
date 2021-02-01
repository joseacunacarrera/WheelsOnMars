#include <iostream>
#include <algorithm>
#include <vector>
#include "Tire.h"
#include "Range.h"
#include "Ground.h"

class Genetic
{

private:
    int populationNumber;
    std::vector<Tire*> population;
    std::vector<std::vector<Range>> *torqueTable;
    std::vector<std::vector<Range>> *foldingTable;
    std::vector<int> *foldingEnergyTable;
    std::vector<int> *torqueEnergyTable;
    Ground *section;

public:
    Genetic(int pPopulationNumber, std::vector<std::vector<Range>> *pTorqueTable, std::vector<std::vector<Range>> *pFoldingTable, std::vector<int> *pFoldingEnergyTable, std::vector<int> *pTorqueEnergyTable, Ground *pSection)
    {
        populationNumber = pPopulationNumber;
        torqueTable = pTorqueTable;
        foldingTable = pFoldingTable;
        torqueEnergyTable = pTorqueEnergyTable;
        foldingEnergyTable = pFoldingEnergyTable;
        section = pSection;
    }

    Tire* getBestCombination();

    void calculateFitness(Tire* pTire);

    void reproducePopulation(std::vector<Tire*> remainingPopulation);
};