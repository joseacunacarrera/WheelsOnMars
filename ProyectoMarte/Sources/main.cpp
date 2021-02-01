#include "..\Headers\Genetic.h"
#include "..\Headers\Tierra.h"

int main()
{
    std::vector<std::vector<Range>> torqueTable {{Range(10, 20), Range(70, 100), Range(5, 10)},
                                                {Range(10, 30), Range(70, 100), Range(5, 20)},
                                                {Range(10, 40), Range(60, 70), Range(5, 30)},
                                                {Range(40, 60), Range(55, 60), Range(30, 50)},
                                                {Range(60, 65), Range(40, 55), Range(50, 70)},
                                                {Range(65, 80), Range(20, 40), Range(70, 90)},
                                                {Range(80, 100), Range(0, 20), Range(90, 100)}};

    std::vector<int> torqueEnergyTable {12, 10, 9, 8, 7, 6, 4};

    std::vector<std::vector<Range>> foldingTable {{Range(1, 10), Range(90, 100), Range(1, 5)},
                                                {Range(10, 15), Range(80, 100), Range(5, 10)},
                                                {Range(10, 20), Range(70, 80), Range(10, 25)},
                                                {Range(20, 25), Range(60, 75), Range(20, 30)},
                                                {Range(25, 50), Range(45, 60), Range(30, 50)},
                                                {Range(50, 75), Range(20, 45), Range(50, 80)},
                                                {Range(75, 100), Range(0, 20), Range(80, 100)}};                                             
                                                
    std::vector<int> foldingEnergyTable {15, 14, 11, 10, 8, 7, 6};

    Tierra* tramo = new Tierra(15);
    tramo->setFirmeza(44);
    tramo->setHumedad(18);
    tramo->setAgarre(65);

    Genetic genetic(20, &torqueTable, &foldingTable, &foldingEnergyTable, &torqueEnergyTable, tramo); 

    std::cout << genetic.getBestCombination()->getEnergy() << std::endl;

    return 0;
}