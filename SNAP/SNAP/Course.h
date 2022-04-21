#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>

using namespace std;

class Course {
public:
	Course();
	~Course() = default;
	virtual string toString() const = 0;
	friend ostream& operator<<(ostream& os, const Course& me) {
		os << me.toString();
		return os;
	}
	string getCourse() const;
protected:
	string course;
};
#endif