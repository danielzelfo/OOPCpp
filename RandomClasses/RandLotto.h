//#ifndef RandLotto_h
//#define RandLotto_h

#include "RandGen.h"

//the random lottery number class
class RandLotto : public RandGen {
private:
	//5 number 1-47 and 1 number 1-27
	int numbers[6];
	bool set;
  
protected:
  void setRand();
public:
	RandLotto();
	void print();
	bool operator == (const RandLotto&);
};
//#endif