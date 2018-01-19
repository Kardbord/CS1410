//Tanner Kvarfordt
//A02052217

//Implementation for RatNum.h

#include "RatNum.h"

//Constructors, get and set functions
RatNum::RatNum(int num, int denom) {
	setNumerator(num);
	setDenominator(denom);
	simplify();
}

void RatNum::setNumerator(int num){
	numerator = num;
}

void RatNum::setDenominator(int denom) {
	if (denom == 0) {
		denominator = 1;
	}
	else {
		denominator = denom;
		if (denom < 0) {
			denominator = denom * (-1); //if it hits the fan, remove this nested if statement and just set denominator = denom
			numerator = numerator * (-1);
		}
	}
}

void RatNum::resetRatNum(int num, int denom) {
	setNumerator(num);
	setDenominator(denom);
	simplify();
}

//Arithmatic operator overloads
RatNum RatNum::operator+=(RatNum const & b) {
	numerator = b.denominator * numerator + b.numerator * denominator;
	denominator = b.denominator * denominator;
	simplify();
	return *this;//"this" is a pointer to the object calling the function, we de-reference it with * so we are changing the value and not returning a reference
}

RatNum RatNum::operator-=(RatNum const & b) {
	numerator = b.denominator * numerator - b.numerator * denominator;
	denominator = b.denominator * denominator;
	simplify();
	return *this;
}

RatNum RatNum::operator*=(RatNum const & b) {
	numerator = numerator * b.numerator;
	denominator = denominator * b.denominator;
	simplify();
	return *this;
}

RatNum RatNum::operator/=(RatNum const & b) {
	numerator = numerator *b.denominator;
	denominator = denominator * b.numerator;
	simplify();
	return *this;
}

RatNum operator+(RatNum a, RatNum const & b) {
	return (a += b);
}

RatNum operator-(RatNum a, RatNum const & b) {
	return (a -= b);
}

RatNum operator*(RatNum a, RatNum const & b) {
	return (a *= b);
}

RatNum operator/(RatNum a, RatNum const & b) {
	return (a /= b);
}

//Simplification
void RatNum::simplify() {
	int gcd = abs(EuclidGCD(numerator, denominator));
	numerator /= gcd;
	denominator /= gcd;
}

int EuclidGCD(int num, int denom) {
	if (num == 0) {
		return denom; //I thought in order to use this cmath, math.h, or cstdlib were req'd... must investigate
	}
	else {
		return EuclidGCD(denom % num, num);
	}
}

//Extraction and insertion operator overloads
std::ostream & operator<<(std::ostream & frac, RatNum const & a) { //the ostream object we are passing this is cout. cout << a; is equivalent to operator<<(cout, a);
	return frac << a.getNumerator() << '/' << a.getDenominator();
}

std::istream & operator>>(std::istream & frac, RatNum & a) { //the istream object we are passing this is cin. cin >> a; is equivalent to operator>>(cin, a);
	int tempnum, tempdenom;
	char slash ='w';
	frac >> tempnum >> slash >> tempdenom;
	while (slash != '/') {
		std::cout << "\aError, input was not in expected form.\nPlease enter a fraction in the form a/b: ";
		frac >> tempnum >> slash >> tempdenom;
	}
	a.resetRatNum(tempnum, tempdenom);
	return frac;
}

//Type casting overloads
RatNum::operator double() {
	return static_cast<double>(numerator) / denominator;
}

RatNum::operator float() {
	return static_cast<float>(numerator) / denominator;
}

//Comparison Operator Overloads
bool operator<(RatNum const & a, RatNum const & b) {
	if (a.getNumerator() * b.getDenominator() < a.getDenominator() * b.getNumerator()) {
		return true;
	}
	else {
		return false;
	}
}

bool operator>(RatNum const & a, RatNum const & b) {
	if (b < a) {
		return true;
	}
	else {
		return false;
	}
}

bool operator==(RatNum const & a, RatNum const & b) {
	if (a.getNumerator() * b.getDenominator() == a.getDenominator() * b.getNumerator()) {
		return true;
	}
	else {
		return false;
	}
}

bool operator<=(RatNum const & a, RatNum const & b) {
	if (a < b) {
		return true;
	}
	else if (a == b) {
		return true;
	}
	else {
		return false;
	}
}

bool operator>=(RatNum const & a, RatNum const & b) {
	if (b < a) {
		return true;
	}
	else if (a == b) {
		return true;
	}
	else {
		return false;
	}
}

bool operator!=(RatNum const & a, RatNum const & b) {
	if (a == b) {
		return false;
	}
	else {
		return true;
	}
}