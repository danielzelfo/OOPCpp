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
#include <string>

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





// initialize static member; one classwide copy
const array<unsigned int, 13> Date::days
{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// Date constructor
Date::Date(int month, int day, int year) {
	setDate(month, day, year);
}

// set month, day and year
void Date::setDate(int mm, int dd, int yy) {
	if (mm >= 1 && mm <= 12) {
		month = mm;
	}
	else {
		throw invalid_argument{ "Month must be 1-12" };
	}
	if (yy >= 1900 && yy <= 2100) {
		year = yy;
	}
	else {
		throw invalid_argument{ "Year must be >= 1900 and <= 2100" };
	}
	// test for a leap year
	if ((mm == 2 && leapYear(year) && dd >= 1 && dd <= 29) || (dd >= 1 && dd <= days[mm]))
	{
		day = dd;
	}
	else {
		throw invalid_argument{
			"Day is out of range for current month and year" };
	}
}
// overloaded prefix increment operator
Date& Date::operator++() {
	helpIncrement(); // increment date
	return *this; // reference return to create an lvalue
}
// overloaded postfix increment operator; note that the
// dummy integer parameter does not have a parameter name
Date Date::operator++(int) {
	Date temp{ *this }; // hold current state of object
	helpIncrement();
	// return unincremented, saved, temporary object
	return temp; // value return; not a reference return
}
// add specified number of days to date
Date& Date::operator+=(unsigned int additionalDays) {
	for (unsigned int i = 0; i < additionalDays; ++i) {
		helpIncrement();
	}
	return *this; // enables cascading
}
// overloaded prefix increment operator
Date& Date::operator--() {
	helpDecrement(); // decrement date
	return *this; // reference return to create an lvalue
}
// overloaded postfix frcrement operator; note that the
// dummy integer parameter does not have a parameter name
Date Date::operator--(int) {
	Date temp{ *this }; // hold current state of object
	helpDecrement();
	// return undecremented, saved, temporary object
	return temp; // value return; not a reference return
}
// add specified number of days to date
Date& Date::operator-=(unsigned int additionalDays) {
	for (unsigned int i = 0; i < additionalDays; ++i) {
		helpDecrement();
	}
	return *this; // enables cascading
}
// if the year is a leap year, return true; otherwise, return false
bool Date::leapYear(int testYear) {
	return (testYear % 400 == 0 ||
		(testYear % 100 != 0 && testYear % 4 == 0));
}

// determine whether the day is the last day of the month
bool Date::endOfMonth(int testDay) const {
	if (month == 2 && leapYear(year)) {
		return testDay == 29; // last day of Feb. in leap year
	}
	else {
		return testDay == days[month];
	}
}
bool Date::firstOfMonth(int testDay) const {
	return testDay == 1;
}
void Date::helpIncrement() {
	// day is not end of month
	if (!endOfMonth(day)) {
		++day; // increment day
	}
	else {
		if (month < 12) { // day is end of month and month < 12
			++month; // increment month
			day = 1; // first day of new month
		}
		else { // last day of year
			++year; // increment year
			month = 1; // first month of new year
			day = 1; // first day of new month
		}
	}
}
// function to help decrement the date
void Date::helpDecrement() {
	// day is not end of month
	if (!firstOfMonth(day)) {
		--day;// decrement day
	}
	else {
		if (month > 1) {
			// day is last day of month and month < 12
			--month; // decrement month
			day = days[month]; // last day of previous month
			if (leapYear(year) && month == 2)
				++day;
		}
		else {
			// first day of year
			--year; // decrement year
			month = 12; // last month of previous year
			day = days[month]; // last day of new month
		}
	}
}

bool Date::operator>(const Date& g) const
{
	return (year > g.year) ||
		(year > g.year && month > g.month) ||
		(year > g.year && month > g.month && day > g.day) ? true : false;
}

bool Date::operator <(const Date& g) const
{
	return (year < g.year) ||
		(year < g.year && month < g.month) ||
		(year < g.year && month < g.month && day < g.day) ? true : false;
}
// overloaded output operator
ostream& operator<<(ostream& output, const Date& d)
{
	static string monthName[13]{ "", "January", "February",
		"March", "April", "May", "June", "July", "August",
		"September", "October", "November", "December" };
	output << monthName[d.month] << ' ' << d.day << ", " << d.year;
	return output;
}

bool Date::operator==(const Date& g) const {
	return day == g.day && month == g.month && year == g.year;
}

int Date::getMonth() const {
	return month;
}
int Date::getDay() const {
	return day;
}
int Date::getYear() const {
	return year;
}
void Date::setYear( int yr ) {
	year = yr;
}



#endif