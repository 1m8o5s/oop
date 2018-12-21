#include <sstream>
#include <vector>
using namespace std;
class Cassa;
class Visitor;
class Concert;
class Manager;
class SingerManager;
class ClubManager;
class SecurityManager;
class Singer;
class DataTime;
class MiniWorld {
private:
	vector<Cassa*> cassa;
	vector<Visitor*> visitors;
	vector<Concert*> concerts;
	vector<SingerManager*> singer_managers;
	vector<ClubManager*> club_managers;
	vector<SecurityManager*> security_managers;
	vector<Singer*> singers;
	DataTime* present;
public:
	void addCassa(char* file, char*mode);
	void addVisitor(char* file, char*mode);
	void addConcert(char* file, char*mode);
	void addSingerManager(char* file, char*mode);
	void addClubManager(char* file, char*mode);
	void addSecurityManager(char* file, char*mode);
	void addSinger(char* file, char*mode);


	void removeCassa(char* title);
	void removeVisitor(char* name);
	void removeConcert(char* title);
	void removeSingerManager(char* name);
	void removeClubManager(char* name);
	void removeSecurityManager(char* name);
	void removeSinger(char* name);

	Cassa* getCassa(char* title);
	Visitor* getVisitor(char* name);
	Concert* getConcert(char* title);
	SingerManager* getSingerManager(char* name);
	ClubManager* getClubManager(char* name);
	SecurityManager* getSecurityManager(char* name);
	Singer* getSinger(char* name);

	MiniWorld();
	MiniWorld(vector<Cassa*>&, vector<Visitor*>&, vector<Concert*>&, vector<SingerManager*>&, vector<ClubManager*>&, vector<SecurityManager*>&, vector<Singer*>&, DataTime*);
	stringstream analyseCommands(stringstream& text);
	void executeCommands(stringstream& text);
	void loop();
};