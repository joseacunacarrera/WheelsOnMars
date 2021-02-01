#ifndef Proyect_Wheels
#define Proyect_Wheels

using namespace std;

class Wheels{

private:

	unsigned short int torque;
	unsigned short int fold;

	//firmeza humedad agarre

public:

	//constructors
	Wheels();
	void setFold(unsigned short int pFold);
	int getFold();
	void setTorque(unsigned short int pTorque);
	int getTorque();
};

#endif 

