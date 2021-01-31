#include "../Headers/Ground.h"

//constructor
Ground::Ground(){
	this->distance = rand() % 41;
	this->firmness =  rand() % 100 ;
	this->humidity =  rand() % 100;;
	this->grip =  rand() % 100;
}

Ground::Ground(int pDistance){
	this->distance = rand() % pDistance;
	this->firmness =  rand() % 100 ;
	this->humidity =  rand() % 100;;
	this->grip =  rand() % 100;
}

//Setter & Getter
void Ground::setDistance(int pDistance){
	this->firmness = pDistance;
}

int Ground::getDistance(){
	return this->distance;
}

void Ground::setFirmness(int pFirmness){
	this->firmness = pFirmness;
}

int Ground::getFirmness(){
	return this->firmness;
}

void Ground::setHumidity(int pHumidity){
	this->humidity = pHumidity;
}
int Ground::getHumidity(){
	return this->humidity;
}

void Ground::setGrip(int pGrip){
	this->grip = pGrip;
}
int Ground::getGrip(){
	return this->grip;
}