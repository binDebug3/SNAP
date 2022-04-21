#ifndef SNAP_H
#define SNAP_H

#include "Student.h"

#include <string>

using namespace std;

class Snap : public Student {
public:
	Snap();
	Snap(string studID, string name, string address, string phone);
	~Snap() = default;
	string toString() const;
	friend ostream& operator<<(ostream& os, const Snap& me) {
		os << me.toString();
		return os;
	}
	string getName() const;
	string getAddress() const;
	string getPhone() const;
	//int getStudID();
private:
	string name;
	string address;
	string phone;
	//int studID;

};
#endif