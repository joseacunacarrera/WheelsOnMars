#include "../Headers/Json.h"

string addPair(string Variable, int Value){
	return ("\"" + Variable + "\"" + " : " + to_string(Value));
}
string addPair(string Variable, string Value){
	return ("\"" + Variable + "\"" + " : " + "\"" + Value + "\"" );
}
//constructors
Json::Json(){

	this->distancia = 0;
	ofstream file;
	file.open("Ruta.json");

	this->json = "{"+	addPair("Origen","552532.54") + ",\n" + addPair("Destino", "12321.52")+ ",\n" + addPair("Distancia",2587)+"\n}";
	file<<json;
	file.close();
}

void Json::addGround(Ground Temp){

	this->TempGround += "{" + addPair("KmStart", this->distancia)+ ",\n" + addPair("KmEnd", this->distancia+Temp.getDistance())+ ",\n" +addPair("Firmeza",Temp.getFirmness())+ ",\n" +addPair("Humedad",Temp.getHumidity()) + ",\n" + addPair("Agarre",Temp.getGrip())+ "\n}" ;
	this->distancia += Temp.getDistance();
}

void Json::addTramo(vector<Ground> Tramo){
	this->TempGround = "\n";
	for (int NumGround = 0; NumGround <= Tramo.size()-1; NumGround++){
  			addGround(Tramo[NumGround]);
  		}
  	ofstream file;
  	file.open("Ruta.json");
  	this->Tramo = "Tramo :[ \n" + this->TempGround + "\n]";
	file<<this->Tramo;
	file.close();
	
	/*
	this->Tramo = "Tramo :[ \n" + this->TempGround + "\n]";
  	this->json += this->Tramo;
  	*/
}