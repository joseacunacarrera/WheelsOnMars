#include "../Headers/Vehiculo.h"
#include "../Headers/Tire.h"
#include <vector>

//constructors
Vehiculo::Vehiculo(){
	this->bateria = 7000;				// maximo de bateria
	this->Tires = Tire();
	this->distanciaRecorrida = 0;
	//this->ubicacionActual = 1837294.25;
	this->destino = 0;
}

Vehiculo::Vehiculo(int pBateria, Tire pTires, int distancia){
	this->bateria = pBateria;				
	this->Tires = pTires;
	this->distanciaRecorrida = distancia;
	this->destino = 0;
	//this->ubicacionActual = 1837294.25;
}

//setters & getters
void Vehiculo::setDestino(int pDestino){
	this->destino = pDestino;
}

int Vehiculo::getDestino(){
	return this->destino;
}

//Funcion de detectar el terreno hasta 40 kilomero delante
std::vector<Ground> Vehiculo::detectarTerreno(){

	int alcance = 40;
	std::vector<Ground> array ;

	while(alcance<=40 and alcance>1) {
		//cout<<"alcance"<<alcance<<"\n";
		Ground tramo =  Ground(alcance);
		
		//cout<<"tramo.getDistance"<<tramo.getDistance()<<"\n";
		alcance = alcance - tramo.getDistance();

		//cout<<"alcance"<<alcance<<"\n";
		array.push_back(tramo);
	}

	return (array);

}

//Cosumo de Energia realizado en una distancia de Tramo tras seleccion de llanatas
void Vehiculo::consumoEnergia(int distanciaTramo){
	// pliegue y torque no tiene que se binario
	int energia = this->Tires.getFold() + this->Tires.getTorque();
	int bateria = (this->bateria / energia);
	int consumo = (bateria - distanciaRecorrida);

	this->bateria = (consumo * energia);
}




