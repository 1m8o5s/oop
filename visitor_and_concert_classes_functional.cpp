#define _CRT_SECURE_NO_WARNINGS
#include "visitor_and_concert_classes_definition.h";
#include <cstring>
#include <fstream>
#include <ctime>
int Visitor::getCache(){
	return this->cache_;
}
int Visitor::getDiscount(){
	return this->discount_;
}
bool Visitor::getMember(){
	return this->vip_member_;
}
char* Visitor::getName(){
	return this->name_;
}
char* Visitor::getNickname(){
	return this->nickname_;
}
int Visitor::getNumberOfPlace(){
	return this->number_of_place_;
}
int Visitor::getNumberOfTicketsWhatWantToBuy(){
	return this->number_of_tickets_what_want_to_buy_;
}
int Visitor::getOld(){
	return this->years_old_;
}
void Visitor::setCache(int cache){
	this->cache_ = cache;
}
void Visitor::setDiscount(int delta_cache){
	this->discount_ = delta_cache;
}
void Visitor::setDiscount(int delta_cache, int cache){
	this->discount_ = delta_cache;
	this->cache_ = cache;
}
void Visitor::setMember(bool member){
	this->vip_member_ = member;
}
void Visitor::setName(char* name){
	strcpy(this->name_, name);
}
void Visitor::setNickname(char* nickname){
	strcpy(this->nickname_, nickname);
}
void Visitor::setNumberOfPlace(int number_place){
	this->number_of_place_ = number_place;
}
void Visitor::setNumberOfTicketsWhatWantToBuy(int number_of_tickets){
	this->number_of_tickets_what_want_to_buy_ = number_of_tickets;
}
void Visitor::setNumberOfTicketsWhatWantToBuy(int number_of_tickets, int cache){
	this->number_of_tickets_what_want_to_buy_ = number_of_tickets;
	this->cache_ = cache;
}
void Visitor::setOld(int years_old){
	this->years_old_ = years_old;
}
std::vector<int> Visitor::setOfCacheValues(){
	srand(time(0));
	int r = rand() % 10 + 3;
	std::vector<int> arr(r);
	for (int i = 0; i < r; i++){
		arr[i] = this->getCache() / i;
	}
	return arr;
}
void Visitor::readDataFieldsFromFile(char* file){
	std::ifstream fin(file);
	int cache;
	int years_old;
	char name[50];
	int discount;
	int number_of_tickets_what_want_to_buy;
	char nickname[50];
	bool vip_member;
	int number_of_place;
	fin >> cache >> years_old >> name >> discount >> number_of_tickets_what_want_to_buy >> nickname >> vip_member >> number_of_place;
	this->setCache(cache);
	this->setDiscount(discount);
	this->setMember(vip_member);
	this->setName(name);
	this->setNickname(nickname);
	this->setNumberOfPlace(number_of_place);
	this->setNumberOfTicketsWhatWantToBuy(number_of_tickets_what_want_to_buy);
	this->setOld(years_old);
	fin.close();
}
void Visitor::writeDataFieldsToFile(char* file){
	std::ofstream fout(file);
	fout << this->getCache() << " " << this->getOld() << " " << this->getName() << " " << this->getDiscount() << " " << this->getNumberOfTicketsWhatWantToBuy() << " " << this->getNickname() << " " << this->getMember() <<" "<< this->getNumberOfPlace();
	fout.close();
}
void Visitor::goToConcert(Concert* concert){
	this->concert_ = concert;
	this->concert_->addVisitor(this);
	this->concert_->setEarnedMoney(this->concert_->getEarnedMoney() + this->concert_->getTicketPrice());
	this->setCache(this->getCache() - (this->concert_->getTicketPrice() - this->getDiscount()));
	this->concert_->setNumberOfTickets(this->concert_->getNumberOfTickets() - 1);
	this->concert_->setNumberOfVisitors(this->concert_->getNumberOfVisitors() + 1);
	if (this->vip_member_ && this->concert_->getVipMemberNumber()) this->concert_->setVipMemberNumber(this->concert_->getVipMemberNumber() - 1);
}
Concert* Visitor::whatConcertIsVisit(){
	return this->concert_;
}


void Concert::setArtistWhatShown(char*artist){
	strcpy(this->artist_what_shown_, artist);
}
void Concert::setDateOfConcert(int date){
	this->date_of_concert_ = date;
}
void Concert::setTicketPrice(int price){
	this->ticket_price_ = price;
}
void Concert::setNumberOfTickets(int number_of_tickets){
	this->number_of_tickets_ = number_of_tickets;
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
int Concert::getNumberOfTickets(){
	return this->number_of_tickets_;
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
void Concert::readFromFile(char* file){
	std::ifstream fin(file);
	char artist_what_shown[50];
	int date_of_concert;
	int ticket_price;
	int number_of_tickets;
	char city_for_concert[50];
	int earned_money;
	int number_of_visitors;
	int vip_member_number;
	fin >> artist_what_shown >> date_of_concert >> ticket_price >> number_of_tickets >> city_for_concert >> earned_money >> number_of_visitors >> vip_member_number;
	this->setArtistWhatShown(artist_what_shown);
	this->setDateOfConcert(date_of_concert);
	this->setTicketPrice(ticket_price);
	this->setNumberOfTickets(number_of_tickets);
	this->setCityForConcert(city_for_concert);
	this->setEarnedMoney(earned_money);
	this->setNumberOfVisitors(number_of_visitors);
	this->setVipMemberNumber(vip_member_number);
}
void Concert::writeToFile(char* file){
	std::ofstream fout(file);
	fout << this->getArtistWhatShown() << " "<< this->getDateOfConcert() << " " << this->getTicketPrice() << " " << this->getNumberOfTickets() << " " << this->getCityForConcert() << " " << this->getEarnedMoney() << " " << this->getNumberOfVisitors() << " "<< this->getVipMemberNumber();
}
Visitor* Concert::getVisitor(int visitor){
	return this->visitors_[visitor];
}
void Concert::addVisitor(Visitor *visitor){
	this->visitors_.push_back(visitor);
}
std::vector<int> Concert::setOfNumberOfVisitirsValues(){
	srand(time(0));
	int r = rand() % this->getNumberOfVisitors() + 1;
	std::vector<int> arr(r); 
	for (int i = 0; i < r; i++){
		arr[i] = this->getNumberOfVisitors() / i;
	}
	return arr;
}