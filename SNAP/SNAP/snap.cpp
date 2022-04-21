#include "snap.h"

#include <string>
#include <sstream>

using namespace std;

Snap::Snap() {
	name = "none";
	address = "no where";
	phone = "000-0000";
}
Snap::Snap(string studID, string name, string address, string phone) {
	this->studID = studID;
	this->name = name;
	this->address = address;
	this->phone = phone;
}
string Snap::toString() const {
	stringstream out;
	out << "snap(" << studID << "," << name << "," << address << "," << phone << ")";
	return out.str();
}
string Snap::getName() const {
	return name;
}
string Snap::getAddress() const {
	return address;
}
string Snap::getPhone() const {
	return phone;
}