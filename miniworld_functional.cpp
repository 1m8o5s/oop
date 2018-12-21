#pragma once
#include "miniworld_definition.h"
#pragma once
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
void MiniWorld::tick_present_time(int target) {
	setSecond(getSecond() + (target == 0));
	setMinute(getMinute() + (target <= 1)*(present_second_ == 60));
	setSecond(getSecond() % 60);
	setHour(getHour() + (target <= 2)*(present_minute_ == 60));
	setMinute(getMinute() % 60);
	setDay(getDay() + (target <= 3)*(present_hour_ == 24));
	setHour(getHour() % 24);
	setMounth(getMounth() + (target <= 4)*(present_day_ == 30));
	setDay(getDay() % 30);
	setYear(getYear() + (target <= 5)*(present_mounth_ == 12));
	setMounth(getMounth() % 12);
}
void MiniWorld::tick_present_time(int target, int times) {
	setSecond(getSecond() + (target == 0)*times);
	setMinute(getMinute() + (target <= 1)*(present_second_ / 60)*times);
	setSecond(getSecond() % 60);
	setHour(getHour() + (target <= 2)*(present_minute_ / 60)*times);
	setMinute(getMinute() % 60);
	setDay(getDay() + (target <= 3)*(present_hour_ / 24)*times);
	setHour(getHour() % 24);
	setMounth(getMounth() + (target <= 4)*(present_day_ / 30)*times);
	setDay(getDay() % 30);
	setYear(getYear() + (target <= 5)*(present_mounth_ / 12)*times);
	setMounth(getMounth() % 12);
}
void MiniWorld::setSecond(int second) {
	present_second_ = second;
}
void MiniWorld::setMinute(int minute) {
	present_minute_ = minute;
}
void MiniWorld::setHour(int hour) {
	present_hour_ = hour;
}
void MiniWorld::setDay(int day) {
	present_day_ = day;
}
void MiniWorld::setMounth(int mounth) {
	present_mounth_ = mounth;
}
void MiniWorld::setYear(int year) {
	present_year_ = year;
}
int MiniWorld::getSecond() {
	return present_second_;
}
int MiniWorld::getMinute() {
	return present_minute_;
}
int MiniWorld::getHour() {
	return present_hour_;
}
int MiniWorld::getDay() {
	return present_day_;
}
int MiniWorld::getMounth() {
	return present_mounth_;
}
int MiniWorld::getYear() {
	return present_year_;
}
//MiniWorld MiniWorld::operator++(int n) {
//	MiniWorld mv(*this);
//	this->tick_present_time(0);
//	return mv;
//}
//MiniWorld& MiniWorld::operator++() {
//	this->tick_present_time(0);
//	return *this;
//}
//MiniWorld MiniWorld::operator--(int) {
//	/*MiniWorld mv(*this);
//	this->tick_present_time(0);
//	return mv;*/
//}
//MiniWorld& MiniWorld::operator--() {
//	/*this->tick_present_time(0);
//	return *this;*/
//}
//MiniWorld MiniWorld::operator+(int n) {
//	MiniWorld mv;
//	mv.tick_present_time(0, n);
//	return (mv);
//}
//MiniWorld& MiniWorld::operator-(int n) {
//	/*MiniWorld mv;
//	mv.tick_present_time(0, n);
//	return (mv);*/
//}
//MiniWorld MiniWorld::operator*(int n) {
//	/*MiniWorld mv;
//	for (int i = 0; i < n; i++)
//		mv.tick_present_time(0, n);
//	return (mv);*/
//}
//MiniWorld& MiniWorld::operator = (MiniWorld& n) {
//	/**this = n;
//	return *this;*/
//}
//MiniWorld& MiniWorld::operator += (int n) {
//	*this = *(this + n);
//	return *this;
//}
//MiniWorld& MiniWorld::operator -= (int n) {
//	/**this = *this - n;
//	return *this;*/
//}
//MiniWorld& MiniWorld::operator *= (int n) {
//	/*for (int i = 0; i < n; i++)
//		this->tick_present_time(0, n);
//	return *this;*/
//}
//int MiniWorld::operator[] (int n) {
//	/*switch (n) {
//	case 0:
//		return this->getSecond();
//	case 1:
//		return this->getMinute();
//	case 2:
//		return this->getHour();
//	case 3:
//		return this->getDay();
//	case 4:
//		return this->getMounth();
//	case 5:
//		return this->getYear();
//	}*/
//}
template <typename T>
void ServiceRead(T& what, char* file, bool binary) {
	if (binary) {
		ifstream fin;
		try {
			fin.open(file, ios::binary);
			if (fin.eof())
				throw 1;
			fin.read(reinterpret_cast<char*>(&what), sizeof(T));

		}
		catch (int exc) {
			fin.close();
		}
		catch (...) {
			fin.close();
		}
	}
	else {
		ifstream fin;
		try {
			fin.open(file);
			if (fin.eof())
				throw 1;
			what.readDataFieldsFromFile(fin);
		}
		catch (int exc) {
			fin.close();
		}
		catch (...) {
			fin.close();
		}
	}
}
template <typename T>
void ServiceWrite(T *what, char* file, bool binary) {
	if (binary) {
		ofstream fin;
		try {
			fin.open(file, ios::binary);
			fin.write(reinterpret_cast<char*>(&what), sizeof(T));
		}
		catch (...) {
			fin.close();
		}
	}
	else {
		ofstream fin;
		try {
			fin.open(file);
			what->writeDataFieldsToFile(fin);
		}
		catch (...) {
			fin.close();
		}
	}
}
void MiniWorld::addCassa(char* file, char*mode) {
	cassa.push_back(new Cassa());
	if (strcmp(mode, "binary")) {
		ServiceRead<Cassa>(*cassa[cassa.size() - 1], file, false);
	}
	else {
		ServiceRead<Cassa>(*cassa[cassa.size() - 1], file, true);
	}
}
void MiniWorld::addVisitor(char* file, char*mode) {
	visitors.push_back(new Visitor());
	if (strcmp(mode, "binary")) {
		ServiceRead<Visitor>(*visitors.back(), file, false);
	}
	else {
		ServiceRead<Visitor>(*visitors.back(), file, true);
	}
}
void MiniWorld::addConcert(char* file, char*mode) {
	concerts.push_back(new Concert());
	if (strcmp(mode, "binary")) {
		ServiceRead<Concert>(*concerts[concerts.size() - 1], file, false);
	}
	else {
		ServiceRead<Concert>(*concerts[concerts.size() - 1], file, true);
	}
}
void MiniWorld::addSingerManager(char* file, char*mode) {
	singer_managers.push_back(new SingerManager());
	if (strcmp(mode, "binary")) {
		ServiceRead<SingerManager>(*(singer_managers[singer_managers.size() - 1]), file, false);
	}
	else {
		ServiceRead<SingerManager>(*(singer_managers[singer_managers.size() - 1]), file, true);
	}
}
void MiniWorld::addClubManager(char* file, char*mode) {
	club_managers.push_back(new ClubManager());
	if (strcmp(mode, "binary")) {
		ServiceRead<ClubManager>(*club_managers[club_managers.size() -1], file, false);
	}
	else {
		ServiceRead<ClubManager>(*club_managers[club_managers.size() - 1], file, true);
	}
}
void MiniWorld::addSecurityManager(char* file, char*mode) {
	security_managers.push_back(new SecurityManager());
	if (strcmp(mode, "binary")) {
		ServiceRead<SecurityManager>(*security_managers[security_managers.size() - 1], file, false);
	}
	else {
		ServiceRead<SecurityManager>(*security_managers[security_managers.size() - 1], file, true);
	}
}
void MiniWorld::addSinger(char* file, char*mode) {
	if (strcmp(mode, "binary")) {
		ServiceRead<Singer>(*singers[singers.size() -1], file, false);
	}
	else {
		ServiceRead<Singer>(*singers[singers.size() - 1], file, true);
	}
}
void MiniWorld::removeCassa(char*title) {
	int i = 0;
	for (; i < cassa.size(); i++) {
		if (!strcmp(cassa[i]->getName(), title))
			break;
	}
	auto it = cassa.begin();
	it += i;
	cassa.erase(it);
}
void MiniWorld::removeVisitor(char*name) {
	for (auto it = visitors.begin(); *it != visitors.back(); ++it) {
		if (!strcmp((*it)->getName(), name)) {
			visitors.erase(it);
			break;
		}
	}
}
void MiniWorld::removeConcert(char*title) {
	for (auto it = concerts.begin(); it != concerts.end(); ++it) {
		if (!strcmp((*it)->getName(), title)) {
			concerts.erase(it);
			break;
		}
	}
}
void MiniWorld::removeSingerManager(char*name) {
	
	for (auto it = singer_managers.begin(); it != singer_managers.end(); ++it) {
		if (!strcmp((*it)->getName(), name)) {
			singer_managers.erase(it);
			break;
		}
	}
}
void MiniWorld::removeClubManager(char*name) {
	for (auto it = club_managers.begin(); it != club_managers.end(); ++it) {
		if (!strcmp((*it)->getName(), name)) {
			club_managers.erase(it);
			break;
		}
	}
}
void MiniWorld::removeSecurityManager(char*name) {
	for (auto it = security_managers.begin(); it != security_managers.end(); ++it) {
		if (!strcmp((*it)->getName(), name)) {
			security_managers.erase(it);
			break;
		}
	}
}
void MiniWorld::removeSinger(char*name) {
	for (auto it = singers.begin(); it != singers.end(); ++it) {
		if (!strcmp((*it)->getName(), name)) {
			singers.erase(it);
			break;
		}
	}
}
MiniWorld::MiniWorld():cassa(),visitors(), concerts(), singer_managers(), club_managers(), security_managers(), singers(), present_second_(), present_minute_(), present_hour_(), present_day_(), present_mounth_(), present_year_() {

}
MiniWorld::MiniWorld(vector<Cassa*>& cassa, vector<Visitor*>& visitors, vector<Concert*>&concerts, vector<SingerManager*>&singer_managers, vector<ClubManager*>&club_managers, vector<SecurityManager*>&security_managers, vector<Singer*> &singers, int second, int minute, int hour, int day, int mounth, int year)
					:cassa(cassa), visitors(visitors), concerts(concerts), singer_managers(singer_managers), club_managers(club_managers), security_managers(security_managers), singers(singers), present_second_(second), present_minute_(minute), present_hour_(hour), present_day_(day), present_mounth_(mounth), present_year_(year)
{

}

