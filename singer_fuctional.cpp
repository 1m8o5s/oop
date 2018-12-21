#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "miniworld_definition.h"
#include <iostream>
#include <fstream>
using namespace std;

Singer Singer::operator++(int) {
	Singer prev = *this;
	this->setMoney(this->getMoney() + 1);
	return prev;
}
Singer& Singer::operator++() {
	this->setMoney(this->getMoney() + 1);
	return *this;
}
Singer Singer::operator--(int) {
	Singer prev = *this;
	this->setMoney(this->getMoney() - 1);
	if (this->getMoney() < 0) this->setMoney(0);
	return prev;
}
Singer& Singer::operator--() {
	this->setMoney(this->getMoney() - 1);
	if (this->getMoney() < 0) this->setMoney(0);
	return *this;
}
Singer Singer::operator+(int cache) {
	Singer singer(*this);
	singer.setMoney(this->getMoney() + cache);
	return singer;
}
Singer Singer::operator-(int cache) {
	Singer singer(*this);
	singer.setMoney(this->getMoney() - cache);
	if (singer.getMoney() < 0) singer.setMoney(0);
	return singer;
}
Singer Singer::operator*(int cache) {
	Singer singer(*this);
	singer.setMoney(this->getMoney() * cache);
	return singer;
}
int Singer::getMoney() {
	return money_;
}
void Singer::setMoney(int money) {
	money_ = money;
}
void Singer::setName(char*name) {
	strcpy(name_, name);
}
char * Singer::getName() {
	return name_;
}

Singer& Singer::operator = (Singer& visit) {
	this->setMoney(visit.getMoney());
	this->setCityForConcert(visit.getCityForConcert());
	this->setName(visit.getName());
	return *this;
}

Singer& Singer::operator += (int cache) {
	this->setMoney(this->getMoney() + cache);
	return *this;
}
Singer& Singer::operator -= (int cache) {
	this->setMoney(this->getMoney() - cache);
	if (this->getMoney() < 0) this->setMoney(0);
	return *this;
}
Singer& Singer::operator *= (int cache) {
	this->setMoney(this->getMoney() * cache);
	return *this;
}
Singer Singer::operator[] (int n) {
	Singer singer;
	switch (n) {
	case 0:
		singer.setMoney(this->getMoney());
		return singer;
	case 1:
		singer.setCityForConcert(this->getCityForConcert());
		return singer;
	case 2:
		singer.setName(this->getName());
		return singer;
	}
}

char* Singer::getCityForConcert() {
	return this->city_for_concert_;
}
void Singer::setCityForConcert(char* ch) {
	strcpy(this->city_for_concert_, ch);
}

void Singer::readDataFieldsFromFile(ifstream&file) {
	int money;
	char name[50];
	char city_for_concert[100];
	file >> money >> name >> city_for_concert;
	setMoney(money);
	setName(name);
	setCityForConcert(city_for_concert);
}
void Singer::writeDataFieldsToFile(ofstream&file) {
	file << getMoney() << getName() << getCityForConcert();
}
Singer::Singer() : money_(0), name_("Ivan"){

}
Singer::Singer(int money, char*name) : money_(money) {
	strcpy(name_, name);
}
Singer::~Singer() {

}