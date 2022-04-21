#ifndef DATE_H
#define DATE_H

#include "Course.h"

#include <string>

using std::string;

class Date : public Course {
public:
	Date();
	Date(string course, string day, string hour);
	~Date() = default;
	string toString() const;
	friend ostream& operator<<(ostream& os, const Date& me) {
		os << me.toString();
		return os;
	}
	string getDay() const;
	string getHour() const;
	void setDay(string newDay);
	//string getCourse();
private:
	string day;
	string hour;
	//string course;
};
#endif