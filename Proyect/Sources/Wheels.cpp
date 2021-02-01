#include "../Headers/Wheels.h"

Wheels::Wheels(){
	this->fold = 1;
	this->torque = 1;	
}

void Wheels::setFold(unsigned short int pFold){
	this->fold = pFold;
}
int Wheels::getFold(){
	return(this->fold);
}
int Wheels::getTorque(){
	return(this->torque);
}
void Wheels::setTorque(unsigned short int pTorque){
	this->torque = pTorque;
}
