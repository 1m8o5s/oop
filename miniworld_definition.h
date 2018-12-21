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
class MiniWorld {
private:
	vector<Cassa*> cassa;
	list<Visitor*> visitors;
	deque<Concert*> concerts;
	set<SingerManager*> singer_managers;
	multiset<ClubManager*> club_managers;
	map<int, SecurityManager*> security_managers;
	multimap<int, Singer*> singers;
	int present_second_;
	int present_minute_;
	int present_hour_;
	int present_day_;
	int present_mounth_;
	int present_year_;
public:
	MiniWorld operator++(int);
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
	int operator[] (int);

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
	MiniWorld(vector<Cassa*>& cassa, list<Visitor*>& visitors, deque<Concert*>&concerts, set<SingerManager*>&singer_managers, multiset<ClubManager*>&club_managers, map<int, SecurityManager*>&security_managers, multimap<int, Singer*> &singers, int second, int minute, int hour, int day, int mounth, int year);
	stringstream analyseCommands(stringstream& text);
	void executeCommands(stringstream& text);
	void loop();
	void tick_present_time(int target);
	void tick_present_time(int target, int times);
};