#ifndef Proyect_Ground
#define Proyect_Ground

using namespace std;

class Ground{

private:

	int distance;
	int firmness;
	int humidity;
	int grip;

public:

	//constructors
	Ground();
	Ground(int distance);

	//setters & getters

	void setDistance(int pDistance);
	int getDistance();

	void setFirmness(int pFirmness);
	int getFirmness();

	void setHumidity(int pHumidity);
	int getHumidity();

	void setGrip(int pGrip);
	int getGrip();
};

#endif 

