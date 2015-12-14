#ifndef Complex_incl
#define Complex_incl

class Complex {
public:
	Complex(const double & realVal = 1.0, const double & imgVal = 0.0);
	Complex & plusEq(const Complex & RHS);
	Complex & minusEq(const Complex & RHS);
	void setReal(const double & realVal);
	void setImaginary(const double & imagVal);
	const double & getReal(void) const;
	const double & getImaginary(void) const;
	void display(void) const;

private:
	double real_part;
	double imaginary_part;
};

#endif