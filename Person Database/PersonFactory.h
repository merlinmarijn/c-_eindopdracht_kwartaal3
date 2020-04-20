#pragma once
#include <iostream>
#include <vector>
#include "Person.h"
#include <string>

class PersonFactory
{

public:
	std::vector<Person> People;
	void Generate_People(int count) {
	for (int i = 0; i < count; i++) {
		person = Person();
		person.Generate_Random_person();
		People.push_back(person);
	}
	}
	void AddPerson(std::string Pname, int Page, std::string PisMale, std::string PisMarried, std::string PhasJob) {
		person.SetPerson(Pname, Page, PisMale, PisMarried, PhasJob);
		People.push_back(person);
	}
	std::string getGender(Person p) {
		if (p.isMale == 0) {
			return "Female";
		}
		else {
			return "Male";
		}
	}
	std::string getJob(Person p) {
		if (p.hasJob == 0) {
			return "false";
		}
		else {
			return "true";
		}
	}
	std::string getMarriedstatus(Person p) {
		if (p.isMarried == 0) {
			return "false";
		}
		else {
			return "true";
		}
	}

	void EditPerson(int ID,std::string Pname, int Page, std::string PisMale, std::string PisMarried, std::string PhasJob) {
		person.SetPerson(Pname, Page, PisMale, PisMarried, PhasJob);
		People.at(ID) = person;
	}

	void DeletePerson(int i) {
		People.erase(People.begin()+i);
	}
private:
	Person person;

};

