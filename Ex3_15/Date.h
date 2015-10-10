class Date {
public:
	Date(int, int, int);
	
	void setMonth(int);
	int getMonth() const;
	
	void setDay(int);
	int getDay() const;
	
	void setYear(int) ;
	int getYear() const;
	
	void displayDate() const;

private:	
	int month;
	int day;
	int year;	
};