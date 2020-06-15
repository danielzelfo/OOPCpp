//#3 Date class.h

/*
This program uses overloaded prefix and postfix increment operators to minus 1 to the day in a Date object
The program also define the overloaded relational operators < and >.
*/

/*
Author: Xin Geng
created by 11/17/2019

input:d1,d2,d3
output: prefix decrement, postfix decrement, relation of days.
implementation:
leap year:
1.The year can be evenly divided by 4;
2.If the year can be evenly divided by 100, it is NOT a leap year, unless;
3.The year is also evenly divisible by 400. Then it is a leap year.
*/

// Fig. 10.6: Date.h
// Date class definition with overloaded increment operators.

#ifndef DATE_H
#define DATE_H
#include <array>
#include <iostream>

class Date {
	friend std::ostream& operator<<(std::ostream&, const Date&);
public:
	Date(int m = 1, int d = 1, int y = 1900); // default constructor

	void setDate(int, int, int); // set month, day, year
	Date& operator++();//prefix increment operator
	Date operator++(int);//postfix increment operatpr
	Date& operator+=(unsigned int);//add days, modifiy object

	Date& operator--(); // prefix decrement operator
	Date operator--(int); // postfix decrement operator
	Date& operator-=(unsigned int); // minus days, modify object

	static bool leapYear(int); // is year a leap year?
	bool endOfMonth(int) const; // is day at the end of month?
	bool firstOfMonth(int) const; // is day at the first of month?
	bool operator > (const Date&) const;
	bool operator < (const Date&) const;
	bool operator == (const Date&) const;

	static const std::array<unsigned int, 13> days; // days per month

	int getMonth() const;
	int getDay() const;
	int getYear() const;
	void setYear(int);
private:
	unsigned int month;
	unsigned int day;
	unsigned int year;

	void helpIncrement();
	void helpDecrement(); // utility function for decrementing date
};
#endif