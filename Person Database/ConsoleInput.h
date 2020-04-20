#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "ConsoleOutput.h";
#include <sstream>
#pragma warning (disable : 4996)
#pragma once
class ConsoleInput
{
	PersonFactory* pf;
public:
	void GetInput(PersonFactory* p, ConsoleOutput* co) {
		pf = p;
		CO = co;
		std::vector<std::string> commando;
		char command[100];
		std::cin.getline(command, 100);
		std::cout << "\n";
		char* point;
		point = strtok(command, " ");
		while (point != NULL) {
			commando.push_back(point);
			point = strtok(NULL, " ");
		}
		for (std::string i : commando) {
			std::cout << i << "\n";
		}
		if (commando.empty()) {} else {
			//Listen to input and start person remove sequence
			if (commando.at(0) == "remove") {
				std::stringstream geek(commando.at(1));
				int x = 0;
				geek >> x;
				system("CLS");
				pf->DeletePerson(x);
				CO->ListPeople();
			}
			//Listen to input and start person edit sequence
			if (commando.at(0) == "edit") {
				CO->ShowEditInstructions();
				std::vector<std::string> editCommando;
				char editcommand[200];
				std::cin.getline(editcommand, 200);
				std::cout << "\n";
				char* point;
				point = strtok(editcommand, " ");
				while (point != NULL) {
					editCommando.push_back(point);
					point = strtok(NULL, " ");
				}
				std::stringstream ID(editCommando.at(0));
				std::stringstream age(editCommando.at(2));
				int x, z = 0;
				age >> x;
				ID >> z;
				pf->EditPerson(z, editCommando.at(1), x, editCommando.at(3), editCommando.at(4), editCommando.at(5));
				CO->ListPeople();
			}
			//Listen to input and start person add sequence
			if (commando.at(0) == "add") {
				CO->ShowAddInstructions();
				std::vector<std::string> addCommando;
				char addcommand[200];
				std::cin.getline(addcommand, 200);
				std::cout << "\n";
				char* point;
				point = strtok(addcommand, " ");
				while (point != NULL) {
					addCommando.push_back(point);
					point = strtok(NULL, " ");
				}
				std::stringstream geek(addCommando.at(1));
				int x = 0;
				geek >> x;
				pf->AddPerson(addCommando.at(0), x, addCommando.at(2), addCommando.at(3), addCommando.at(4));
				CO->ListPeople();
			}
		}
		GetInput(p, co);
	}
private:
	ConsoleOutput* CO;
};

