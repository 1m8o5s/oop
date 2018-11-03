#define _CRT_SECURE_NO_WARNINGS
#include "singer_definition.h"
#include <iostream>
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