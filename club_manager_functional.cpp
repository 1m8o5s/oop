#include "all_managers_definition.h"
#include <iostream>
#include "cassa_definition.h"
#include "singer_manager_definition.h"
#include "security_manager_definition.h"
using namespace std;
ClubManager::ClubManager():Accountant(0, 0, 20, 40, 100), Manager(0, "Ivan"){
	cout << endl << "Club Manager Constructor" << endl;
}
ClubManager::~ClubManager(){
	cout << endl << "Club Manager Destructor" << endl;
}
void ClubManager::setCassaCashPercent(Cassa*cassa, int percent){
	cassa->setCashPercent(percent);
}
void ClubManager::setCassaTicketPrice(Cassa*cassa, int price){
	cassa->setTicketPrice(price);
}
void ClubManager::agreeCashPercentWithSingerManager(Cassa*cassa, SingerManager*singer_manager, int cash_percent){
	if (singer_manager->agreeCashPercentWithClubManager(cash_percent)){
		this->setCassaCashPercent(cassa, cash_percent);
	}
}

void ClubManager::agreeTicketPriceWithSingerManager(Cassa*cassa, SingerManager*singer_manager, int ticket_price){
	if (singer_manager->agreeTicketPriceWithClubManager(ticket_price)){
		this->setCassaTicketPrice(cassa, ticket_price);
	}
}

void ClubManager::distributeMoney(Cassa*cassa, SingerManager*singer_manager, SecurityManager* security_manager, Singer* singer){
	this->setEarnedMoney(cassa->getEarnedMoney());
	cassa->setEarnedMoney(0);
	security_manager->setMoney(security_manager->getMoney() + this->getEarnedMoney()*0.1);
	this->setMoney(this->getMoney() + this->getEarnedMoney()*0.4);
	this->setEarnedMoney(this->getEarnedMoney()*0.5);
	singer_manager->setEarnedMoney(this->getEarnedMoney());
	singer_manager->distributeMoney(singer);
}
void ClubManager::readDataFieldsFromFile(ifstream&f){
	int money;
	int earned_money;
	f >> money >> earned_money;
	this->setEarnedMoney(earned_money);
	this->setMoney(money);
}
void ClubManager::writeDataFieldsToFile(ofstream&f){
	f << this->getEarnedMoney() << this->getMoney();
}