void MiniWorld::executeCommands(stringstream& text) {
	/*stringstream set_of_lexems = analyseCommands(text);
	char tmp_token[50];
	set_of_lexems >> tmp_token;
	if (!strcmp(tmp_token, "tick")) {
		set_of_lexems >> tmp_token;
		if (!strcmp(tmp_token, "second")) {
			this->tick_present_time(0);
		}
		else if (!strcmp(tmp_token, "minute")) {
			this->tick_present_time(1);
		}
		else if (!strcmp(tmp_token, "hour")) {
			this->tick_present_time(2);
		}
		else if (!strcmp(tmp_token, "day")) {
			this->tick_present_time(3);
		}
		else if (!strcmp(tmp_token, "mounth")) {
			this->tick_present_time(4);
		}
		else if (!strcmp(tmp_token, "year")) {
			this->tick_present_time(5);
		}
	}
	else if (!strcmp(tmp_token, "remove")) {
		char name[50];
		char type[50];
		set_of_lexems >> name;
		set_of_lexems >> type;
		if (!strcmp(type, "Cassa")) {
			removeCassa(name);
		}
		else if (!strcmp(type, "Visitor")) {
			removeVisitor(name);
		}
		else if (!strcmp(type, "Concert")) {
			removeConcert(name);
		}
		else if (!strcmp(type, "SingerManager")) {
			removeSingerManager(name);
		}
		else if (!strcmp(type, "ClubManager")) {
			removeClubManager(name);
		}
		else if (!strcmp(type, "SecurityManager")) {
			removeSecurityManager(name);
		}
		else if (!strcmp(type, "Singer")) {
			removeSinger(name);
		}
	}
	else if (!strcmp(tmp_token, "add")) {
		char type[50];
		char mode[50];
		char file[50];
		set_of_lexems >> type >> mode >> file;
		if (!strcmp(type, "Cassa")) {
			addCassa(file, mode);
		}
		else if (!strcmp(type, "Visitor")) {
			addVisitor(file, mode);
		}
		else if (!strcmp(type, "Concert")) {
			addConcert(file, mode);
		}
		else if (!strcmp(type, "SingerManager")) {
			addSingerManager(file, mode);
		}
		else if (!strcmp(type, "ClubManager")) {
			addClubManager(file, mode);
		}
		else if (!strcmp(type, "SecurityManager")) {
			addSecurityManager(file, mode);
		}
		else if (!strcmp(type, "Singer")) {
			addSinger(file, mode);
		}
	}*/
}
//stringstream MiniWorld::analyseCommands(stringstream& text) {
	/*char tmp_token[50];
	stringstream set_of_lexems;
	text >> tmp_token;
	set_of_lexems << tmp_token << " ";
	
	if (!strcmp(tmp_token, "tick")) {
		text >> tmp_token;
		set_of_lexems << tmp_token << " ";
	}
	else if (!strcmp(tmp_token, "remove")){
		text >> tmp_token;
		set_of_lexems << tmp_token << " ";
		text >> tmp_token;
		text >> tmp_token;
		set_of_lexems << tmp_token << " ";
	}
	else {
		text >> tmp_token;
		set_of_lexems << tmp_token << " ";
		text >> tmp_token;
		text >> tmp_token;
		set_of_lexems << tmp_token << " ";
		text >> tmp_token;
		set_of_lexems << tmp_token << " ";
	}
	return set_of_lexems;*/
//}
void MiniWorld::loop() {
	//Зчитування з консольки команд від користувача
	/*char buf[200];
	stringstream text;
	while (true) {
		cout << endl << "Enter command:" << endl;
		cin.getline(buf, 200);
		if (!strcmp(buf, "exit"))
			return;
		text.write(buf, 200);
		executeCommands(text);*/
		//cout << endl << concerts[concerts.size() - 1]->getName();
	//}
	/*  | add type from text|binary "file"
		| remove name as type
		| show name as type /// в наступній версії
		| tick second|minute|hour|day|mounth|year
		| exit


	*/
	//Виконання команд від користувача

}