#define _CRT_SECURE_NO_WARNINGS
#include "cassa_definition.h"
#include "all_managers_definition.h"
void Manager::setName(char*name){
	strcpy(this->name_, name);
}
Manager::Manager(int money, char* name):money_(money){
	this->setName(name);
	cout << endl << "Manager Constructor" << endl;
}
Manager::~Manager(){
	cout << endl << "Manager Destructor" << endl;
}
int Manager::getMoney(){
	return this->money_;
}
void Manager::setMoney(int money){
	this->money_ = money;
}
void Manager::readDataFieldsFromFile(ifstream&f){
	int money;
	f >> money;
	this->setMoney(money);
}
void Manager::writeDataFieldsToFile(ofstream&f){
	f << this->getMoney();
}