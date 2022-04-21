#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

using namespace std;

class Student {
public:
	Student();
	~Student() = default;
	virtual string toString() const = 0;
	friend ostream& operator<<(ostream& os, const Student& me) { 
		os << me.toString();
		return os;
	}
	virtual string getStudID() const;
protected:
	string studID;
};
#endif