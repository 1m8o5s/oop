#pragma once
#include <vector>
#include <fstream>
using namespace std;
class Visitor;
class Singer;
class Concert{
private:
	char title_[50];

	int concert_start_year;
	int concert_start_mounth;
	int concert_start_day;
	int concert_start_hour;
	int concert_start_minute;

	int ticket_price_;
	int age_limit_;
	char city_for_concert_[50];
	std::vector<Visitor*> visitors_; 
	Singer* singer_;
public:
	int earned_money_;
	int number_of_visitors_;
	int vip_member_number_;

	Concert operator++(int);
	Concert& operator++();
	Concert operator--(int);
	Concert& operator--();
	Concert operator+(int);
	Concert operator-(int);
	Concert operator*(int);
	//Concert& operator = (int);
	Concert& operator += (int);
	Concert& operator -= (int);
	Concert& operator *= (int);
	int operator[] (int);


	void setTitle(char*artist);
	void setDateOfConcert(int minute, int hour, int day, int mounth, int year);
	void setMinuteOfConcert(int minute);
	void setHourOfConcert(int hour);
	void setDayOfConcert(int day);
	void setMounthOfConcert(int mounth);
	void setYearOfConcert(int year);
	void setTicketPrice(int price);
	void setAgeLimit(int age_limit);
	void setCityForConcert(char*city);
	void setEarnedMoney(int money);
	void setNumberOfVisitors(int visitors);
	void setVipMemberNumber(int vips_number);
	void setSinger(Singer*singer);
	char*getTitle();
	char*getName();
	int getMinuteOfConcert();
	int getHourOfConcert();
	int getDayOfConcert();
	int getMounthOfConcert();
	int getYearOfConcert();
	int getTicketPrice();
	int getAgeLimit();
	char* getCityForConcert();
	int getEarnedMoney();
	int getNumberOfVisitors();
	int getVipMemberNumber();
	Singer* getSinger();
	Visitor* getVisitor(int visitor);
	void addVisitor(Visitor *visitor);
	void readDataFieldsFromFile(ifstream& file);
	void writeDataFieldsToFile(ofstream& file);
	Concert();
	Concert(char*artist_what_shown, int minute, int hour, int day, int mounth, int year, int ticket_price, int age_limit, char*city_for_concert, int earned_money, int number_of_visitors, int vip_member_number);
	Concert(Concert&ct);
	~Concert();
};