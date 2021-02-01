#include "../Headers/Json.h"

string addPair(string Variable, int Value){
	return ("\"" + Variable + "\"" + " : " + to_string(Value));
}
string addPair(string Variable, string Value){
	return ("\"" + Variable + "\"" + " : " + "\"" + Value + "\"" );
}
//constructors
Json::Json(){

	this->count = 0;
	ofstream file;
	file.open("Ruta.json");

	this->json = "{"+	addPair("Origen","552532.54") + ",\n" + addPair("Destino", "12321.52")+ ",\n" + addPair("Distancia",2587)+"\n";
	file<<json;
	file.close();
}

void Json::addGround(Ground Temp, int num){

	this->TempGround += "{" + addPair("KmStart", this->count)+ ",\n" + addPair("KmEnd", this->count+Temp.getDistance())+ ",\n" +addPair("Firmeza",Temp.getFirmness())+ ",\n" +addPair("Humedad",Temp.getHumidity()) + ",\n" + addPair("Agarre",Temp.getGrip())+ "\n}" ;
	this->count += Temp.getDistance();
	if(num>0){
		this->TempGround += ",";
	}
}

void Json::addSection(vector<Ground> Sections, int run){
	this->TempGround = "\n";
	for (int NumGround = 0; NumGround <= Sections.size()-1; NumGround++){
  			addGround(Sections[NumGround],Sections.size()-1-NumGround);
  		}
  	ofstream file;
  	file.open("Ruta.json", std::ios_base::app);
  	this->section = ",\"Tramo"+  to_string(run) + "\""+"  :[ " + this->TempGround + "]";
	file << this->section << endl;


	file.close();

	/*
	this->section = "Tramo :[ \n" + this->TempGround + "\n]";
  	this->json += this->section;
  	*/
}
void Json::close(){

  	ofstream file;
  	file.open("Ruta.json", std::ios_base::app);
	file <<"}";
	file.close();

	/*
	this->section = "Tramo :[ \n" + this->TempGround + "\n]";
  	this->json += this->section;
  	*/
}