#include "data_time_definition.h"
void DataTime::setSecond(int sec) {
	this->second = sec;
}
void DataTime::setMinute(int min) {
	this->minute = min;
}
void DataTime::setHour(int hour) {
	this->hour = hour;
}
void DataTime::setDay(int day) {
	this->day = day;
}
void DataTime::setMounth(int mounth) {
	this->mounth = mounth;
}
void DataTime::setYear(int year) {
	this->year = year;
}
int DataTime::getSecond() {
	return second;
}
int DataTime::getMinute() {
	return minute;
}
int DataTime::getHour() {
	return hour;
}
int DataTime::getDay() {
	return day;
}
int DataTime::getMounth() {
	return mounth;
}
int DataTime::getYear() {
	return year;
}
void DataTime::tick(int target) {
	setSecond(getSecond() + (target == 0));
	setMinute(getMinute() + (target <= 1)*(second == 60));
	setSecond(getSecond() % 60);
	setHour(getHour() + (target <= 2)*(minute == 60));
	setMinute(getMinute() % 60);
	setDay(getDay() + (target <= 3)*(hour == 24));
	setHour(getHour() % 24);
	setMounth(getMounth() + (target <= 4)*(day == 30));
	setDay(getDay() % 30);
	setYear(getYear() + (target <= 5)*(mounth == 12));
	setMounth(getMounth() % 12);
}
DataTime::DataTime():second(0), minute(0),hour(0),day(0), mounth(0), year(0) {

}
DataTime::DataTime(int sec, int min, int hour, int day, int mounth, int year)
					:second(sec), minute(min), hour(hour), day(day), mounth(mounth), year(year)
{

}