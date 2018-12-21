#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "miniworld_definition.h"
#include <iostream>
#include <fstream>
using namespace std;

void Concert::setTitle(char*artist){
	strcpy(this->title_, artist);
}
void Concert::setDateOfConcert(int minute, int hour, int day, int mounth, int year){
	this->setMinuteOfConcert(minute);
	this->setHourOfConcert(hour);
	this->setDayOfConcert(day);
	this->setMounthOfConcert(mounth);
	this->setYearOfConcert(year);
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
void Concert::setSinger(Singer* singer) {
	this->singer_ = singer;
}
void Concert::setHourOfConcert(int hour) {
	concert_start_hour = hour;
}
void Concert::setMinuteOfConcert(int minute) {
	concert_start_minute = minute;
}
void Concert::setDayOfConcert(int day) {
	concert_start_day = day;
}
void Concert::setMounthOfConcert(int mounth) {
	concert_start_mounth = mounth;
}
void Concert::setYearOfConcert(int year) {
	concert_start_year = year;
}
char* Concert::getTitle(){
	return this->title_;
}
char* Concert::getName() {
	return this->title_;
}
int Concert::getMinuteOfConcert() {
	return this->concert_start_minute;
}
int Concert::getHourOfConcert() {
	return this->concert_start_hour;
}
int Concert::getDayOfConcert() {
	return this->concert_start_day;
}
int Concert::getMounthOfConcert() {
	return this->concert_start_mounth;
}
int Concert::getYearOfConcert() {
	return this->concert_start_year;
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
void Concert::readDataFieldsFromFile(ifstream& file){
	char artist_what_shown[50];
	int ticket_price;
	int age_limit;
	char city_for_concert[50];
	int earned_money;
	int number_of_visitors;
	int vip_member_number;
	int  minute, hour, day, mounth, year;
	file >> artist_what_shown >>  minute >> hour >> day >> mounth >> year >> ticket_price >> age_limit >> city_for_concert >> earned_money >> number_of_visitors >> vip_member_number;
	this->setDayOfConcert(day);
	this->setHourOfConcert(hour);
	this->setMinuteOfConcert(minute);
	this->setMounthOfConcert(mounth);
	this->setYearOfConcert(year);
	this->setTitle(artist_what_shown);
	this->setTicketPrice(ticket_price);
	this->setAgeLimit(age_limit);
	this->setCityForConcert(city_for_concert);
	this->setEarnedMoney(earned_money);
	this->setNumberOfVisitors(number_of_visitors);
	this->setVipMemberNumber(vip_member_number);
}
void Concert::writeDataFieldsToFile(ofstream& file){
	file << this->getTitle() << " " << this->getMinuteOfConcert() << " " << this->getHourOfConcert() << " " << this->getDayOfConcert() << " " << this->getMounthOfConcert() << " " << this->getYearOfConcert()  << " " << this->getTicketPrice() << " " << this->getAgeLimit() << " " << this->getCityForConcert() << " " << this->getEarnedMoney() << " " << this->getNumberOfVisitors() << " " << this->getVipMemberNumber();
}
Singer* Concert::getSinger() {
	return this->singer_;
}
Visitor* Concert::getVisitor(int visitor){
	return visitors_[0];
}
void Concert::addVisitor(Visitor *visitor){
	this->visitors_.push_back(visitor);
}
Concert Concert::operator++(int) {
	Concert cncrt;
	this->setTicketPrice(this->getTicketPrice() + 1);
	return cncrt;
}
Concert& Concert::operator++() {
	this->setTicketPrice(this->getTicketPrice() + 1);
	return *this;
}
Concert Concert::operator--(int) {
	Concert cncrt;
	this->setTicketPrice(this->getTicketPrice() - 1);
	return cncrt;
}
Concert& Concert::operator--() {
	this->setTicketPrice(this->getTicketPrice() - 1);
	return *this;
}
Concert Concert::operator+(int n) {
	Concert cnc;
	cnc.setTicketPrice(this->getTicketPrice() + n);
	return cnc;
}
Concert Concert::operator-(int n) {
	Concert cnc;
	cnc.setTicketPrice(this->getTicketPrice() - n);
	return cnc;
}
Concert Concert::operator*(int n){
	Concert cnc;
	cnc.setTicketPrice(this->getTicketPrice() * n);
	return cnc;
}
/*
Concert& Concert::operator = (int cnc) {
	setAgeLimit(cnc);
	return *this;
}
*/
Concert& Concert::operator += (int n) {
	this->setTicketPrice(this->getTicketPrice() + n);
	return *this;
}
Concert& Concert::operator -= (int n) {
	this->setTicketPrice(this->getTicketPrice() - n);
	return *this;
}
Concert& Concert::operator *= (int n) {
	this->setTicketPrice(this->getTicketPrice() * n);
	return *this;
}
int Concert::operator[] (int n) {
	return this->getTicketPrice()*n;
}
Concert::Concert() :concert_start_minute(0), concert_start_hour(0), concert_start_day(0), concert_start_mounth(0), concert_start_year(0), ticket_price_(0), age_limit_(18), earned_money_(0), number_of_visitors_(0), vip_member_number_(0){
	cout << endl << "constructor without arguments for concert" << endl;
}
Concert::Concert(char*artist_what_shown, int minute, int hour, int day, int mounth, int year, int ticket_price, int age_limit, char*city_for_concert, int earned_money, int number_of_visitors, int vip_member_number)
	: concert_start_minute(minute), concert_start_hour(hour), concert_start_day(hour), concert_start_mounth(mounth), concert_start_year(year), ticket_price_(ticket_price), age_limit_(age_limit), earned_money_(earned_money), number_of_visitors_(number_of_visitors), vip_member_number_(vip_member_number)
{
	strcpy(this->title_, artist_what_shown);
	strcpy(this->city_for_concert_, city_for_concert);
	cout << endl << "constructor with arguments for concert" << endl;
}

Concert::Concert(Concert &ct){
	this->setAgeLimit(ct.getAgeLimit());
	this->setTitle(ct.getTitle());
	this->setCityForConcert(ct.getCityForConcert());
	this->setMinuteOfConcert(ct.getMinuteOfConcert());
	this->setHourOfConcert(ct.getHourOfConcert());
	this->setDayOfConcert(ct.getDayOfConcert());
	this->setMounthOfConcert(ct.getMounthOfConcert());
	this->setYearOfConcert(ct.getYearOfConcert());
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