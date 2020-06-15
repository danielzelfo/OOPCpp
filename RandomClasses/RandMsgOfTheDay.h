#include "RandString.h"
#include <fstream>

//the random message class
class RandMsgOfTheDay : public RandString {

protected:
  void setRand();
public:
	RandMsgOfTheDay();
	
	string ReadNthLine(const string& filename, int N);
	void print();
};