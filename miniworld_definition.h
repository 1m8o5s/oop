#include <sstream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
using namespace std;
class Cassa;

class Visitor;
class Concert;
class Manager;
class SingerManager;
class ClubManager;
class SecurityManager;
class Singer;
class Concert {
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
	Concert& operator = (int);
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
class Singer {
public:
	Singer operator++(int);
	Singer& operator++();
	Singer operator--(int);
	Singer& operator--();
	Singer operator+(int);
	Singer operator-(int);
	Singer operator*(int);
	Singer& operator = (Singer&);
	Singer& operator += (int);
	Singer& operator -= (int);
	Singer& operator *= (int);
	Singer operator[] (int);
	Concert * concert_;
	int money_;
	char name_[50];
	char city_for_concert_[100];
	void sing();
	void setMoney(int money);
	int getMoney();
	void setName(char* name);
	char* getName();
	void setCityForConcert(char*city);
	char*getCityForConcert();

	void readDataFieldsFromFile(ifstream&file);
	void writeDataFieldsToFile(ofstream&file);
	Singer();
	Singer(int, char*);
	~Singer();
};
class Visitor {
private:
	Concert* concert_;
	int cache_;
	int years_old_;
	char name_[50];
	int discount_;
	bool have_ticket_;
public:
	Visitor operator++(int);
	Visitor& operator++();
	Visitor operator--(int);
	Visitor& operator--();
	Visitor operator+(int);
	Visitor operator-(int);
	Visitor operator*(int);
	Visitor& operator = (Visitor&);
	Visitor& operator += (int);
	Visitor& operator -= (int);
	Visitor& operator *= (int);
	Visitor& operator[] (int);
	char nickname_[50];
	bool vip_member_;
	int number_of_place_;
	void goToConcert(Concert* concert);
	Concert* whatConcertIsVisit();
	void leaveConcert();
	void setCache(int cache);
	void setOld(int years_old);
	void setName(char* name);
	void setDiscount(int discount);
	void setDiscount(int discount, int cache);
	void setTicketOwnership(bool have_ticket);
	void setTicketOwnership(bool have_ticket, int cache);
	void setNickname(char* nickname);
	void setMember(bool member);
	void setNumberOfPlace(int number);

	int getCache();
	int getOld();
	char* getName();
	int getDiscount();
	bool getTicketOwnership();
	char* getNickname();
	bool getMember();
	int getNumberOfPlace();

	void readDataFieldsFromFile(ifstream& file);
	void writeDataFieldsToFile(ofstream& file);

	Visitor();
	Visitor(int cache, int years_old, char*name, int discount, bool have_ticket, char*nickname, bool vip_member, int number_of_place);
	Visitor(Visitor&vs);
	~Visitor();
};
class Cassa {
private:
	int ticket_price_;
	int number_of_tickets_;
	bool end_of_selling_;
	int work_from_;
	int work_to_;
	int sell_price_;
	friend void setPriceOfTicket(Cassa&, int price);
public:
	int cash_percent_;
	static int earned_money_;
	char title_[50];

	Cassa operator++(int);
	Cassa& operator++();
	Cassa operator--(int);
	Cassa& operator--();
	Cassa& operator+(int);
	Cassa& operator-(int);
	Cassa& operator*(int);
	Cassa& operator = (Cassa&);
	Cassa& operator += (int);
	Cassa& operator -= (int);
	Cassa& operator *= (int);
	Cassa& operator[] (int);

	void setTicketPrice(int tickets_price);
	void setNumberOfTickets(int number_of_tickets);
	void setEndOfSelling(bool end_of_selling);
	void setWorkFrom(int work_from);
	void setWorkTo(int work_to);
	void setCashPercent(int cash_percent);
	static void setEarnedMoney(int earned_money) { earned_money_ = earned_money; }
	void setTitle(char*name);
	int getTicketPrice();
	int getNumberOfTickets();
	int getSellPrice();
	void setSellPrice(int price);
	bool getEndOfSelling();
	int getWorkFrom();
	int getWorkTo();
	int getCashPercent();
	int getEarnedMoney();
	char*getTitle();
	char*getName();
	void readDataFieldsFromFile(ifstream &file);
	void writeDataFieldsToFile(ofstream &file);
	void sellTickets(Visitor* visitor, Concert* concert, ClubManager* club_manager, SingerManager* singer_manager, SecurityManager* security_manager, Singer* singer);
	Cassa();
	Cassa(int ticket_price, int number_of_tickets, bool end_of_selling, int sell_price, int work_from, int work_to, int cash_percent, int earned_money, char * title);
	Cassa(Cassa&cs);
	~Cassa();
};
class Manager {
public:
	void setName(char*name);
	char name_[50];
	char* getName();
	Manager operator++(int);
	Manager& operator++();
	Manager operator--(int);
	Manager& operator--();
	Manager operator+(int);
	Manager operator-(int);
	Manager operator*(int);
	Manager& operator = (Manager&);
	Manager& operator += (int);
	Manager& operator -= (int);
	Manager& operator *= (int);
	int operator[] (int);
	virtual ~Manager();
protected:
	int money_;
	int getMoney();
	void setMoney(int money);
	void readDataFieldsFromFile(std::ifstream&fp);
	void writeDataFieldsToFile(std::ofstream&fp);
	Manager();
	Manager(int money, char*name);
};

class Accountant {
protected:
	int experience_;
	int earned_money_;
	int cash_percent_what_want_to_receive_from_agreement_;
	int percent_from_earnings_;
public:
	void setEarnedMoney(int earned_money);
	int getEarnedMoney();
	int ticket_price_what_want_to_receive_from_agreement_;
	void distribute_money();
	Accountant();
	Accountant(int experience, int earned_money, int cash_percent_what_want_to_receive_from_agreement, int percent_from_earnings, int ticket_price_what_want_to_receive_from_agreement);
	~Accountant();
};

class SecurityManager :public Manager {
public:
	using Manager::getMoney;
	using Manager::setMoney;
	using Manager::readDataFieldsFromFile;
	using Manager::writeDataFieldsToFile;
	int getMoney();
	void setMoney(int money);
	void readDataFieldsFromFile(ifstream&fp);
	void writeDataFieldsToFile(ofstream&fp);
	int strength_;
	int time_in_work_;
	void expelVisitor(Visitor*visitor);
	SecurityManager();
	SecurityManager(int strength, int time_in_work, char *name);
	~SecurityManager();
};
class SingerManager :public Manager, public Accountant {
public:
	int getMoney();
	void readDataFieldsFromFile(ifstream&f);
	void writeDataFieldsToFile(ofstream&f);
	void setConcertDate(Concert* concert, Singer*singer, int minute, int hour, int day, int mounth, int year);
	void startWorkingWith(Singer* singer);
	void setCityForConcert(Concert* concert, Singer*singer, char* city);
	bool agreeTicketPriceWithClubManager(int price);
	bool agreeCashPercentWithClubManager(int cash_percent);
	void setConcertTicketPrice(Concert*concert, int price);
	void distributeMoney(Singer * singer);

