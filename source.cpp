#define _CRT_SECURE_NO_WARNINGS
#include "visitor_definition.h"
#include "concert_definition.h"
#include "cassa_definition.h"
#include "manager_definition.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int Cassa::earned_money_ = 0;
int main(){
	Cassa::setEarnedMoney(10);
	Visitor visitor1;
	Visitor visitor2;
	Visitor visitor3;
	Visitor visitor4;
	Visitor visitor5;
	Concert * concert1 = new Concert;
	Concert * concert2 = new Concert;
	Concert * concert3 = new Concert;
	Concert * concert4 = new Concert;
	Concert * concert5 = new Concert;
	Visitor visitors[5];
	Visitor * visitors2 = new Visitor[5];
	for (int i = 0; i < 5; i++){
		visitors[i].readDataFieldsFromFile("file1.txt");
		visitors2[i].readDataFieldsFromFile("file1.txt");
	}
	for (int i = 0; i < 5; i++){
		visitors2[i].writeDataFieldsToFile("file2.txt");
	}
	concert1->readDataFieldsFromFile("file3.txt");
	Cassa * cs = new Cassa;
	Cassa cs1;
	Cassa cs2(cs1);
	Cassa cs3 = {0, 2, 100, 10, false, 0, 10, 20, 0, "Arsen"};
	cout << endl << "cs tickter price" << cs->getTicketPrice() << endl;
	cs->setCashPercent(20);
	setPriceOfTicket(*cs, 90);
	concert1->setTicketPrice(cs->getTicketPrice());
	cout << endl << "cs tickter price " << cs->getTicketPrice() << endl;
	doSomethingWithTicketPrice(cs);
	cs = doSomeCassaMethods(cs);
	Manager manager;
	manager.setPOfTicket(*cs, 97);
	cout << endl << "cs ticktet price " << cs->getTicketPrice() << endl;
	cs->setNumberOfTickets(2);
	visitors[0].setOld(100);
	visitors[1].setOld(100);
	cout << endl << "visitors money before " << visitors[0].getCache() << endl;
	cs->sellTickets(visitors, concert1);
	cs->sellTickets(visitors + 1, concert1);
	cout << endl << "visitors money after " << visitors[0].getCache() << endl;
	for (int i = 0; i < 5; i++)
		visitors2[i].goToConcert(concert1);
	std::cout << "Concert earned money " << concert1->getEarnedMoney() << endl;
	std::cout << "Cassa earned money " << cs->getEarnedMoney() << endl;

	Visitor * visitor1ptr = &visitor1;
	visitor1ptr->readDataFieldsFromFile("file1.txt");
	visitor1ptr->writeDataFieldsToFile("file4.txt");
	cin.get();
	system("pause");
	return 0;
}