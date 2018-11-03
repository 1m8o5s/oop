#define _CRT_SECURE_NO_WARNINGS
#include "all_managers_definition.h"
#include "cassa_definition.h"
#include "concert_definition.h"
#include "visitor_definition.h"
#include <iostream>
using namespace std;
void Cassa::setTicketPrice(int tickets_price){
	this->ticket_price_ = tickets_price;
}
void Cassa::setNumberOfTickets(int number_of_tickets){
	this->number_of_tickets_ = number_of_tickets;
}
void Cassa::setEndOfSelling(bool end_of_selling){
	this->end_of_selling_ = end_of_selling;
}
void Cassa::setWorkFrom(int work_from){
	this->work_from_ = work_from;
}
void Cassa::setWorkTo(int work_to){
	this->work_to_ = work_to;
}
void Cassa::setCashPercent(int cash_percent){
	this->cash_percent_ = cash_percent;
}
void Cassa::setCashierName(char*name){
	strcpy(this->cashier_name_, name);
}
int Cassa::getTicketPrice(){
	return this->ticket_price_;
}
int Cassa::getNumberOfTickets(){
	return this->number_of_tickets_;
}
bool Cassa::getEndOfSelling(){
	return this->end_of_selling_;
}
int Cassa::getWorkFrom(){
	return this->work_from_;
}
int Cassa::getWorkTo(){
	return this->work_to_;
}
int Cassa::getCashPercent(){
	return this->cash_percent_;
}
int Cassa::getEarnedMoney(){
	return this->earned_money_;
}
char* Cassa::getCashierName(){
	return this->cashier_name_;
}
void Cassa::readDataFieldsFromFile(ifstream &file){
	int ticket_price;
	int number_of_tickets;
	bool end_of_selling;
	int work_from;
	int work_to;
	int cash_percent;
	char cashier_name[50];
	file >> ticket_price >> number_of_tickets >> end_of_selling >> work_from >> work_to >> cash_percent >> cashier_name;
	this->setTicketPrice(ticket_price);
	this->setNumberOfTickets(number_of_tickets);
	this->setEndOfSelling(end_of_selling);
	this->setWorkFrom(work_from);
	this->setWorkTo(work_to);
	this->setCashPercent(cash_percent);
	this->setCashierName(cashier_name);
}
void Cassa::writeDataFieldsToFile(ofstream &file){
	file << ticket_price_ << number_of_tickets_ << end_of_selling_ << work_from_ << work_to_ << cash_percent_ << cashier_name_;
}
void Cassa::sellTickets(Visitor* visitor, Concert* concert, ClubManager* club_manager, SingerManager* singer_manager, SecurityManager* security_manager, Singer* singer){
	if (this->getNumberOfTickets()){
		if (visitor->getOld() > concert->getAgeLimit()){
			visitor->setCache(visitor->getCache() - (concert->getTicketPrice() - visitor->getDiscount()));
			visitor->setTicketOwnership(true);
			visitor->goToConcert(concert);
			concert->setEarnedMoney(concert->getEarnedMoney() + (concert->getTicketPrice() - visitor->getDiscount())*(100 - this->getCashPercent()) / 100);
			this->setEarnedMoney(this->getEarnedMoney() + (concert->getTicketPrice() - visitor->getDiscount())*this->getCashPercent() / 100);
			visitor->setDiscount(0);
			club_manager->distributeMoney(this, singer_manager, security_manager, singer);
		}
	}
}
Cassa* doSomeCassaMethods(Cassa *cs){
	cs->setTicketPrice(cs->getTicketPrice() + 1);
	return cs;
}
Cassa::Cassa() :ticket_price_(0), number_of_tickets_(0), end_of_selling_(false), work_from_(0), work_to_(0), cash_percent_(0){
	cout << endl << "constructor without arguments for cassa" << endl;
}
Cassa::Cassa(int ticket_price, int number_of_tickets, bool end_of_selling, int work_from, int work_to, int cash_percent, int earned_money, char * cashier_name)
	:ticket_price_(ticket_price), number_of_tickets_(number_of_tickets), end_of_selling_(end_of_selling), work_from_(work_from), work_to_(work_to), cash_percent_(cash_percent)
{
	strcpy(this->cashier_name_, cashier_name);
	cout << endl << "constructor with arguments for cassa" << endl;
}
Cassa::Cassa(Cassa&cs){
	this->setCashierName(cs.getCashierName());
	this->setCashPercent(cs.getCashPercent());
	this->setEarnedMoney(cs.getEarnedMoney());
	this->setEndOfSelling(cs.getEndOfSelling());
	this->setNumberOfTickets(cs.getNumberOfTickets());
	this->setTicketPrice(cs.getTicketPrice());
	this->setWorkFrom(cs.getWorkFrom());
	this->setWorkTo(cs.getWorkTo());
	cout << endl << "copy constructor for cassa" << endl;
}
Cassa::~Cassa(){
	cout << endl << "destructor for cassa" << endl;
}
void doSomethingWithTicketPrice(Cassa *cs){
	cout << endl << "result = " << cs->getTicketPrice() / 2 << endl;
}
void doSomethingWithTicketPrice(Cassa &cs){
	cout << endl << "result = " << cs.getTicketPrice() / 2 << endl;
}
void setPriceOfTicket(Cassa& a, int price){
	a.ticket_price_ = price;
}