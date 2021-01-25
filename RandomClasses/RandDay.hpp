//#ifndef RandDay_h
//#define RandDay_h

#include "RandGen.hpp"
#include "Date.hpp"
#include <string>
//the random day class


class RandDay : public RandGen {
private:
	Date date;
	//boolean to check is srand was set
	bool set;
	//boolean for if we need to generate a random year
	bool randYr;
	

protected:
  void setRand();
  
public:
	RandDay();

	//constructor with year
	RandDay(int yr);
	void print();

	//a toString function
	std::string toString();


	//overload equality operator
	bool operator == (const RandDay&) const;
};





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






//#endif