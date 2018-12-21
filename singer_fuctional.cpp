#define _CRT_SECURE_NO_WARNINGS
#include "singer_definition.h"
#include <iostream>
#include <fstream>
using namespace std;
Singer::Singer(){
	cout << endl << "Singer Constructor" << endl;
}
Singer::~Singer(){
	cout << endl << "Singer Destructor" << endl;
}
void Singer::setCityForConcert(char*city){
	strcpy(this->city_for_concert_, city);
}
char* Singer::getCityForConcert() {
	return this->city_for_concert_;
}
int Singer::getDateOfConcert() {
	return this->date_of_concert_;
}
void Singer::setDateOfConcert(int date){
	this->date_of_concert_ = date;
}
int Singer::getMoney(){
	return this->money_;
}
void Singer::setMoney(int money){
	this->money_ = money;
}
void Singer::setName(char*name){
	strcpy(this->name_, name);
}
char* Singer::getName() {
	return this->name_;
}
void Singer::readDataFieldsFromFile(ifstream&file) {
	int money;
	char name[50];
	int date_of_concert;
	char city_for_concert[100];
	file >> money >> name >> date_of_concert >> city_for_concert;
	setMoney(money);
	setName(name);
	setDateOfConcert(date_of_concert);
	setCityForConcert(city_for_concert);
}
void Singer::writeDataFieldsToFile(ofstream&file) {
	file << getMoney() << getName() << getDateOfConcert() << getCityForConcert();
}