#ifndef Proyect_Tire
#define Proyect_Tire

using namespace std;

class Tire{

private:

	unsigned short int torque;
	unsigned short int fold;

	//firmeza humedad agarre

public:

	//constructors
	Tire();
	void setFold(unsigned short int pFold);
	int getFold();
	void setTorque(unsigned short int pTorque);
	int getTorque();
};

#endif 

