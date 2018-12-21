#pragma once
#include "all_managers_definition.h"
#pragma once
#include "visitor_definition.h"
void SecurityManager<int>::expelVisitor(Visitor*visitor){
	visitor->leaveConcert();
}
int SecurityManager<int>::getMoney(){
	return this->money_;
}
void SecurityManager<int>::setMoney(int money){
	this->money_ = money;
}
void SecurityManager<int>::readDataFieldsFromFile(ifstream&fp){
	int money;
	fp >> money;
	this->setMoney(money);
}
void SecurityManager<int>::writeDataFieldsToFile(ofstream&fp){
	fp << this->getMoney();
}
template<typename T>
SecurityManager<T>::SecurityManager<T>(){}
template<typename T>
SecurityManager<T>::SecurityManager<T>(int strength, int time_in_work, char* name):strength_(strength), time_in_work_(time_in_work), Manager(0, name){
	cout << endl << "Security Manager Constructor" << endl;
}
template<typename T>
SecurityManager<T>::~SecurityManager<T>(){
	cout << endl << "Security Manager Destructor" << endl;
}