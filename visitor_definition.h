#include <vector>
#include <fstream>
using namespace std;
class Concert;
class Visitor{
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