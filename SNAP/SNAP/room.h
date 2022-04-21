#ifndef ROOM_H
#define ROOM_H

#include "Course.h"

using namespace std;

class Room : public Course {
public:
	Room();
	Room(string course, string room);
	~Room() = default;
	string toString() const;
	friend ostream& operator<<(ostream& os, const Room& me) {
		os << me.toString();
		return os;
	}
	string getRoom() const;
	//string getCourse();
private:
	//string course;
	string room;
};
#endif