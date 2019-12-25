//#ifndef RandDay_h
//#define RandDay_h

#include "RandGen.h"
#include "Date.h"
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
//#endif