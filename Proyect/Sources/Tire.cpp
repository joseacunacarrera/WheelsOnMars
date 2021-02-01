#include "../Headers/Tire.h"

Tire::Tire(){
	this->fold = 1;
	this->torque = 1;	
}

void Tire::setFold(unsigned short int pFold){
	this->fold = pFold;
}
int Tire::getFold(){
	return(this->fold);
}
int Tire::getTorque(){
	return(this->torque);
}
void Tire::setTorque(unsigned short int pTorque){
	this->torque = pTorque;
}
