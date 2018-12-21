#include <vector>
#include <fstream>
using namespace std;
class Visitor;
class Singer;
class Concert{
private:
	char title_[50];
	int date_of_concert_;
	int ticket_price_;
	int age_limit_;
	char city_for_concert_[50];
	std::vector<Visitor*> visitors_; 
	Singer* singer_;
public:
	int earned_money_;
	int number_of_visitors_;
	int vip_member_number_;
	void setTitle(char*artist);
	void setDateOfConcert(int date);
	void setTicketPrice(int price);
	void setAgeLimit(int age_limit);
	void setCityForConcert(char*city);
	void setEarnedMoney(int money);
	void setNumberOfVisitors(int visitors);
	void setVipMemberNumber(int vips_number);
	void setSinger(Singer*singer);
	char*getTitle();
	char*getName();
	int getDateOfConcert();
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
	explicit Concert(char*artist_what_shown, int date_of_concert, int ticket_price, int age_limit, char*city_for_concert, int earned_money, int number_of_visitors, int vip_member_number);
	Concert(Concert&ct);
	~Concert();
};