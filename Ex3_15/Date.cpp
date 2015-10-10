#include <iostream>
#include "Date.h"

using namespace std;

Date::Date(int m, int d, int y) {
	setMonth(m);
	setDay(d);
	setYear(y);
}

void Date::setMonth(int m) {
	if(m < 1 || m > 12) {
		month = 1;
	} else {
		month = 12;
	}
}

int Date::getMonth() const {
	return month;
}

void Date::setDay(int d) {
	day = d;
}

int Date::getDay() const {
	return month;
}

void Date::setYear(int y) {
	year = y;
}

int Date::getYear() const {
	return year;
}

void Date::displayDate() const {
	cout << month << '/' << day << '/' << year << endl;
}