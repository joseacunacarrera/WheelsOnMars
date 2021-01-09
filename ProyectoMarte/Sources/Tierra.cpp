#include "../Headers/Tierra.h"

//constructor
Tierra::Tierra(){
	this->distancia = rand() % 41;
	this->firmeza =  rand() % 100 ;
	this->humedad =  rand() % 100;;
	this->agarre =  rand() % 100;
}

Tierra::Tierra(int pDistancia){
	this->distancia = rand() % pDistancia;
	this->firmeza =  rand() % 100 ;
	this->humedad =  rand() % 100;;
	this->agarre =  rand() % 100;
}

//Setter & Getter
void Tierra::setDistancia(int pDistancia){
	this->firmeza = pDistancia;
}

int Tierra::getDistancia(){
	return this->distancia;
}

void Tierra::setFirmeza(int pFirmeza){
	this->firmeza = pFirmeza;
}

int Tierra::getFirmeza(){
	return this->firmeza;
}

void Tierra::setHumedad(int pHumedad){
	this->humedad = pHumedad;
}
int Tierra::getHumedad(){
	return this->humedad;
}

void Tierra::setAgarre(int pAgarre){
	this->agarre = pAgarre;
}
int Tierra::getAgarre(){
	return this->agarre;
}