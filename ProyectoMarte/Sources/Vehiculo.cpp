#include "../Headers/Vehiculo.h"


//constructors
Vehiculo::Vehiculo(){
	this->bateria = 7000;				// maximo de bateria
	this->ubicacionActual = ;
	this->llantas = new Llantas();
	this->distanciaRecorrida = 0;
}

//setters & getters
Ruta Vehiculo::trasarRuta(int ubicacionActual){

}
	
void Vehiculo::detectarTerreno(){
	Tierra tramo = new Tierra();
	int distancia = 40-tramo.getDistancia();
	
	// meter json

	while(distancia>0) {
		tramo = new Tierra(distancia);
		distancia = distancia - tramo.getDistancia();
	
		//meter en el json
	
	}
}


//distanciaRecorrida ()
void Vehiculo::consumoEnergia(int distanciaTramo){
	int energia = this->llantas.getPliegue() + this->llantas.getTorque();
	int bateria = (this->bateria / energia);
	int consumo = (bateria - distanciaRecorrida);

	this->bateria = (consumo * energia);
}




