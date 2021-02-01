#include <iostream>
#include "Sources/Ground.cpp"
#include "Sources/Wheels.cpp"
#include "Sources/Json.cpp"
#include "Sources/Vehiculo.cpp"
#include <fstream>
#include <vector>
#include <omp.h>

using namespace std;

int main(){

	Json ruta = Json();
	Json Modificaciones = Json();

	Vehiculo vehiculo = Vehiculo();
	int count = 1;
	 
  	while (vehiculo.getDestino() != 1){
  		
  		//Calcula los 40km proximos
  		vector<Ground> Sections = vehiculo.detectarTerreno(); 		 
  		
  		//Mete json
  		ruta.addSection(Sections, count);
  		count++;

  		//Calcula El genetico (tengo que tener buffers referente a donde quede en lectura )
  		for (int NumGround = 0; NumGround <= Sections.size()-1; NumGround++)
  		{
  			// Se le envia al genetico el vehiculo y las caracteristicas de un tramo
  			//genetico(vehiculo, Sections[NumGround]);
  			//Agregarlo a otro json de Modificaciones de llantas
  		}
  	}
  	ruta.close();
	return 0;
}