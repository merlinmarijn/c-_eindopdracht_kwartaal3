// Person Database.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PersonFactory.h";
#include "ConsoleInput.h";
#include "ConsoleOutput.h";

PersonFactory* pf = new PersonFactory();
ConsoleInput* CI = new ConsoleInput();
ConsoleOutput* CO = new ConsoleOutput();


void main()
{
	pf->Generate_People(100);
	CO->ListPeople(pf);
	CI->GetInput(pf, CO);
}