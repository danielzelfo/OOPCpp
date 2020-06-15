#include <iostream>
#include <string>
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


//constructor
RationalNumber::RationalNumber(int num, int den) {
	//throwing the dividing by zero exception if needed
	if (den == 0)
		throw string("Math Error: dividing by 0 in " + to_string(num) + "/" + to_string(den));

	

	//setting the data
	numerator = num;
	denominator = den;

	//reducing
	reduction();
}

//setter using the overloaded assignment operator
void RationalNumber::operator = (RationalNumber const &obj) {
	numerator = obj.numerator;
	denominator = obj.denominator;
}

//the overoaded addition operator
RationalNumber RationalNumber::operator + (RationalNumber const &obj) const{
	RationalNumber res;
	res.numerator = numerator*obj.denominator + obj.numerator*denominator;
	res.denominator = denominator * obj.denominator;
	res.reduction();
	return res;
}

//the overloaded subtraction operator
RationalNumber RationalNumber::operator - (RationalNumber const &obj) const {
	RationalNumber res;
	res.numerator = numerator * obj.denominator - obj.numerator*denominator;
	res.denominator = denominator * obj.denominator;
	res.reduction();
	return res;
}

//the overloaded multiplication operator
RationalNumber RationalNumber::operator * (RationalNumber const &obj) const {
	RationalNumber res;
	res.numerator = numerator * obj.numerator;
	res.denominator = denominator * obj.denominator;
	res.reduction();
	return res;
}

//the overloaded division operator
RationalNumber RationalNumber::operator / (RationalNumber const &obj) const {
	RationalNumber res;
	res.numerator = numerator * obj.denominator;
	res.denominator = denominator * obj.numerator;
	res.reduction();
	return res;
}

//the overloaded less than operator
bool RationalNumber::operator < (RationalNumber const &obj) const {
	return ((numerator * obj.denominator) < (obj.numerator * denominator));
}

//the overloaded equality operator
bool RationalNumber::operator == (RationalNumber const &obj) const {
	return (numerator == obj.numerator  && denominator == obj.denominator);
}

//the overloaded less or equal to than operator
bool RationalNumber::operator <= (RationalNumber const &obj) const {
	return *this < obj || *this == obj;
}

//the overloaded greater than operator
bool RationalNumber::operator > (RationalNumber const &obj) const {
	return !(*this <= obj);
}

//the overloaded greater than or equal to operator
bool RationalNumber::operator >= (RationalNumber const &obj) const {
	return !(*this < obj);
}

//the overloaded not equal to operator
bool RationalNumber::operator != (RationalNumber const &obj) const {
	return !(*this == obj);
}

// function printRational definition
void RationalNumber::printRational() const
{
	if (numerator == 0 || denominator == 1) // print fraction as integer
		cout << numerator;
	else
		cout << numerator << '/' << denominator;
} // end function printRational

// function reduction definition
void RationalNumber::reduction()
{
	

	int m, k, r;
	if (abs(numerator) < abs(denominator)) 
		{ m = abs(numerator); k = abs(denominator); } 
	else 
		{ k = abs(numerator); m = abs(denominator); }
	while (m != 0) {
		r = k % m;
		k = m;
		m = r;
	}
	// At this point, GCD(K,M) = GCD(k,m) = GCD(k,0) = k
	numerator /= k;
	denominator /= k;


	//making sure the denominator is not negative
	if (denominator < 0) {
		denominator *= -1;
		numerator *= -1;
	}
} // end function reduction