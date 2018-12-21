#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "visitor_definition.h"
#pragma once
#include "concert_definition.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;
Visitor Visitor::operator++(int) {
	Visitor prev = *this;
	this->setCache(this->getCache() + 1);
	return prev;
}
Visitor& Visitor::operator++() {
	this->setCache(this->getCache() + 1);
	return *this;
}
Visitor Visitor::operator--(int) {
	Visitor prev = *this;
	this->setCache(this->getCache() - 1);
	if (this->getCache() < 0) this->setCache(0);
	return prev;
}
Visitor& Visitor::operator--() {
	this->setCache(this->getCache() - 1);
	if (this->getCache() < 0) this->setCache(0);
	return *this;
}
Visitor Visitor::operator+(int cache) {
	Visitor visit(*this);
	visit.setCache(this->getCache() + cache);
	return visit;
}
Visitor Visitor::operator-(int cache) {
	Visitor visit(*this);
	visit.setCache(this->getCache() - cache);
	if (visit.getCache() < 0) visit.setCache(0);
	return visit;
}
Visitor Visitor::operator*(int cache) {
	Visitor visit(*this);
	visit.setCache(this->getCache() * cache);
	return visit;
}

Visitor& Visitor::operator = (Visitor& visit) {
	this->setCache(visit.getCache());
	this->setDiscount(visit.getDiscount());
	this->setMember(visit.getMember());
	this->setName(visit.getName());
	this->setNickname(visit.getName());
	this->setNumberOfPlace(visit.getNumberOfPlace());
	this->setOld(visit.getOld());
	this->setTicketOwnership(visit.getTicketOwnership());
	return *this;
}

Visitor& Visitor::operator += (int cache) {
	this->setCache(this->getCache() + cache);
	return *this;
}
Visitor& Visitor::operator -= (int cache) {
	this->setCache(this->getCache() - cache);
	if (this->getCache() < 0) this->setCache(0);
	return *this;
}
Visitor& Visitor::operator *= (int cache) {
	this->setCache(this->getCache() * cache);
	return *this;
}
Visitor& Visitor::operator[] (int n) {
	Visitor visit;
	switch (n) {
	case 0:
		visit.setCache(this->getCache());
		break;
	case 1:
		visit.setDiscount(this->getDiscount());
		break;
	case 2:
		visit.setMember(this->getMember());
		break;
	case 3:
		visit.setName(this->getName());
		break;
	case 4:
		visit.setNickname(this->getNickname());
		break;
	case 5:
		visit.setNumberOfPlace(this->getNumberOfPlace());
		break;
	case 6:
		visit.setOld(this->getOld());
		break;
	case 7:
		visit.setTicketOwnership(this->getTicketOwnership());
		break;
	}
	return visit;
}
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
bool Visitor::getTicketOwnership(){
	return this->have_ticket_;
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
void Visitor::setTicketOwnership(bool have_ticket){
	this->have_ticket_ = have_ticket;
}
void Visitor::setTicketOwnership(bool have_ticket, int cache){
	this->have_ticket_ = have_ticket;
	this->cache_ = cache;
}
void Visitor::setOld(int years_old){
	this->years_old_ = years_old;
}
void Visitor::readDataFieldsFromFile(ifstream& file){
	int cache;
	int years_old;
	char name[50];
	int discount;
	bool have_ticket;
	char nickname[50];
	bool vip_member;
	int number_of_place;
	file >> cache >> years_old >> name >> discount >> have_ticket >> nickname >> vip_member >> number_of_place;
	this->setCache(cache);
	this->setDiscount(discount);
	this->setMember(vip_member);
	this->setName(name);
	this->setNickname(nickname);
	this->setNumberOfPlace(number_of_place);
	this->setTicketOwnership(have_ticket);
	this->setOld(years_old);
}
void Visitor::writeDataFieldsToFile(ofstream& file){
	file << this->getCache() << " " << this->getOld() << " " << this->getName() << " " << this->getDiscount() << " " << this->getTicketOwnership() << " " << this->getNickname() << " " << this->getMember() << " " << this->getNumberOfPlace();
}
void Visitor::goToConcert(Concert* concert){
	this->concert_ = concert;
	this->concert_->addVisitor(this);
	this->concert_->setNumberOfVisitors(this->concert_->getNumberOfVisitors() + 1);
}
Concert* Visitor::whatConcertIsVisit(){
	return this->concert_;
}
void Visitor::leaveConcert() {
	this->concert_ = nullptr;
}
Visitor::Visitor() :concert_(nullptr), cache_(0), years_old_(12), discount_(0), have_ticket_(false), vip_member_(false){
	cout << endl << "constructor without arguments for visitor" << endl;
}
Visitor::Visitor(int cache, int years_old, char*name, int discount, bool have_ticket, char*nickname, bool vip_member, int number_of_place)
	: cache_(cache), years_old_(years_old), discount_(discount), have_ticket_(have_ticket), vip_member_(vip_member), number_of_place_(number_of_place)
{
	strcpy(this->name_, name);
	strcpy(this->nickname_, nickname);
	cout << endl << "constructor with arguments for visitor" << endl;
}
Visitor::Visitor(Visitor&vs){
	this->setCache(vs.getCache());
	this->setDiscount(vs.getDiscount());
	this->setMember(vs.getMember());
	this->setName(vs.getName());
	this->setNickname(vs.getNickname());
	this->setNumberOfPlace(vs.getNumberOfPlace());
	this->setOld(vs.getOld());
	this->setTicketOwnership(vs.getTicketOwnership());
	this->goToConcert(vs.concert_);
	cout << endl << "copy constructor for visitor" << endl;
}
Visitor::~Visitor(){
	cout << endl << "destructor for visitor" << endl;
}