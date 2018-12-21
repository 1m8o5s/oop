#define _CRT_SECURE_NO_WARNINGS
#include "visitor_definition.h"
#include "concert_definition.h"
#include "cassa_definition.h"
#include "all_managers_definition.h"
#include "singer_definition.h"
#include "miniworld_definition.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int Cassa::earned_money_ = 0;
template <typename T>
void ServiceStatic(T* arr, int &len, char* name) {
	for (int i = 0; i < len; i++) {
		if (strcmp((arr + i)->getName(), name)) {
			for (int j = i + 1; j < len; j++) {
				*(arr + j - 1) = *(arr + j);
			}
		}
	}
}
template <typename T>
void ServiceDinamic(T* arr, int &len, char* name) {
	for (int i = 0; i < len; i++) {
		if (strcmp((arr + i)->getName(), name)) {
			for (int j = i + 1; j < len; j++) {
				arr[j - 1] = arr[j];
				try {
					arr = (T*)realloc(arr, --len);
					if (arr == nullptr)
						throw 1;
				}
				catch (...) {
					cout << "\nNot enough Memory\n";
				}
			}
		}
	}
}
int main(){
	Cassa::setEarnedMoney(10);
	Visitor visitor1;
	Visitor visitor2;
	Visitor visitor3;
	Visitor visitor4;
	Visitor visitor5;
	Concert * concert1 = nullptr;
	Concert * concert2 = nullptr;
	Concert * concert3 = nullptr;
	Concert * concert4 = nullptr;
	Concert * concert5 = nullptr;
	try {
		try {
			concert1 = new Concert;
			if (concert1 == nullptr)
				throw 1;
		}
		catch (int exc) {
			throw exc;
		}
		try {
			concert2 = new Concert;
			if (concert2 == nullptr)
				throw 1;
		}
		catch (int exc) {
			throw exc;
		}
		try {
			concert3 = new Concert;
			if (concert3 == nullptr)
				throw 1;
		}
		catch (int exc) {
			throw exc;
		}
		try {
			concert4 = new Concert;
			if (concert4 == nullptr)
				throw 1;
		}
		catch (int exc) {
			throw exc;
		}
		try {
			concert5 = new Concert;
			if (concert5 == nullptr)
				throw 1;
		}
		catch (int exc) {
			throw exc;
		}
	}
	catch (int exc) {
		cout << "\nNot enough memory\n";
	}
	catch (...) {
		cout << "\nNot enough memory\n";
	}
	Visitor visitors[5];
	Visitor * visitors2 = new Visitor[5];
	ifstream fin("file1.txt");
	for (int i = 0; i < 5; i++){
		fin.close();
		fin.open("file1.txt");
		visitors[i].readDataFieldsFromFile(fin);
		fin.close();
		fin.open("file1.txt");
		visitors2[i].readDataFieldsFromFile(fin);
	}
	fin.close();
	ofstream fout("file2.txt");
	for (int i = 0; i < 5; i++){
		fout.close();
		fout.open("file2.txt");
		visitors2[i].writeDataFieldsToFile(fout);
	}
	fout.close();
	ifstream fin1("file3.txt");
	concert1->readDataFieldsFromFile(fin1);
	fin1.close();
	Cassa * cs = new Cassa;
	Cassa cs1;
	Cassa cs2(cs1);
	Cassa cs3 = {100, 10, false, 0, 10, 20, 0, (char*)"Arsen"};
	cout << endl << "cs tickter price" << cs->getTicketPrice() << endl;
	cs->setCashPercent(20);
	setPriceOfTicket(*cs, 90);
	concert1->setTicketPrice(cs->getTicketPrice());
	cout << endl << "cs tickter price " << cs->getTicketPrice() << endl;
	doSomethingWithTicketPrice(cs);
	cs = doSomeCassaMethods(cs);
	ClubManager* cl = new ClubManager; // Ivan
	SingerManager* sm = new SingerManager(0, 0, (char*)"Askold");
	Singer* sn = new Singer;
	SecurityManager* security = new SecurityManager(0, 0, (char*)"Eldar");
	SecurityManager man;

	Manager* mn;
	mn = new ClubManager;
	cout << mn->getName() << endl;
	delete mn;
	mn = new SingerManager;
	cout << mn->getName() << endl;

	Manager* nn;
	nn = cl;
	cout << nn->getName() << endl;
	nn = sm;
	cout << nn->getName() << endl;

	Manager* nm;
	nm = (ClubManager*)sm;
	cout << nm->getName() << endl;
	nm = (SingerManager*)cl;
	cout << nm->getName() << endl;

	cl->agreeCashPercentWithSingerManager(cs, sm, 20);
	cl->agreeTicketPriceWithSingerManager(cs, sm, 50);
	sm->setCityForConcert(concert1, sn, (char*)"Lviv");
	cout << endl << "cs ticktet price " << cs->getTicketPrice() << endl;
	cs->setNumberOfTickets(2);
	visitors[0].setOld(100);
	visitors[1].setOld(100);
	cout << endl << "visitors money before " << visitors[0].getCache() << endl;
	cs->sellTickets(visitors, concert1, cl, sm, security, sn);
	cs->sellTickets(visitors + 1, concert1, cl, sm, security, sn);
	cout << endl << "visitors money after " << visitors[0].getCache() << endl;
	for (int i = 0; i < 5; i++)
		visitors2[i].goToConcert(concert1);
	std::cout << "Concert earned money " << concert1->getEarnedMoney() << endl;
	std::cout << "Cassa earned money " << cs->getEarnedMoney() << endl;

	Visitor * visitor1ptr = &visitor1;
	ifstream f("file1.txt");
	visitor1ptr->readDataFieldsFromFile(f);
	f.close();
	ofstream f2("file2.txt");
	visitor1ptr->writeDataFieldsToFile(f2);
	f2.close();
	MiniWorld * world = new MiniWorld;
	world->loop();
	system("pause");
	return 0;
}