#include "RandStr.h"

RandStr::RandStr() {
	setRand();
}

//generates a random ascii value that is a printable character
// random number from 32-127
int RandStr::randAscPrintable() {
	return (32 + rand() % 94);
}

void RandStr::setRand() {
	srand(time(0));
	str = "";
	//generating a random size from 1 - 256
	int size = rand() % 256 + 1;

	//generating all the random characters
	for (int i = 0; i < size; ++i)
		str += static_cast<char>(randAscPrintable());
}

void RandStr::print() {
	cout << str;
}