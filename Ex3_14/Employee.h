#include <string>

class Employee {
public:
	Employee(std::string, std::string, int);
	
	void setFirstName(std::string);
	std::string getFirstName() const;
	
	void setLastName(std::string);
	std::string getLastName() const;
	
	void setMonthlySalary(int);
	int getMonthlySalary() const;

private:	
	std::string firstName;
	std::string lastName;
	int monthlySalary;
};