#define _CRT_SECURE_NO_WARNINGS
#include "visitor_and_concert_classes_definition.h"
#include <iostream>
#include <fstream>
int main(){
	//6)У програмі побудувати 5 об'єктів, розміщених у статичній пам’яті, та 5 об’єктів - у динамічній пам'яті
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
	//7)В основній програмі визначити 2 масиви об'єктів. 
	Visitor visitors[5];
	Visitor * visitors2 = new Visitor[5];
	//9)Продемонструвати роботу усіх методів, описаних в класах.
	for (int i = 0; i < 5; i++){
		visitors[i].readDataFieldsFromFile("file1.txt");
		visitors2[i].readDataFieldsFromFile("file1.txt");
	}
	for (int i = 0; i < 5; i++){
		visitors2[i].writeDataFieldsToFile("file2.txt");
	}
	concert1->readFromFile("file3.txt");
	for (int i = 0; i < 5; i++) 
		visitors2[i].goToConcert(concert1); //8)Продемонструвати роботу з об’єктами, розміщеними в даному масиві. //10)Продемонструвати сценарій взаємодії двох об’єктів
	std::cout << visitors2[2].whatConcertIsVisit()->getArtistWhatShown();
	std::cout << concert1->getVisitor(0)->getCache();
	Visitor * visitor1ptr = &visitor1; //11)Показати в програмі використання покажчика на екземпляр класу.
	visitor1ptr->readDataFieldsFromFile("file1.txt");
	visitor1ptr->writeDataFieldsToFile("file4.txt");
	system("pause");
	return 0;
}