#include "all_managers_definition.h"
#include "concert_definition.h"
#include "singer_definition.h"
#include <iostream>
using namespace std;
SingerManager::SingerManager(int money, int earned_money, char* name):Manager(money, name), Accountant(0, earned_money, 20, 30, 10){
	cout << endl << "Singer Manager Constructor" << endl;
}
SingerManager::~SingerManager(){
	cout << endl << "Singer Manager Destructor" << endl;
}
int SingerManager::getMoney(){
	return this->money_;
}


void SingerManager::readDataFieldsFromFile(ifstream&f){
	int money;
	int earned_money;
	f >> money >> earned_money;
	this->setEarnedMoney(earned_money);
	this->setMoney(money);
}
void SingerManager::writeDataFieldsToFile(ofstream&f){
	f << this->getEarnedMoney() << this->getMoney();
}
void SingerManager::setConcertDate(Concert* concert, Singer*singer, int date){
	concert->setDateOfConcert(date);
	singer->setDateOfConcert(date);
}
void SingerManager::setCityForConcert(Concert* concert, Singer*singer, char* city){
	concert->setCityForConcert(city);
	singer->setCityForConcert(city);
}
bool SingerManager::agreeTicketPriceWithClubManager(int price){
	return price;
}
bool SingerManager::agreeCashPercentWithClubManager(int cash_percent){
	return cash_percent;
}
void SingerManager::setConcertTicketPrice(Concert* concert, int price){
	concert->setTicketPrice(price);
}
void SingerManager::distributeMoney(Singer * singer){
	this->setMoney(this->getEarnedMoney()*0.7);
	this->setEarnedMoney(this->getEarnedMoney()*0.3);
	singer->setMoney(this->getEarnedMoney());
	this->setEarnedMoney(0);
}