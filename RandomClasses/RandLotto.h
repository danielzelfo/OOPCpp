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


RandLotto::RandLotto() {
	set = false;
	setRand();
	set = true;
}

void RandLotto::setRand() {
	if(!set)
		srand(time(0));
	//generting 5 numbers from 1 to 4
	for (int i = 0; i < 5; ++i)
		numbers[i] = rand() % 47 + 1;

	//generatin 1 number from 1 to 27
	numbers[5] = rand() % 27 + 1;
}

void RandLotto::print() {
	for (int i = 0; i < 6; ++i)
		cout << numbers[i] << " ";
}

bool RandLotto::operator == (const RandLotto& other) {
	for (int i = 0; i < 5; ++i)
		if (numbers[i] != other.numbers[i])
			return false;
	return true;
}




//#endif