class DataTime {
private:
	int second;
	int minute;
	int hour;
	int day;
	int mounth;
	int year;
public:
	void setSecond(int sec);
	void setMinute(int min);
	void setHour(int hour);
	void setDay(int day);
	void setMounth(int mounth);
	void setYear(int year);
	int getSecond();
	int getMinute();
	int getHour();
	int getDay();
	int getMounth();
	int getYear();
	void tick(int target);
	DataTime();
	DataTime(int sec, int min, int hour, int day, int mounth, int year);
};