#include "automobile_definition.h"
#include <iostream>

int main(){
	Auto static_memory_allocation[5] = { Auto(), Auto(), Auto(), Auto(), Auto() };
	Auto * dynamic_memory_allocation = new Auto[5];
	static_memory_allocation[1].setModel("LLL");
	cout << static_memory_allocation[1].getModel();
	dynamic_memory_allocation->changeSpeed(200);
	dynamic_memory_allocation->sortOfRandomSetOfSpeed();
	system("pause");
	return 0;
}