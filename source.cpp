#include <iostream>
#include <fstream>
#include <cstring>
#include <clocale>
using namespace std;
struct time_{
	int time__sec;
	int time__min;
	int time__hour;
	int time__mday;
	int time__mon;
	int time__year;
};
struct Student{//binary
	char name[32];
	char surname[32];
	int age;
	struct time_ date_of_birth;
};
struct Train{//text
	int train_number;
	char destination[64];
	struct time_ departure_time;
	struct time_ arrival_time;
	int time_in_road;
};
void read_from_file(struct Train * trains, int m){
	ifstream fin("info.txt");
	char skip_2dots;
	char e;
	for (int i = 0; i < m; i++){
		fin >> trains[i].train_number >> trains[i].destination
			>> trains[i].departure_time.time__hour >> skip_2dots >> trains[i].departure_time.time__min >> skip_2dots >> trains[i].departure_time.time__sec
			>> trains[i].arrival_time.time__hour >> skip_2dots >> trains[i].arrival_time.time__min >> skip_2dots >> trains[i].arrival_time.time__sec;
	}
	fin.close();
}
void read_from_file(struct Student * students, int n){
	ifstream fin("info.dat", ios::binary);
	students = (struct Student*)realloc(students, n*sizeof(struct Student));
	for (int i = 0; i < n; i++){
		fin.read((char *)&students[i], sizeof(students[i]));
	}
	fin.close();
}
void write_to_file(struct Train * trains, int m){
	ofstream fout("info.txt");
	for (int i = 0; i < m; i++){
		fout << trains[i].train_number << "  " << trains[i].destination << "  "
			<< trains[i].departure_time.time__hour << ":" << trains[i].departure_time.time__min << ":" << trains[i].departure_time.time__sec << "   "
			<< trains[i].arrival_time.time__hour << ":" << trains[i].arrival_time.time__min << ":" << trains[i].arrival_time.time__sec << endl;
	}
	fout.close();
}
void write_to_file(struct Student * students, int * n){
	ofstream fout("info.dat", ios::binary);
	for (int i = 0; i < *n; i++){
		fout.write((char *)&students[i], sizeof(students[i]));
	}
	fout.close();
}
void sort(struct Student * students, int n){
	int j = n;
	struct Student * time_p = (struct Student*)malloc(sizeof(struct Student));
	bool swapped;
	do{
		swapped = false;
		for (int i = 1; i < j--; i++){
			if (students[i - 1].age > students[i].age){
				*time_p = students[i - 1];
				students[i - 1] = students[i];
				students[i] = *time_p;
				swapped = true;
			}
		}
	} while (swapped);
}
int main(){
	setlocale(LC_ALL, "ukr");
	
	int n;
	cout << "¬ведiть кiлькiсть студентiв: ";
	cin >> n;
	struct Student * students = (struct Student *)malloc(n*sizeof(struct Student));
	for (int i = 0; i < n; i++){
		cout << "¬ведiть iм'€:  ";
		cin >> students[i].name;
		cout << "¬ведiть прiзвище:  ";
		cin >> students[i].surname;
		cout << "¬ведiть дату народженн€ в форматi DD MM YYYY:  ";
		cin >> students[i].date_of_birth.time__mday >> students[i].date_of_birth.time__mon >> students[i].date_of_birth.time__year;
	}
	write_to_file(students, &n);
	free(students);

	struct Student *students1 = (struct Student *)malloc(n*sizeof(struct Student));
	read_from_file(students1, n);
	for (int i = 0; i < n; i++){
		students1[i].age = students1[i].date_of_birth.time__year * 400 + students1[i].date_of_birth.time__mon * 32 + students1[i].date_of_birth.time__mday;
	}
	sort(students1, n);
	for (int i = 0; i < n; i++){
		cout << students1[i].surname << " " << students1[i].date_of_birth.time__mday << " " << students1[i].date_of_birth.time__mon << " " << students1[i].date_of_birth.time__year << endl;
	}
	cout << endl;


	/*
	int m;
	cout << "¬ведiть кiлькiсть поњздiв: ";
	cin >> m;
	struct Train * trains = (struct Train *)malloc(m*sizeof(struct Train));
	for (int i = 0; i < m; i++){
		cout << "¬ведiть номер поњзда:  ";
		cin >> trains[i].train_number;
		cout << "¬ведiть станцiю призначенн€:  ";
		cin >> trains[i].destination;
		cout << "¬ведiть час вiдправленн€ у форматi hh mm ss:  ";
		cin >> trains[i].departure_time.time__hour >> trains[i].departure_time.time__min >> trains[i].departure_time.time__sec;
		cout << "¬ведiть час прибутт€ у форматi hh mm ss:  ";
		cin >> trains[i].arrival_time.time__hour >> trains[i].arrival_time.time__min >> trains[i].arrival_time.time__sec;
	}
	write_to_file(trains, m);
	free(trains);
	struct Train * trains1 = (struct Train *)malloc(m*sizeof(struct Train));
	read_from_file(trains1, m);

	for (int i = 0; i < m; i++){
		trains1[i].time_in_road = trains1[i].arrival_time.time__hour * 3600 + trains1[i].arrival_time.time__min * 60 + trains1[i].arrival_time.time__sec - (trains1[i].departure_time.time__hour * 3600 + trains1[i].departure_time.time__min * 60 + trains1[i].departure_time.time__sec);
		if (trains1[i].time_in_road/3600 < 10)
		cout << trains1[i].train_number << "  " << trains1[i].destination << "  "
			<< trains1[i].departure_time.time__hour << ":" << trains1[i].departure_time.time__min << ":" << trains1[i].departure_time.time__sec << "   "
			<< trains1[i].arrival_time.time__hour << ":" << trains1[i].arrival_time.time__min << ":" << trains1[i].arrival_time.time__sec << endl;
	}
	free(trains1);
	*/
	system("pause");
	return 0;
}