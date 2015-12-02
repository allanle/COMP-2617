#ifndef DATEANDTIME_H
#define DATEANDTIME_H

class DateAndTime {
public:
	DateAndTime(int = 1, int = 1, int = 1900, int = 0, int = 0, int = 0);
	void setDate(int, int, int);
	void setMonth(int);
	void setDay(int);
	void setYear(int);
	void nextDay();
	void setTime(int, int, int);
	void setHour(int);
	void setMinute(int);
	void setSecond(int);
	void tick();
	int getMonth();
	int getDay();
	int getYear();
	int getHour();
	int getMinute();
	int getSecond();
	void printStandard();
	void printUniversal();

private:
	int month;
	int day;
	int year;
	int hour;
	int minute;
	int second;
	bool leapYear();
	int monthDays();
};

#endif