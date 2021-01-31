#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#ifndef Proyect_Json
#define Proyect_Json
using namespace std;

class Json{

private:
	std::string json;
	std::string Tramo;
	std::string TempGround;
	int distancia;

public:
	Json();
	void addGround(Ground Temp);
	void addTramo(vector<Ground> Tramo);
};

#endif 

