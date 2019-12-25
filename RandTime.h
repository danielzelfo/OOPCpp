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