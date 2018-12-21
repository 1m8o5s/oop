////#include "manager_definition.h"
////#include "club_manager_definition.h"
////#include "singer_manager_definition.h"
//#include <fstream>
//#include <iostream>
//#include <queue>
//using namespace std;
//class Visitor;
//class Manager{
//public:
//	void setName(char*name);
//	char name_[50];
//	char* getName();
//	Manager operator++(int);
//	Manager& operator++();
//	Manager operator--(int);
//	Manager& operator--();
//	Manager operator+(int);
//	Manager operator-(int);
//	Manager operator*(int);
//	Manager& operator = (Manager&);
//	Manager& operator += (int);
//	Manager& operator -= (int);
//	Manager& operator *= (int);
//	int operator[] (int);
//	virtual ~Manager();
//protected:
//	int money_;
//	int getMoney();
//	void setMoney(int money);
//	void readDataFieldsFromFile(std::ifstream&fp);
//	void writeDataFieldsToFile(std::ofstream&fp);
//	Manager();
//	Manager(int money, char*name);
//};
//
//class Accountant{
//	//8
//protected:
//	int experience_;
//	int earned_money_;
//	int cash_percent_what_want_to_receive_from_agreement_;
//	int percent_from_earnings_;
//public:
//	void setEarnedMoney(int earned_money);
//	int getEarnedMoney();
//	int ticket_price_what_want_to_receive_from_agreement_;
//	void distribute_money();
//	Accountant();
//	Accountant(int experience, int earned_money, int cash_percent_what_want_to_receive_from_agreement, int percent_from_earnings, int ticket_price_what_want_to_receive_from_agreement);
//	~Accountant();
//};
//
//class SecurityManager :public Manager{
//public:
//	using Manager::getMoney;
//	using Manager::setMoney;
//	using Manager::readDataFieldsFromFile;
//	using Manager::writeDataFieldsToFile;
//	int getMoney();
//	void setMoney(int money);
//	void readDataFieldsFromFile(ifstream&fp);
//	void writeDataFieldsToFile(ofstream&fp);
//	int strength_;
//	int time_in_work_;
//	void expelVisitor(Visitor*visitor);
//	
//	//5
//	SecurityManager();
//	SecurityManager(int strength, int time_in_work, char *name);
//	~SecurityManager();
//};
//
//class Concert;
//class Singer;
//class SingerManager :public Manager, public Accountant{
//public:
//	//12
//	priority_queue<Singer*> singers_working_with;
//	int getMoney();
//	void readDataFieldsFromFile(ifstream&f);
//	void writeDataFieldsToFile(ofstream&f);
//	void setConcertDate(Concert* concert, Singer*singer, int minute, int hour, int day, int mounth, int year);
//	void startWorkingWith(Singer* singer);
//	void setCityForConcert(Concert* concert, Singer*singer, char* city);
//	bool agreeTicketPriceWithClubManager(int price);
//	bool agreeCashPercentWithClubManager(int cash_percent);
//	void setConcertTicketPrice(Concert*concert, int price);
//	void distributeMoney(Singer * singer);
//
//	SingerManager();
//	SingerManager(int money, int earned_money, char* name);
//	virtual ~SingerManager();
//};
//class Cassa;
//class ClubManager :public Manager, public Accountant{
//private:
//	queue<Cassa*> bought_cashier_;
//public:
//	void setCassaTicketPrice(Cassa * cassa, int price);
//	void setCassaCashPercent(Cassa * cassa, int percent);
//	void agreeTicketPriceWithSingerManager(Cassa*cassa, SingerManager*singer_manager, int ticket_price);
//	void agreeCashPercentWithSingerManager(Cassa*cassa, SingerManager*singer_manager, int cash_percent);
//	void buyCassa(Cassa * cassa);
//	void distributeMoney(Cassa* cassa, SingerManager*singer_manager, SecurityManager* security_manager, Singer* singer);
//	void readDataFieldsFromFile(ifstream&f);
//	void writeDataFieldsToFile(ofstream&f);
//	ClubManager();
//	virtual ~ClubManager();
//};