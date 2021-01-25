#include "RandGen.hpp"
#include <string>

#ifndef RANDSTRING_H
#define RANDSTRING_H


//the random string abstract class
class RandString : public RandGen {
protected:
	string str;
	void setRand() = 0;
  
public:
	void print() = 0;
};

#endif