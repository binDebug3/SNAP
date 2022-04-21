#include "snap.h"
#include "grade.h"
#include "date.h"
#include "room.h"
#include "Student.h"
#include "Course.h"

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

using namespace std;

string studentIDtoName(string studentID, const vector<Snap>& snap);

int main(int argc, char* argv[]) {
	VS_MEM_CHECK
	
		//open files
	if (argc < 3){
		cerr << "Please provide name of input and output files";
		return 1;
	}
	ifstream in(argv[1]);
	if (!in.is_open()) {
		cout << "Uh oh there was an inputFile error..." << endl;
		return 2;
	}
	ofstream out(argv[2]);
	if (!out.is_open()) {
		cout << "Uh oh there was an outputFile error..." << endl;
		return 3;
	}

	vector<Snap> snap;
	vector<Grade> csg;
	vector<Date> cdh;
	vector<Room> cr;

	out << "Input Strings:" << endl;
	while (!in.eof()) {
		string nextLine;
		getline(in, nextLine);

		//parse one line of input
		vector<int> numInfo;
		vector<string> infoList;
		int abbrIndex = nextLine.find("(");
		if (abbrIndex == -1) {
			abbrIndex = nextLine.size();
		}
		string inputType;
		try {
			inputType = nextLine.substr(0, abbrIndex);
		}
		catch (...) {
			out << "**Error: " << nextLine << endl;
		}
		if (inputType != "snap" && inputType != "csg" && inputType != "cdh" && inputType != "cr") { 
			out << "**Error: " << nextLine << endl;
		}
		else {
			out << nextLine << endl;
			numInfo.push_back(abbrIndex);
			for (unsigned int index = 0; index < nextLine.size(); index++) {
				if (nextLine.at(index) == ',') {
					numInfo.push_back(index);
				}
			}
			numInfo.push_back(nextLine.find(")"));
			for (unsigned int i = 0; i < numInfo.size() - 1; i++) {
				int first = numInfo.at(i) + 1;
				int second = numInfo.at(i + 1);
				int length = second - first;
				infoList.push_back(nextLine.substr(first, length));
			}
			string infoType = nextLine.substr(0, abbrIndex);

			//add parsed information to appropriate list
			if (infoType == "snap") {
				snap.push_back(Snap(infoList.at(0), infoList.at(1), infoList.at(2), infoList.at(3)));
			}
			else if (infoType == "csg") {
				csg.push_back(Grade(infoList.at(0), infoList.at(1), infoList.at(2)));
			}
			else if (infoType == "cdh") {
				cdh.push_back(Date(infoList.at(0), infoList.at(1), infoList.at(2)));
			}
			else if (infoType == "cr") {
				cr.push_back(Room(infoList.at(0), infoList.at(1)));
			}
			else {
				cout << "Reading input file error" << endl;
			}
		}
	}

	//print information in each vector
	out << endl << "Vectors:" << endl;
	for (unsigned int i = 0; i < snap.size(); i++) {
		out << snap[i] << endl;
	}
	for (unsigned int i = 0; i < csg.size(); i++) {
		out << csg[i] << endl;
	}
	for (unsigned int i = 0; i < cdh.size(); i++) {
		out << cdh[i] << endl;
	}
	for (unsigned int i = 0; i < cr.size(); i++) {
		out << cr[i] << endl;
	}

	//format and print course grades
	out << endl << "Course Grades:" << endl;
	for (unsigned int i = 0; i < csg.size(); i++) {
		out << csg[i].getCourse() << "," << studentIDtoName(csg[i].getStudID(), snap) << "," << csg[i].getGrade() << endl;
		if (i < csg.size() - 1 && (csg[i].getCourse() != csg[i + 1].getCourse())) {
			out << endl;
		}
	}

	//reformat the cdh vector to make it easier to use (combining duplicate classes)
	for (int i = 0; i < cdh.size() - 1; i++) {
		if (cdh.size() > 0 && cdh[i].getCourse() == cdh[i + 1].getCourse()) {
			string combinedDay = cdh[i].getDay() + cdh[i + 1].getDay();
			cdh[i].setDay(combinedDay);
			//delete cdh[i + 1];
			cdh.erase(cdh.begin() + i + 1);
			i--;
		}
	}

	//print student schedules
	out << endl << "Student Schedules:" << endl;
	for (unsigned int i = 0; i < snap.size(); i++) {
		out << snap[i].getName() << ", " << snap[i].getStudID() << ", " << snap[i].getAddress() << ", " << snap[i].getPhone() << endl;
		for (unsigned int n = 0; n < csg.size(); n++) {
			if (snap[i].getStudID() == csg[n].getStudID()) {
				for (unsigned int k = 0; k < cdh.size(); k++) {
					if (csg[n].getCourse() == cdh[k].getCourse()) {
						for (unsigned int j = 0; j < cr.size(); j++) {
							if (cr[j].getCourse() == csg[n].getCourse()) {
								out << "\t" << csg[n].getCourse() << " " << cdh[k].getDay() << " " << cdh[k].getHour() << ", " << cr[j].getRoom() << endl;
							}
						}
					}
				}
			}
		}
		out << endl;
	}

	//remove memory leaks
	/*while (snap.size() > 0) {
		delete snap.at(0);
		snap.erase(snap.begin());
	}
	while (csg.size() > 0) {
		delete csg.at(0);
		csg.erase(csg.begin());
	}
	while (cdh.size() > 0) {
		delete cdh.at(0);
		cdh.erase(cdh.begin());
	}
	while (cr.size() > 0) {
		delete cr.at(0);
		cr.erase(cr.begin());
	}*/

	return 0;
}

//convert a given student ID number to its corresponding name
string studentIDtoName(string studentID, const vector<Snap>& snap) {
	for (unsigned int i = 0; i < snap.size(); i++) {
		if (studentID == snap[i].getStudID()) {
			return snap[i].getName();
		}
	}
	return "oof";
}