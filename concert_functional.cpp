#define _CRT_SECURE_NO_WARNINGS
#include "concert_definition.h"
#include "visitor_definition.h"
#include <iostream>
using namespace std;

void Concert::setArtistWhatShown(char*artist){
	strcpy(this->artist_what_shown_, artist);
}
void Concert::setDateOfConcert(int date){
	this->date_of_concert_ = date;
}
void Concert::setTicketPrice(int price){
	this->ticket_price_ = price;
}
void Concert::setAgeLimit(int age_limit){
	this->age_limit_ = age_limit;
}
void Concert::setCityForConcert(char*city){
	strcpy(this->city_for_concert_, city);
}
void Concert::setEarnedMoney(int money){
	this->earned_money_ = money;
}
void Concert::setNumberOfVisitors(int visitors){
	this->number_of_visitors_ = visitors;
}
void Concert::setVipMemberNumber(int vips_number){
	this->vip_member_number_ = vips_number;
}


char* Concert::getArtistWhatShown(){
	return this->artist_what_shown_;
}
int Concert::getDateOfConcert(){
	return this->date_of_concert_;
}
int Concert::getAgeLimit(){
	return this->age_limit_;
}
int Concert::getTicketPrice(){
	return this->ticket_price_;
}
char* Concert::getCityForConcert(){
	return this->city_for_concert_;
}
int Concert::getEarnedMoney(){
	return this->earned_money_;
}
int Concert::getNumberOfVisitors(){
	return this->number_of_visitors_;
}
int Concert::getVipMemberNumber(){
	return this->vip_member_number_;
}
void Concert::readDataFieldsFromFile(char* file){
	std::ifstream fin(file);
	char artist_what_shown[50];
	int date_of_concert;
	int ticket_price;
	int age_limit;
	char city_for_concert[50];
	int earned_money;
	int number_of_visitors;
	int vip_member_number;
	fin >> artist_what_shown >> date_of_concert >> ticket_price >> age_limit >> city_for_concert >> earned_money >> number_of_visitors >> vip_member_number;
	this->setArtistWhatShown(artist_what_shown);
	this->setDateOfConcert(date_of_concert);
	this->setTicketPrice(ticket_price);
	this->setAgeLimit(age_limit);
	this->setCityForConcert(city_for_concert);
	this->setEarnedMoney(earned_money);
	this->setNumberOfVisitors(number_of_visitors);
	this->setVipMemberNumber(vip_member_number);
}
void Concert::writeDataFieldsToFile(char* file){
	std::ofstream fout(file);
	fout << this->getArtistWhatShown() << " " << this->getDateOfConcert() << " " << this->getTicketPrice() << " " << this->getAgeLimit() << " " << this->getCityForConcert() << " " << this->getEarnedMoney() << " " << this->getNumberOfVisitors() << " " << this->getVipMemberNumber();
}
Visitor* Concert::getVisitor(int visitor){
	return this->visitors_[visitor];
}
void Concert::addVisitor(Visitor *visitor){
	this->visitors_.push_back(visitor);
}
Concert::Concert() :date_of_concert_(0), ticket_price_(0), age_limit_(18), earned_money_(0), number_of_visitors_(0), vip_member_number_(0){
	cout << endl << "constructor without arguments for concert" << endl;
}
Concert::Concert(char*artist_what_shown, int date_of_concert, int ticket_price, int age_limit, char*city_for_concert, int earned_money, int number_of_visitors, int vip_member_number)
	: date_of_concert_(date_of_concert), ticket_price_(ticket_price), age_limit_(age_limit), earned_money_(earned_money), number_of_visitors_(number_of_visitors), vip_member_number_(vip_member_number)
{
	strcpy(this->artist_what_shown_, artist_what_shown);
	strcpy(this->city_for_concert_, city_for_concert);
	cout << endl << "constructor with arguments for concert" << endl;
}
Concert::Concert(Concert &ct){
	this->setAgeLimit(ct.getAgeLimit());
	this->setArtistWhatShown(ct.getArtistWhatShown());
	this->setCityForConcert(ct.getCityForConcert());
	this->setDateOfConcert(ct.getDateOfConcert());
	this->setEarnedMoney(ct.getEarnedMoney());
	this->setNumberOfVisitors(ct.getNumberOfVisitors());
	this->setTicketPrice(ct.getTicketPrice());
	this->setVipMemberNumber(ct.getVipMemberNumber());
	for (int i = 0; i < ct.visitors_.size(); i++){
		this->addVisitor(ct.visitors_[i]);
	}
	cout << endl << "copy constructor for concert" << endl;
}
Concert::~Concert(){
	cout << endl << "destructor for concert" << endl;
}