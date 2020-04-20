#include <iostream>
#include "PersonFactory.h";

#pragma once
class ConsoleOutput
{
	PersonFactory* pf;
public:
	void ShowInstructions() {
		std::cout << "\n\nCommands" << "\n" << "'edit' lets you edit a person\n" << "'remove #' lets you remove person with id #\n" << "'add' gives you a screen to make a custom person\n\n";
	}

	void ShowAddInstructions() {
		std::cout << "To add a person use the following setup ('name' 'age' isMale(true or false) isMarried(true or false) hasJob(true or false))\n";
	}

	void ShowEditInstructions() {
		std::cout << "To edit a person use the following setup ('ID' 'name' 'age' isMale(true or false) isMarried(true or false) hasJob(true or false))\n";
	}

	void ListPeople(PersonFactory* pp = NULL) {
		if (pp != NULL) {
			pf = pp;
		}
		system("CLS");
		int id = 0;
		for (Person i : pf->People) {
			std::cout << id << ": " << i.name << ": " << pf->getGender(i);
			std::cout << " | " << "Age: " << i.age;
			std::cout << " | ismarried: " << pf->getMarriedstatus(i);
			std::cout << " | Hasjob: " << pf->getJob(i);
			std::cout << "\n";
			id++;
		}
		ShowInstructions();
	}

private:

};

