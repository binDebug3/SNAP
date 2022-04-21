#ifndef GRADE_H
#define GRADE_H

#include "Student.h"
#include "Course.h"

#include <string>

using namespace std;

class Grade : public Student, Course {
public:
	Grade();
	Grade(string course, string studID, string grade);
	~Grade() = default;
	string toString() const;
	friend ostream& operator<<(ostream& os, const Grade& me) {
		os << me.toString();
		return os;
	}
	string getCourse() const;
	string getGrade() const;
	//int getStudID();
private:
	//string course;
	//string studID;
	string grade;
};
#endif