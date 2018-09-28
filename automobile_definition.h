//T3
//1^Визначити користувацький клас

//2^Клас повинен містити 3 загальні і 5 приватних значень. Відобразити використання всіх полів даних у методах

//3^Визначити в класі методи для запису у файл і зчитування з файлу полів даних

//4^ В класі визначити 4 методи, які опрацьовують описані дані (два методи мають бути перевантаженими).

//5^Визначити в класі метод який виділяє випадкову величину динамічної пам'яті
//В пам’яті розмістити множину значень одного з цілочисельних полів та відсортувати їх.
//1^, 2^, 3^, 4^, 7^;
//Реалізовано визначення, функціонал десь інше
#include <string>
using namespace std;
class Auto{
private:
	string proizvoditel;
	string model;
	string motor_name;
	int year_of_birth;
	string seriinii_nomer;
public:
	int rgb_color[3];
	string nomernii_znak;
	int speed;

	void changeColor(int r, int g, int b);
	void changeColor(int r, int g, int b, string newznak);
	void changeNomerniiZnak(string newznak);
	void changeSpeed(int speed);
	void changeMotor(string newmotor);
	void changeMotor(string newmotor, int powerful);
	//i am zdelat eto
	void readProizvoditel(string file);
	void readModel(string file);
	void readMotorName(string file);
	void readSeriiniiNomer(string file);
	void readColor(string file);
	void readNomerniiZnak(string file);
	void readYearOfBirth(string file);
	void readSpeed(string file);
	void readAll(string file);

	void writeProizvoditel(string file);
	void writeModel(string file);
	void writeMotorName(string file);
	void writeSeriiniiNomer(string file);
	void writeColor(string file);
	void writeNomerniiZnak(string file);
	void writeYearOfBirth(string file);
	void writeSpeed(string file);
	void writeAll(string file);

	string getProizvoditel();//
	string getModel();//
	string getMotorName();//
	int getYearOfBirth();//
	string getSeriiniiNomer();//

	void setProizvoditel(string proizvoditel);//
	void setModel(string model);//
	void setMotorName(string motor_name);//
	void setYearOfBirth(int year);//
	void setSeriiniiNomer(string seriinii_nomer);//


	void sortOfRandomSetOfSpeed();
};