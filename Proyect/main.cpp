#include <iostream>
#include "Sources/Ground.cpp"
#include "Sources/Tire.cpp"
#include "Sources/Json.cpp"
#include "Sources/Vehiculo.cpp"
#include <fstream>
#include <vector>

using namespace std;

int main(){

	Ground tierra(50);
	cout<<tierra.getDistance();

	Json ruta = Json();

	Vehiculo vehiculo = Vehiculo();

	 
  	while (vehiculo.getDestino() != 1){
  		
  		//Calcula los 40km proximos
  		vector<Ground> Tramos = vehiculo.detectarTerreno(); 		 
  		ruta.addTramo(Tramos);

  		//Calcula El genetico (tengo que tener buffers referente a donde quede en lectura )
  		
  		break;
  	}
	return 0;
}