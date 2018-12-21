#include <iostream>
using namespace std;
class Concert;
class Singer{
public:
	Concert * concert_;
	int money_;
	char name_[50];
	int date_of_concert_;
	char city_for_concert_[100];
	void sing();
	void setMoney(int money);
	int getMoney();
	void setName(char* name);
	char* getName();
	void setDateOfConcert(int date);
	void setCityForConcert(char*city);
	int getDateOfConcert();
	char*getCityForConcert();

	void readDataFieldsFromFile(ifstream&file);
	void writeDataFieldsToFile(ofstream&file);
	Singer();
	~Singer();
};