#include "iostream"

#ifndef ProyectoMarte_Tierra
#define ProyectoMarte_Tierra

class Tierra{

private:

	int distancia;
	int firmeza;
	int humedad;
	int agarre;

public:

	//constructors
	Tierra();
	Tierra(int distancia);

	//setters & getters
	void setFirmeza(int pFirmeza);
	int getFirmea();

	void setHumedad(int pHumedad);
	int getHumedad();

	void setAgarre(int pAgarre);
	int getAgarre();
}

#endif 

