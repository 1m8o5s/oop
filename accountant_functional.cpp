#include "all_managers_definition.h"
#include <iostream>
using namespace std;
int Accountant::getEarnedMoney(){
	return this->earned_money_;
}
void Accountant::setEarnedMoney(int earned_money){
	this->earned_money_ = earned_money;
}
Accountant::Accountant(int experience, int earned_money, int cash_percent_what_want_to_receive_from_agreement, int percent_from_earnings, int ticket_price_what_want_to_receive_from_agreement)
	:experience_(experience), earned_money_(earned_money), cash_percent_what_want_to_receive_from_agreement_(cash_percent_what_want_to_receive_from_agreement), percent_from_earnings_(percent_from_earnings), ticket_price_what_want_to_receive_from_agreement_(ticket_price_what_want_to_receive_from_agreement)
{
	cout << endl << "Accountant Constructor" << endl;
}
Accountant::~Accountant(){
	cout << endl << "Accountant Destructor" << endl;
}
