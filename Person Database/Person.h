#pragma once
#include <string>
#include <fstream>
#include <vector>
class Person
{
public:
	std::string name;
	int age;
	bool isMale;
	bool isMarried;
	bool hasJob;

	std::vector<std::string> maleNameList;
	std::vector<std::string> femaleNameList;

	void Generate_Random_person() {
		std::ifstream malefile("malenames.txt");
		std::ifstream femalefile("femalenames.txt");
		for (std::string line; std::getline(malefile, line);) {
			maleNameList.push_back(line);
		}
		for (std::string line; std::getline(femalefile, line);) {
			femaleNameList.push_back(line);
		}
		name = "RandomPerson";
		age = rand()%80+1;
		isMale = ChanceCheck(50);
		getNamebyGender();
		if (age > 25) {
			isMarried = ChanceCheck(40);
			hasJob = ChanceCheck(80);
		}
	}
	bool ChanceCheck(int chance) {
		if (rand() % 100 + 1 < chance) {
			return (true);
		}
		else { return false; }
	}
	void SetPerson(std::string Pname, int Page, std::string PisMale, std::string PisMarried, std::string PhasJob) {
		name = Pname;
		age = Page;
		if (PisMale == "true"){isMale=1;}else{isMale = 0;}
		if (PisMarried == "true") { isMarried = 1; }else { isMarried = 0; }
		if (PhasJob == "true") { hasJob = 1; }else { hasJob = 0; }
	}

	void getNamebyGender() {
		if (isMale) {
			name = maleNameList.at(rand() % maleNameList.size());
		}
		else {
			name = femaleNameList.at(rand() % maleNameList.size());
		}
	}
};

