#include "miniworld_definition.h"
#include "all_managers_definition.h"
#include "cassa_definition.h"
#include "singer_definition.h"
#include "visitor_definition.h"
#include "concert_definition.h"
#include "data_time_definition.h"

template <typename T>
void ServiceRead(T *what, char* file, bool binary) {
	if (binary) {
		ifstream fin;
		try {
			fin.open(file, ios::binary);
			if (fin.eof())
				throw 1;
			fin.read(reinterpret_cast<char*>(what), sizeof(T));

		}
		catch (int exc) {
			fin.close();
		}
		catch (...) {
			fin.close();
		}
	}
	else {
		ifstream fin;
		try {
			fin.open(file);
			if (fin.eof())
				throw 1;
			what->readDataFieldsFromFile(fin);
		}
		catch (int exc) {
			fin.close();
		}
		catch (...) {
			fin.close();
		}
	}
}
template <typename T>
void ServiceWrite(T *what, char* file, bool binary) {
	if (binary) {
		ofstream fin;
		try {
			fin.open(file, ios::binary);
			fin.write(reinterpret_cast<char*>(what), sizeof(T));
		}
		catch (...) {
			fin.close();
		}
	}
	else {
		ofstream fin;
		try {
			fin.open(file);
			what->writeDataFieldsToFile(fin);
		}
		catch (...) {
			fin.close();
		}
	}
}
void MiniWorld::addCassa(char* file, char*mode) {
	cassa.push_back(new Cassa);
	if (strcmp(mode, "binary")) {
		ServiceRead<Cassa>(cassa[cassa.size() - 1], file, false);
	}
	else {
		ServiceRead<Cassa>(cassa[cassa.size() - 1], file, true);
	}
}
void MiniWorld::addVisitor(char* file, char*mode) {
	visitors.push_back(new Visitor);
	if (strcmp(mode, "binary")) {
		ServiceRead<Visitor>(visitors[visitors.size() - 1], file, false);
	}
	else {
		ServiceRead<Visitor>(visitors[cassa.size() - 1], file, true);
	}
}
void MiniWorld::addConcert(char* file, char*mode) {
	concerts.push_back(new Concert);
	if (strcmp(mode, "binary")) {
		ServiceRead<Concert>(concerts[concerts.size() - 1], file, false);
	}
	else {
		ServiceRead<Concert>(concerts[concerts.size() - 1], file, true);
	}
}
void MiniWorld::addSingerManager(char* file, char*mode) {
	singer_managers.push_back(new SingerManager);
	if (strcmp(mode, "binary")) {
		ServiceRead<SingerManager>(singer_managers[singer_managers.size() - 1], file, false);
	}
	else {
		ServiceRead<SingerManager>(singer_managers[singer_managers.size() - 1], file, true);
	}
}
void MiniWorld::addClubManager(char* file, char*mode) {
	club_managers.push_back(new ClubManager);
	if (strcmp(mode, "binary")) {
		ServiceRead<ClubManager>(club_managers[club_managers.size() - 1], file, false);
	}
	else {
		ServiceRead<ClubManager>(club_managers[club_managers.size() - 1], file, true);
	}
}
void MiniWorld::addSecurityManager(char* file, char*mode) {
	security_managers.push_back(new SecurityManager);
	if (strcmp(mode, "binary")) {
		ServiceRead<SecurityManager>(security_managers[security_managers.size() - 1], file, false);
	}
	else {
		ServiceRead<SecurityManager>(security_managers[security_managers.size() - 1], file, true);
	}
}
void MiniWorld::addSinger(char* file, char*mode) {
	singers.push_back(new Singer);
	if (strcmp(mode, "binary")) {
		ServiceRead<Singer>(singers[singers.size() - 1], file, false);
	}
	else {
		ServiceRead<Singer>(singers[singers.size() - 1], file, true);
	}
}
template <typename T>
void removeComponent(T where, char*what) {
	int i = 0;
	for (; i < where.size(); i++) {
		if (!strcmp(where[i]->getName(), what))
			break;
	}
	auto it = where.begin();
	it += i;
	where.erase(it);
}

MiniWorld::MiniWorld():cassa(),visitors(), concerts(), singer_managers(), club_managers(), security_managers(), singers(), present() {

}
MiniWorld::MiniWorld(vector<Cassa*>& cassa, vector<Visitor*>& visitors, vector<Concert*>&concerts, vector<SingerManager*>&singer_managers, vector<ClubManager*>&club_managers, vector<SecurityManager*>&security_managers, vector<Singer*>&singers, DataTime* present) 
					:cassa(cassa), visitors(visitors), concerts(concerts), singer_managers(singer_managers), club_managers(club_managers), security_managers(security_managers), singers(singers), present(present)
{

}

