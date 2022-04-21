#include "room.h"

#include <string>

using namespace std;

Room::Room() {
	course = "none";
	room = "0";
}
Room::Room(string course, string room) {
	this->course = course;
	this->room = room;
}
string Room::toString() const {
	return "cr(" + course + "," + room + ")";
}
string Room::getRoom() const {
	return room;
}