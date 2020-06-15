

#include <random>
#include <time.h>
#include <iostream>
using namespace std;

#ifndef RANDGEN_H
#define RANDGEN_H

class RandGen {
protected:
	virtual void setRand() = 0;


public:
	virtual void print() = 0;
	void generate() { setRand(); }

};

#endif