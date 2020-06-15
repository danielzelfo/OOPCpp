// Fig. 9.1:
#include <string>
#include <iomanip> // for setw and setfill stream manipulators
#include <stdexcept> // for invalid_argument exception class
#include <sstream> // for ostringstream class


// prevent multiple inclusions of header
// Time class definition

#ifndef TIME_H
#define TIME_H
class Time {
public:
	void setTime(int, int, int); // set hour, minute and second
	std::string toUniversalString() const; // 24-hour time format string
	std::string toStandardString() const; // 12-hour time format string
private:
	unsigned int hour{ 0 }; // 0 - 23 (24-hour clock format)
	unsigned int minute{ 0 }; // 0 - 59
	unsigned int second{ 0 }; // 0 - 59
};


using namespace std;
// set new Time value using universal time
void Time::setTime(int h, int m, int s) {
	// validate hour, minute and second
	if ((h >= 0 && h < 24) && (m >= 0 && m < 60) && (s >= 0 && s < 60)) {
		hour = h;
		minute = m;
		second = s;
	}
	else {
		throw invalid_argument(
			"hour, minute and/or second was out of range");
	}
}
// return Time as a string in universal-time format (HH:MM:SS)
string Time::toUniversalString() const {
	ostringstream output;

	output << setfill('0') << setw(2) << hour << ":"
		<< setw(2) << minute << ":" << setw(2) << second;
	return output.str();
}
// return Time as string in standard-time format (HH:MM:SS AM or PM)
string Time::toStandardString() const {
	ostringstream output;
	output << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
		<< setfill('0') << setw(2) << minute << ":" << setw(2)
		<< second << (hour < 12 ? " AM" : " PM");
	return output.str();
}


#endif