	SingerManager();
	SingerManager(int money, int earned_money, char* name);
	virtual ~SingerManager();
};
class ClubManager :public Manager, public Accountant {
public:
	void setCassaTicketPrice(Cassa * cassa, int price);
	void setCassaCashPercent(Cassa * cassa, int percent);
	void agreeTicketPriceWithSingerManager(Cassa*cassa, SingerManager*singer_manager, int ticket_price);
	void agreeCashPercentWithSingerManager(Cassa*cassa, SingerManager*singer_manager, int cash_percent);
	void buyCassa(Cassa * cassa);
	void distributeMoney(Cassa* cassa, SingerManager*singer_manager, SecurityManager* security_manager, Singer* singer);
	void readDataFieldsFromFile(ifstream&f);
	void writeDataFieldsToFile(ofstream&f);
	ClubManager();
	virtual ~ClubManager();
};
class MiniWorld {
private:
	vector<Cassa*> cassa;
	vector<Visitor*> visitors;
	vector<Concert*> concerts;
	vector<SingerManager*> singer_managers;
	vector<ClubManager*> club_managers;
	vector<SecurityManager*> security_managers;
	vector<Singer*> singers;
	int present_second_;
	int present_minute_;
	int present_hour_;
	int present_day_;
	int present_mounth_;
	int present_year_;
public:
	/*MiniWorld operator++(int);
	MiniWorld& operator++();
	MiniWorld operator--(int);
	MiniWorld& operator--();
	MiniWorld operator+(int);
	MiniWorld& operator-(int);
	MiniWorld operator*(int);
	MiniWorld& operator = (MiniWorld&);
	MiniWorld& operator += (int);
	MiniWorld& operator -= (int);
	MiniWorld& operator *= (int);
	int operator[] (int);*/

	void setSecond(int second);
	void setMinute(int minute);
	void setHour(int hour);
	void setDay(int day);
	void setMounth(int mounth);
	void setYear(int year);

	int getSecond();
	int getMinute();
	int getHour();
	int getDay();
	int getMounth();
	int getYear();

	void addCassa(char* file, char*mode);
	void addVisitor(char* file, char*mode);
	void addConcert(char* file, char*mode);
	void addSingerManager(char* file, char*mode);
	void addClubManager(char* file, char*mode);
	void addSecurityManager(char* file, char*mode);
	void addSinger(char* file, char*mode);


	void removeCassa(char* title);
	void removeVisitor(char* name);
	void removeConcert(char* title);
	void removeSingerManager(char* name);
	void removeClubManager(char* name);
	void removeSecurityManager(char* name);
	void removeSinger(char* name);

	Cassa* getCassa(char* title);
	Visitor* getVisitor(char* name);
	Concert* getConcert(char* title);
	SingerManager* getSingerManager(char* name);
	ClubManager* getClubManager(char* name);
	SecurityManager* getSecurityManager(char* name);
	Singer* getSinger(char* name);

	MiniWorld();
	MiniWorld(vector<Cassa*>& cassa, vector<Visitor*>& visitors, vector<Concert*>&concerts, vector<SingerManager*>&singer_managers, vector<ClubManager*>&club_managers, vector<SecurityManager*>&security_managers, vector<Singer*> &singers, int second, int minute, int hour, int day, int mounth, int year);
	stringstream analyseCommands(stringstream& text);
	void executeCommands(stringstream& text);
	void loop();
	void tick_present_time(int target);
	void tick_present_time(int target, int times);
};