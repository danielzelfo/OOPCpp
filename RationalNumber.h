#include <iostream>
using namespace std;

class RationalNumber {
public:
	//default constructor and constructor with numerator and denominator
	RationalNumber(int = 0, int = 1);

	//assignment operator overloaded
	void operator = (RationalNumber const &);

	//arithmatic operators overloaded
	RationalNumber operator + (RationalNumber const &) const;
	RationalNumber operator - (RationalNumber const &) const;
	RationalNumber operator * (RationalNumber const &) const;
	RationalNumber operator / (RationalNumber const &) const;

	//logical operators overloaded
	bool operator > (RationalNumber const &) const;
	bool operator < (RationalNumber const &) const;
	bool operator >= (RationalNumber const &) const;
	bool operator <= (RationalNumber const &) const;
	bool operator == (RationalNumber const &) const;
	bool operator != (RationalNumber const &) const;

	// display rational number 
	void printRational() const; 
//private:
	int numerator; // private variable numerator
	int denominator; // private variable denominator
	void reduction(); // function for fraction reduction 
};