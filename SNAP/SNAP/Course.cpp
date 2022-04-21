#include "Course.h"

#include <string>

using namespace std;

Course::Course() {
	course = "none";
}
string Course::getCourse() const {
	return course;
}