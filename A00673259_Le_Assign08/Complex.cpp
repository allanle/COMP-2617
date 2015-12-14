#include <iostream>
#include <iomanip>
#include "Complex.h"
using namespace std;

Complex::Complex(const double & realVal, const double & imagVal) {
	setReal(realVal);
	setImaginary(imagVal);
}

void Complex::setReal(const double & realVal) {
	real_part = realVal;
}

void Complex::setImaginary(const double & imagVal) {
	imaginary_part = imagVal;
}

Complex & Complex::plusEq(const Complex & op) {
	real_part += op.real_part;
	imaginary_part += op.imaginary_part;
	return (*this);
}

Complex & Complex::minusEq(const Complex & op) {
	real_part -= op.real_part;
	imaginary_part -= op.imaginary_part;
	return (*this);
}

const double & Complex::getReal(void) const {
	return real_part;
}

const double & Complex::getImaginary(void) const {
	return imaginary_part;
}

void Complex::display(void) const {
	cout << fixed << setprecision(4);
	cout << "( " << getReal() << " , " << getImaginary() << " )";
}