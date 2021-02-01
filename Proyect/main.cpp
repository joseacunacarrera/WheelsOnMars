#include <iostream>
#include "Sources/Ground.cpp"
#include "Sources/Wheels.cpp"
#include "Sources/Json.cpp"
#include "Sources/Vehiculo.cpp"
#include "Sources/Genetic.cpp"
#include <fstream>
#include <vector>
#include <omp.h>

using namespace std;

int main(){

	Json ruta = Json();
	Json Modificaciones = Json();

	Vehiculo vehiculo = Vehiculo();
	int count = 1;

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

	std::vector<int> foldingValueTable {10, 9, 8, 7, 6, 5, 4};
	 
  	while (vehiculo.getDestino() != 1){
  		
  		//Calcula los 40km proximos
  		vector<Ground> Sections = vehiculo.detectarTerreno(); 		 
  		
  		//Mete json
  		ruta.addSection(Sections, count);
		
		cout << "\n------------# de Tramo: " << count << "------------\n";

  		count++;

  		//Calcula El genetico (tengo que tener buffers referente a donde quede en lectura )
  		for (int NumGround = 0; NumGround <= Sections.size()-1; NumGround++)
  		{
  			// Se le envia al genetico el vehiculo y las caracteristicas de un tramo
  			Genetic genetic(20, &torqueTable, &foldingTable, &foldingEnergyTable, &torqueEnergyTable, &Sections[NumGround]);
			Tire* nuevaTire = genetic.getBestCombination();
			cout << "\nTerreno: " << NumGround << endl;
			cout << "\tDistancia:" << Sections.at(NumGround).getDistance() << 
				 	"\n\tFirmness: " << Sections.at(NumGround).getFirmness() <<
					"\n\tHumidity: " << Sections.at(NumGround).getHumidity() <<
					"\n\tGrip: " << Sections.at(NumGround).getGrip() << "\n";
			cout << "Torque: " << ((nuevaTire->getTorque() * 7) / 65536) + 1 << " Pliegue: " <<
					 foldingValueTable.at((nuevaTire->getFolding() * 7) / 65536) << " Energia Consumida: " << 
					 torqueEnergyTable.at((nuevaTire->getTorque() * 7) / 65536) + foldingEnergyTable.at((nuevaTire->getFolding() * 7) / 65536) << endl;
  			//Agregarlo a otro json de Modificaciones de llantas
  		}
  	}
  	ruta.close();
	return 0;
}