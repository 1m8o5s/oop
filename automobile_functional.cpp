#include "automobile_definition.h"
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
void Auto::changeColor(int r, int g, int b){
	Auto::rgb_color[0] = r;
	Auto::rgb_color[1] = g;
	Auto::rgb_color[2] = b;
}
void Auto::changeColor(int r, int g, int b, string newznak){
	Auto::rgb_color[0] = r;
	Auto::rgb_color[1] = g;
	Auto::rgb_color[2] = b;
	Auto::nomernii_znak = newznak;
}
void Auto::changeMotor(string newmotor){
	Auto::motor_name = newmotor;
}
void Auto::changeMotor(string newmotor, int powerful){
	Auto::motor_name = newmotor;
	Auto::speed = powerful / 20;
}
void Auto::changeNomerniiZnak(string newznak){
	Auto::nomernii_znak = newznak;
}
void Auto::changeSpeed(int speed){
	Auto::speed = speed;
}

string Auto::getProizvoditel(){
	return this->proizvoditel;
}
string Auto::getModel(){
	return this->model;
}
string Auto::getMotorName(){
	return this->motor_name;
}
int Auto::getYearOfBirth(){
	return this->year_of_birth;
}
string Auto::getSeriiniiNomer(){
	return this->seriinii_nomer;
}
void Auto::setProizvoditel(string proizvoditel){
	this->proizvoditel = proizvoditel;
}
void Auto::setModel(string model){
	this->model = model;
}
void Auto::setMotorName(string motor_name){
	this->motor_name = motor_name;
}
void Auto::setYearOfBirth(int year){
	this->year_of_birth = year;
}
void Auto::setSeriiniiNomer(string seriinii_nomer){
	this->seriinii_nomer = seriinii_nomer;
}


void Auto::readProizvoditel(string file){
	ifstream fin(file);
	string proizvoditel;
	fin >> proizvoditel;
	Auto::setProizvoditel(proizvoditel);
}//template
void Auto::writeProizvoditel(string file){
	ofstream fout(file);
	fout << Auto::getProizvoditel();
}//template
void Auto::readAll(string file){
	ifstream fin(file);
	string proizvoditel;
	string model;
	string motor_name;
	int year_of_birth;
	string seriinii_nomer;

	fin >> proizvoditel >> model >> motor_name >> year_of_birth >> seriinii_nomer 
		>> Auto::rgb_color[0] >> Auto::rgb_color[1] 
		>> Auto::rgb_color[2] >> nomernii_znak >> speed;

	Auto::setProizvoditel(proizvoditel);
	Auto::setModel(model);
	Auto::setMotorName(motor_name);
	Auto::setYearOfBirth(year_of_birth);
	Auto::setSeriiniiNomer(seriinii_nomer);
}
void Auto::writeAll(string file){
	ofstream fout(file);
	fout << Auto::getProizvoditel() << Auto::getModel() << Auto::getMotorName() << Auto::getYearOfBirth() << Auto::getSeriiniiNomer()
		<< Auto::rgb_color[0] << Auto::rgb_color[1] << Auto::rgb_color[2] << Auto::nomernii_znak << Auto::speed;
}
void Auto::sortOfRandomSetOfSpeed(){
	srand(time(0));
	int s = rand() % 20 + 5;
	int j = 0;
	int * arr_ = new int [s];
	for (int i = 0; i < s; i++){
		arr_[i] = this->speed / (i + 1);
	}
	bool swapped = false;
	int * tmp = 0;
	do{
		for (int i = 0; i < --s; i++, j++){
			if (arr_[i] > arr_[i + i]){
				*tmp = arr_[i];
				arr_[i] = arr_[i+1];
				arr_[i+1] = *tmp;
				swapped = true;
			}
		}
	} while (swapped);
	/*for (int i = 0; i < j; j++){
		cout << arr_[i];
	}*/
}