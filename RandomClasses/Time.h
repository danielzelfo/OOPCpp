// Fig. 9.1:
#include <string>
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

#endif