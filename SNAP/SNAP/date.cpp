#include "date.h"

#include <string>

using namespace std;

Date::Date() {
	day = "Monday";
	hour = "0:00";
}
Date::Date(string course, string day, string hour) {
	this->course = course;
	this->day = day;
	this->hour = hour;
}
string Date::toString() const {
	return "cdh(" + course + "," + day + "," + hour + ")";
}
string Date::getDay() const {
	return day;
}
string Date::getHour() const {
	return hour;
}
//updates day (used to turn T, Th to TTh)
void Date::setDay(string newDay) {
	day = newDay;
}