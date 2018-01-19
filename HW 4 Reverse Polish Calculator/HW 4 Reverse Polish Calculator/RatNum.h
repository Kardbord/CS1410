//Tanner Kvarfordt
//A02052217

//Header file for the RatNum class which will allow for the creation of rational numbers or fractions

#ifndef RATNUM_H
#define RATNUM_H

#include<iostream>

class RatNum {
private:
	int numerator, denominator;

	//Receives an int, sets numerator, returns nothing
	void setNumerator(int);

	//Receives an int, sets denominator if valid, returns nothing
	void setDenominator(int);
public:
	//Constructor: sets numerator and denominator to the values sent if they are valid
	RatNum(int = 1, int = 1);

	//Receives 2 ints, sets numerator then denominator, returns nothing
	void resetRatNum(int = 1, int = 1);

	//Receives nothing, returns numerator
	int getNumerator() const { return numerator; }

	//Receives nothing, returns denominator
	int getDenominator() const { return denominator; }

	//+= operator overload
	RatNum operator+=(RatNum const &);

	//-= operator overload
	RatNum operator-=(RatNum const &);

	//*= operator overload
	RatNum operator*=(RatNum const &);

	// /= overload
	RatNum operator/=(RatNum const &);

	//Simplifies the RatNum that calls this function
	void simplify();

	//Overloaded type to cast RatNum to a double
	operator double();

	//Overloaded type to cast RatNum to a float
	operator float();

};

// + operator overload
RatNum operator+(RatNum, RatNum const &);

// - operator overload
RatNum operator-(RatNum, RatNum const &);

// * operator overload
RatNum operator*(RatNum, RatNum const &);

// / operator overload
RatNum operator/(RatNum, RatNum const &);

//Receives two ints, finds greatest common denominator, returns GCD
int EuclidGCD(int, int);

//Overloaded extraction operator to allow for printing RatNums to screen
std::ostream & operator<<(std::ostream &, RatNum const &); //std::ostream & is the return type: we are returning an ostream reference

//Overloaded insertion operator to allow for using cin with RatNum
std::istream & operator>>(std::istream &, RatNum &);

//Overloaded < operator for comparisons of RatNums
bool operator<(RatNum const &, RatNum const &);

//Overloaded == operator for comparisons of RatNums
bool operator==(RatNum const &, RatNum const &);

//Overloaded > operator
bool operator>(RatNum const &, RatNum const &);

//Overloaded <= operator
bool operator<=(RatNum const &, RatNum const &);

//Overloaded >= operator
bool operator>=(RatNum const &, RatNum const &);

//Overloaded != operator
bool operator!=(RatNum const &, RatNum const &);

#endif