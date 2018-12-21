#pragma once
#include "miniworld_definition.h"
#pragma once
#include "visitor_definition.h"
#include <iostream>
#include <fstream>
void SecurityManager::expelVisitor(Visitor*visitor){
	visitor->leaveConcert();
}
int SecurityManager::getMoney(){
	return this->money_;
}
void SecurityManager::setMoney(int money){
	this->money_ = money;
}
void SecurityManager::readDataFieldsFromFile(ifstream&fp){
	int money;
	fp >> money;
	this->setMoney(money);
}
void SecurityManager::writeDataFieldsToFile(ofstream&fp){
	fp << this->getMoney();
}
SecurityManager::SecurityManager(){}
SecurityManager::SecurityManager(int strength, int time_in_work, char* name):strength_(strength), time_in_work_(time_in_work), Manager(0, name){
	cout << endl << "Security Manager Constructor" << endl;
}
SecurityManager::~SecurityManager(){
	cout << endl << "Security Manager Destructor" << endl;
}