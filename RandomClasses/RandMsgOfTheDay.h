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

RandMsgOfTheDay::RandMsgOfTheDay() {
	setRand();
}

void RandMsgOfTheDay::setRand() {
	srand(time(0));

	//generating a random line number for the messages text file from 1 to 100
	int randLine = rand() % 100 + 1;

	//setting the random message to the randLine line of the file message.txt, which is a list of messages
	str = ReadNthLine("RandomClasses/messages.txt", randLine);
}


//function to get the nth line of a file
string RandMsgOfTheDay::ReadNthLine(const string& filename, int N) {
	ifstream in(filename.c_str());

	string s;
	//for performance
	s.reserve(100);

	//skip N lines
	for (int i = 0; i < N; ++i)
		getline(in, s);

	getline(in, s);
	return s;
}

void RandMsgOfTheDay::print() {
	cout << str;
}