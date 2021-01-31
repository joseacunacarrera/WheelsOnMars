#include "iostream"
#include "../Headers/Tire.h"
#include "Ground.h"
#include <vector>

#ifndef Proyect_Vehiculo
#define Proyect_Vehiculo

using namespace std;

class Vehiculo{

private:

	float bateria;
	Tire Tires;
	int distanciaRecorrida;		// distancia total de
	int destino;
	//float ubicacionActual;	meter ubicacionActual a la ruta
	

public:

	//constructors
	Vehiculo();
	Vehiculo(int pBateria, Tire pTires, int distancia);


	//setters & getters		
	void setDestino(int pDestino);
	int getDestino();

	//Detecta el terreno a un alcance de 40 km
	std::vector<Ground> detectarTerreno();		

	//Realiza el cosumo de energia pertinente a la seleccion dada
	void consumoEnergia(int distanciaTramo);

};

#endif 
