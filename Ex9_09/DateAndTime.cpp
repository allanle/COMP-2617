#include <iostream>
#include "DateAndTime.h" 
using namespace std;


DateAndTime::DateAndTime(int m, int d, int y, int hr, int min, int sec) {
        setDate(m, d, y); 
        setTime(hr, min, sec);
} 

void DateAndTime::setDate(int mo, int dy, int yr) {
        setMonth(mo);
        setDay(dy); 
        setYear(yr); 
}

void DateAndTime::setDay(int d) {
        if (month == 2 && leapYear()) {
            day = (d <= 29 && d >= 1) ? d : 1;
        } else {
            day = (d <= monthDays() && d >= 1) ? d : 1;
        }

}

void DateAndTime::setMonth(int m) {
        month = m <= 12 && m >= 1 ? m : 1;
}

void DateAndTime::setYear(int y) {
        year = y >= 1900 ? y : 1900;
}

void DateAndTime::nextDay() {
        setDay(day + 1);

        if (day == 1) {
            setMonth(month + 1);
            if (month == 1) {
                setYear(year + 1); 
            }
        } 
}

void DateAndTime::setTime(int hr, int min, int sec) {
        setHour(hr); 
        setMinute(min); 
        setSecond(sec); 
    } 

void DateAndTime::setHour(int h) {
        hour = (h >= 0 && h < 24) ? h : 0; 
}

void DateAndTime::setMinute(int m) {
        minute = (m >= 0 && m < 60) ? m : 0; 
} 
	
void DateAndTime::setSecond(int s) {
        second = (s >= 0 && s < 60) ? s : 0;
}

void DateAndTime::tick() {
        setSecond(second + 1);
        if (second == 0) {
            setMinute(minute + 1); 
            if (minute == 0) {
                setHour(hour + 1);
                if (hour == 0) {
                    nextDay(); 
                }
            } 
        }
}

int DateAndTime::getDay() {
        return day;
} 

int DateAndTime::getMonth() {
        return month;
} 

int DateAndTime::getYear() {
        return year;
} 

int DateAndTime::getHour() {
        return hour;
} 

int DateAndTime::getMinute() {
        return minute;
} 

int DateAndTime::getSecond() {
        return second;
} 

void DateAndTime::printStandard() {
        cout << ((hour % 12 == 0) ? 12 : hour % 12) << ':' << (minute < 10 ? "0" : "") << minute << ':' << (second < 10 ? "0" : "") << second << (hour < 12 ? " AM " : " PM ") << month << '-' << day << '-' << year << endl;
} 

void DateAndTime::printUniversal() {
        cout << (hour < 10 ? "0" : "") << hour << ':' << (minute < 10 ? "0" : "") << minute << ':' << (second < 10 ? "0" : "") << second << "    " << month << '-' << day << '-' << year << endl;
} 
	
bool DateAndTime::leapYear() {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
            return true; 
        } else {
            return false;
        }
}

int DateAndTime::monthDays() {
        const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return (month == 2 && leapYear()) ? 29 : days[(month - 1)];
} 