/**
COMP 2617
Assignment 4
Member-function definitions for class Fraction.

@author Allan Le A00673259
@version 2015/10/28
*/

#include "Fraction.h"
#include "GCD.h" // template function for calculating greatest common divisor
#include <iostream>
using namespace std;

/**
	Default ctor
*/
Fraction::Fraction(void) : numerator(0), denominator(1) {

}

/**
	Second ctor
	@param num numerator argument
	@param denom denominator argument
*/
Fraction::Fraction(long long num, long long denom) 
	    : numerator(num), denominator(denom) {
	if (denominator == 0) {
		numerator = 0;
		denominator = 1;
		cerr << "\n\n Attempt was made to create a Fraction" 
			 << "object with a denominator of 0 !!!\n\n";
	}else{
		simplify();
	}
}

/**
	Plus Equation.
	@param op Integer value.
*/
const Fraction & Fraction::plusEq(const Fraction & op) {
	numerator = (numerator * op.denominator) + (op.numerator * denominator);
	denominator *= op.denominator;

	simplify();

	return(*this);
}

/**
	Minus Equation
	@param op Integer value.
*/
const Fraction & Fraction::minusEq(const Fraction & op) {
	numerator =  (numerator * op.denominator) - (op.numerator * denominator);
	denominator *= op.denominator;

	simplify();

	return(*this);
}

/**
	Times Equation
	@param op Integer value.
*/
const Fraction & Fraction::timesEq(const Fraction & op ) {
	numerator *= op.numerator;
	denominator *= op.denominator;

	simplify();  // will make sure that denominator is positive and
	             //   will invoke gcd() function to reduce fraction
	             //   as much as possible

	return (*this); // returns the object which invoked the method
}

/**
	Divide Equation
	@param op Integer value.
*/
const Fraction & Fraction::divideEq(const Fraction & op) {
	numerator *= op.denominator;
	denominator *= op.numerator;

	simplify();

	return(*this);
}

/**
	Returns the negation object.
*/
Fraction Fraction::negate(void) const {
	return Fraction(-numerator, denominator);
}

/**
	Returns top number.
*/
long long Fraction::getNum(void) const {
	return numerator;
}

/**
	Returns bottom number.
*/
long long Fraction::getDenom(void) const {
	return denominator;
}


/**
	Displays output.
*/
void Fraction::display(void) const {
	cout << numerator << '/' << denominator;
}


/**
	Simplifies the outcome until it can't be simplified anymore.
*/
void Fraction::simplify(void) {
	// If the top number is 0, make it a 1.
	if (numerator == 0) {
		denominator = 1;
	}else{
		long greatest = gcd(numerator, denominator);

		if (greatest > 1) {
			numerator /= greatest;
			denominator /= greatest;
		}
	}

	// If the bottom number is less than zero
	// Make it a negative integer.
	if (denominator < 0) {
		numerator = -numerator;
		denominator = -denominator;
	}
}