#include <vector>
class Visitor;
//1)��������� 2 ����-���� �������������� �����, ������� � ������� ������� (�� ����� 8 ���� �� ����).
class Concert{
private:
	char artist_what_shown_[50];
	int date_of_concert_;
	int ticket_price_;
	int number_of_tickets_;
	char city_for_concert_[50];
	std::vector<Visitor*> visitors_; //3)����������� ��'���� ���� �ᒺ��� ������ ��������� �ᒺ��� ������ ����� � ������ ��� ������������ ������ �������.

public:
	int earned_money_;
	int number_of_visitors_;
	int vip_member_number_;
	//2)����� ���� ������� ������ 3 ������� �� 5 ������� ��������. ³��������� ������������ ��� ���� ����� � �������
	void setArtistWhatShown(char*artist);
	void setDateOfConcert(int date);
	void setTicketPrice(int price);
	void setNumberOfTickets(int number_of_tickets);
	void setCityForConcert(char*city);
	void setEarnedMoney(int money);
	void setNumberOfVisitors(int visitors);
	void setVipMemberNumber(int vips_number);
	//4)� ������� ���� ��������� 6 ������, �� ������������ ������ ��� (��� ������ ����� ���� ���������������), �� ���� ����� ������ � ����� ��������� �ᒺ�� �����, � �� ���� ����� ������� ��� �����
	char*getArtistWhatShown();
	int getDateOfConcert();
	int getTicketPrice();
	int getNumberOfTickets();
	char* getCityForConcert();
	int getEarnedMoney();
	int getNumberOfVisitors();
	int getVipMemberNumber();
	Visitor* getVisitor(int visitor);
	void addVisitor(Visitor *visitor);
	//5)��������� � ���� ������ ��� ������ � ���� �� ������� � ����� ���� �����. 
	void readFromFile(char* file);
	void writeToFile(char* file);

	std::vector<int> setOfNumberOfVisitirsValues();

};
//1)��������� 2 ����-���� �������������� �����, ������� � ������� ������� (�� ����� 8 ���� �� ����).
class Visitor{
private:
	Concert* concert_;
	int cache_;
	int years_old_;
	char name_[50];
	int discount_;
	int number_of_tickets_what_want_to_buy_;
public:
	char nickname_[50];
	bool vip_member_;
	int number_of_place_;
	//2)����� ���� ������� ������ 3 ������� �� 5 ������� ��������. ³��������� ������������ ��� ���� ����� � �������
	void goToConcert(Concert* concert);
	Concert* whatConcertIsVisit();
	void setCache(int cache);
	void setOld(int years_old);
	void setName(char* name);
	void setDiscount(int discount);
	void setDiscount(int discount, int cache);
	void setNumberOfTicketsWhatWantToBuy(int number_of_tickets);
	void setNumberOfTicketsWhatWantToBuy(int number_of_tickets, int cache);
	void setNickname(char* nickname);
	void setMember(bool member);
	void setNumberOfPlace(int number);

	int getCache();
	int getOld();
	char* getName();
	int getDiscount();
	int getNumberOfTicketsWhatWantToBuy();
	char* getNickname();
	bool getMember();
	int getNumberOfPlace();

	void readDataFieldsFromFile(char*file);
	void writeDataFieldsToFile(char*file);

	std::vector<int> setOfCacheValues(); //��������� ���������� ����� � ����, ���� ������ ��������� �������� �������� �����. � �����i ��������� ������� ������� ������ � ������������� ���� �� ����������� ��.
};

