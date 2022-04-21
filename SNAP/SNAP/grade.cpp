#include "grade.h"

#include <string>

Grade::Grade() {
	studID = "0";
	course = "none";
	grade = "F";
}
Grade::Grade(string course, string studID, string grade) {
	this->course = course;
	this->studID = studID;
	this->grade = grade;
}
string Grade::getGrade() const {
	return grade;
}
string Grade::toString() const {
	return "csg(" + course + "," + studID + "," + grade + ")";
}
string Grade::getCourse() const {
	return Course::getCourse();
}