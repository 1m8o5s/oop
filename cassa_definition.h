#include <vector>
#include <fstream>
using namespace std;
class Visitor;
class Concert;
class SingerManager;
class ClubManager;
class SecurityManager;
class Singer;
class Cassa{
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
	static void setEarnedMoney(int earned_money){ earned_money_ = earned_money; }
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
void setPriceOfTicket(Cassa& a, int price);
void doSomethingWithTicketPrice(Cassa *cs);
void doSomethingWithTicketPrice(Cassa &cs);
Cassa* doSomeCassaMethods(Cassa *cs);