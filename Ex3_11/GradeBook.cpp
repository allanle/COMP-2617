#include <iostream>
#include "GradeBook.h"

using namespace std;

GradeBook::GradeBook(string courseName, string instructorName) {
	setCourseName(courseName);
	setInstructorName(instructorName);
}

void GradeBook::setCourseName(string name) {
	courseName = name;
}

string GradeBook::getCourseName() const {
	return courseName;
}

void GradeBook::setInstructorName(string name) {
	instructorName = name;
}

string GradeBook::getInstructorName() const {
	return instructorName;
}

void GradeBook::displayMessage() const {
	cout << "Welcome to the grade book \nfor course: " << getCourseName()
		 << "\nand instructor: " << getInstructorName() << "\n" << endl;
}