void MiniWorld::executeCommands(stringstream& text) {
	stringstream set_of_lexems = analyseCommands(text);
	char tmp_token[50];
	set_of_lexems >> tmp_token;
	if (!strcmp(tmp_token, "tick")) {
		set_of_lexems >> tmp_token;
		if (!strcmp(tmp_token, "second")) {
			present->tick(0);
		}
		else if (!strcmp(tmp_token, "minute")) {
			present->tick(1);
		}
		else if (!strcmp(tmp_token, "hour")) {
			present->tick(2);
		}
		else if (!strcmp(tmp_token, "day")) {
			present->tick(3);
		}
		else if (!strcmp(tmp_token, "mounth")) {
			present->tick(4);
		}
		else if (!strcmp(tmp_token, "year")) {
			present->tick(5);
		}
	}
	else if (!strcmp(tmp_token, "remove")) {
		char name[50];
		char type[50];
		set_of_lexems >> name;
		set_of_lexems >> type;
		if (!strcmp(type, "Cassa")) {
			removeComponent<vector<Cassa*> >(cassa, name);
		}
		else if (!strcmp(type, "Visitor")) {
			removeComponent<vector<Visitor*> >(visitors, name);
		}
		else if (!strcmp(type, "Concert")) {
			removeComponent<vector<Concert*> >(concerts, name);
		}
		else if (!strcmp(type, "SingerManager")) {
			removeComponent<vector<SingerManager*> >(singer_managers, name);
		}
		else if (!strcmp(type, "ClubManager")) {
			removeComponent<vector<ClubManager*> >(club_managers, name);
		}
		else if (!strcmp(type, "SecurityManager")) {
			removeComponent<vector<SecurityManager*> >(security_managers, name);
		}
		else if (!strcmp(type, "Singer")) {
			removeComponent<vector<Singer*> >(singers, name);
		}
	}
	else if (!strcmp(tmp_token, "add")) {
		char type[50];
		char mode[50];
		char file[50];
		set_of_lexems >> type >> mode >> file;
		if (!strcmp(type, "Cassa")) {
			addCassa(file, mode);
		}
		else if (!strcmp(type, "Visitor")) {
			addVisitor(file, mode);
		}
		else if (!strcmp(type, "Concert")) {
			addConcert(file, mode);
		}
		else if (!strcmp(type, "SingerManager")) {
			addSingerManager(file, mode);
		}
		else if (!strcmp(type, "ClubManager")) {
			addClubManager(file, mode);
		}
		else if (!strcmp(type, "SecurityManager")) {
			addSecurityManager(file, mode);
		}
		else if (!strcmp(type, "Singer")) {
			addSinger(file, mode);
		}
	}
}
stringstream MiniWorld::analyseCommands(stringstream& text) {
	char tmp_token[50];
	stringstream set_of_lexems;
	text >> tmp_token;
	set_of_lexems << tmp_token << " ";
	
	if (!strcmp(tmp_token, "tick")) {
		text >> tmp_token;
		set_of_lexems << tmp_token << " ";
	}
	else if (!strcmp(tmp_token, "remove")){
		text >> tmp_token;
		set_of_lexems << tmp_token << " ";
		text >> tmp_token;
		text >> tmp_token;
		set_of_lexems << tmp_token << " ";
	}
	else {
		text >> tmp_token;
		set_of_lexems << tmp_token << " ";
		text >> tmp_token;
		text >> tmp_token;
		set_of_lexems << tmp_token << " ";
		text >> tmp_token;
		set_of_lexems << tmp_token << " ";
	}
	return set_of_lexems;
}
void MiniWorld::loop() {
	//Зчитування з консольки команд від користувача
	char buf[200];
	stringstream text;
	while (true) {
		cout << endl << "Enter command:" << endl;
		cin.getline(buf, 200);
		if (!strcmp(buf, "exit"))
			return;
		text.write(buf, 200);
		executeCommands(text);
	}
	/*  | add type from text|binary "file"
		| remove name as type
		| show name as type /// в наступній версії
		| tick second|minute|hour|day|mounth|year
		| exit


	*/
	//Виконання команд від користувача

}