#include "RandDay.h"


RandDay::RandDay() {
	set = false;
	setRand();
	set = true;
	randYr = true;
}

RandDay::RandDay(int y) {
	set = false;
	setRand();
	set = true;
	date.setYear(y);
	randYr = false;
}


void RandDay::setRand() {
	int year = date.getYear();
	if(!set)
		srand(time(0));

	//random month and year
	int month = rand() % 12 + 1;

	if(randYr)
		year = rand() % 200 + 1900;

	//generating a random day and considering the leap year
	int day = rand() % (month == 2 && Date::leapYear(year) ? 29 : Date::days[month]) + 1;
	date.setDate(month, day, year);
}

void RandDay::print() {
	cout << date;
}

bool RandDay::operator == (const RandDay& other) const{
	return date == other.date;
}


string RandDay::toString() {
	return (to_string(date.getMonth()) + '/' + to_string(date.getDay()) +  '/' + to_string(date.getYear()));


}