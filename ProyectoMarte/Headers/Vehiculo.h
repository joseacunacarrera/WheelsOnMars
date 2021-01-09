#include "iostream"
#include "Llanta.h"
#include "Tierra.h"
#include "Ruta.h"

#ifndef ProyectoMarte_Vehiculo
#define ProyectoMarte_Vehiculo

class Vehiculo{

private:

	float bateria;
	float ubicacionActual;
	Llanta llantas;
	int distanciaRecorrida;

public:

	//constructors
	Vehiculo();


	//setters & getters

	//genera punto destino y cantidad a recorrer
	Ruta trasarRuta(int ubicacionActual);		

	//Detecta el terreno a un alcance de 40 km
	void detectarTerreno();		

	//Realiza el cosumo de energia pertinente a la seleccion dada
	void consumoEnergia(int distanciaTramo);

}

#endif 

ajustarLlantas
	tiene dos componenytes 
		- torque de lmarcha
		- pliegues de agarre
terreno 