#include "RandGen.h"
#include "Time.h"

//the random time class
class RandTime : public RandGen {
private:
	Time theTime;
protected:
  void setRand();
public:
	RandTime();
	
	void print();
};

RandTime::RandTime() {
	setRand();
}

void RandTime::setRand() {
	srand(time(0));

	// random hour, minute, and second in 24-hour
	int hour = rand() % 25;
	int minute = rand() % 61;
	int second = rand() % 61;
	theTime.setTime(hour, minute, second);
}

void RandTime::print() {
	cout << theTime.toStandardString();
}