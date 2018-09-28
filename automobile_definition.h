//T3
//1^��������� �������������� ����

//2^���� ������� ������ 3 ������� � 5 ��������� �������. ³��������� ������������ ��� ���� ����� � �������

//3^��������� � ���� ������ ��� ������ � ���� � ���������� � ����� ���� �����

//4^ � ���� ��������� 4 ������, �� ������������ ������ ��� (��� ������ ����� ���� ���������������).

//5^��������� � ���� ����� ���� ������ ��������� �������� �������� ���'��
//� ����� ��������� ������� ������� ������ � ������������� ���� �� ����������� ��.
//1^, 2^, 3^, 4^, 7^;
//���������� ����������, ���������� ���� ����
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