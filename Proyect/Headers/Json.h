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
	string json;
	string section;
	string TempGround;
	int count;

public:
	Json();
	void addGround(Ground Temp , int num);
	void addSection(vector<Ground> Sections, int run);
	void close();
};

#endif 

