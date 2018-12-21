#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "cassa_definition.h"
#pragma once
#include "all_managers_definition.h"
void Manager::setName(char*name){
	strcpy(this->name_, name);
}
char* Manager::getName() {
	return name_;
}
Manager Manager::operator++(int) {
	Manager mn;
	this->setMoney(this->getMoney() + 1);
	return mn;
}
Manager& Manager::operator++() {
	this->setMoney(this->getMoney() + 1);
	return *this;
}
Manager Manager::operator--(int) {
	Manager mn;
	this->setMoney(this->getMoney() + 1);
	return mn;
}
Manager& Manager::operator--() {
	this->setMoney(this->getMoney() + 1);
	return *this;
}
Manager Manager::operator+(int n) {
	Manager mn;
	mn.setMoney(this->getMoney() + n);
	return mn;
}
Manager Manager::operator-(int n) {
	Manager mn;
	mn.setMoney(this->getMoney() + n);
	return mn;
}
Manager Manager::operator*(int n) {
	Manager mn;
	mn.setMoney(this->getMoney()*n);
	return mn;
}

Manager& Manager::operator = (Manager& mn) {
	*this = mn;
	return *this;
}

Manager& Manager::operator += (int n) {
	this->setMoney(this->getMoney() + n);
	return *this;
}
Manager& Manager::operator -= (int n) {
	this->setMoney(this->getMoney() - n);
	return *this;
}
Manager& Manager::operator *= (int n) {
	this->setMoney(this->getMoney() * n);
	return *this;
}
int Manager::operator[] (int n) {
	return this->getMoney() / n;
}
Manager::Manager():money_(0), name_("Grigoriy") {

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