#include "../Headers/Vehiculo.h"


//constructors
Vehiculo::Vehiculo(){
	this->bateria = 7000;				// maximo de bateria
	this->wheels = Wheels();
	this->distanciaRecorrida = 0;
	//this->ubicacionActual = 1837294.25;
	this->destino = 0;
	this->Km = 2587;
}

Vehiculo::Vehiculo(int pBateria, Wheels pWheels, int distancia){
	this->bateria = pBateria;				
	this->wheels = pWheels;
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
		this->distanciaRecorrida += tramo.getDistance();
		if(this->distanciaRecorrida > this->Km){
			this->destino=1;
			break;
		}
	}

	return (array);

}

//Cosumo de Energia realizado en una distancia de Tramo tras seleccion de llanatas
void Vehiculo::consumoEnergia(int distanciaTramo){
	// pliegue y torque no tiene que se binario
	int energia = this->wheels.getFold() + this->wheels.getTorque();
	int bateria = (this->bateria / energia);
	int consumo = (bateria - distanciaTramo);

	this->bateria = (consumo * energia);
}




