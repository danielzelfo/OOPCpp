#include "RandString.h"

//the random string class
class RandStr : public RandString {

protected:
  void setRand();

public:
	RandStr();
	
	//generates a random ascii value that is a printable character
	int randAscPrintable();
	void print();
};