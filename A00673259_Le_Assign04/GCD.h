/**
COMP 2617
Assignment 4
Greatest Common Denominator Template Class.

@author Allan Le A00673259
@version 2015/10/28
*/

template<class T>

T gcd(T x, T y) {
	T greatest = 1;

	if (x < 0) {
		x = -x;
	}

	if (y < 0) {
		y = -y;
	}

	for (T i = 2; i <= ((x < y) ? x : y); i++) {
		if (x % i == 0 && y % i == 0) {
			greatest = i;
		}
	}

	return greatest;
}