// Dictionary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Dictionary.h"

int main()
{
	Dictionary<const char*, int> dictionary;

	dictionary.addItem("First", 10);
	dictionary.addItem("Second", 25);

	int displayValue;

	dictionary.tryGetValue("First", displayValue);
	std::cout << displayValue << std::endl;

	dictionary.tryGetValue("Second", displayValue);
	std::cout << displayValue << std::endl;
	system("pause");
	system("cls");

	dictionary.remove("Second");
	dictionary.addItem("First", 75);
	dictionary.addItem("Second", 75);
	dictionary.addItem("Third", 75);


	dictionary.tryGetValue("First", displayValue);
	std::cout << displayValue << std::endl;

	dictionary.tryGetValue("Second", displayValue);
	std::cout << displayValue << std::endl;

	dictionary.tryGetValue("Third", displayValue);
	std::cout << displayValue << std::endl;
	system("pause");
	system("cls");

	dictionary.clear();

	dictionary.addItem("First", -12);
	dictionary.addItem("Second", 0);
	dictionary.addItem("Third", 12);
	dictionary.addItem("First", 0);


	dictionary.tryGetValue("First", displayValue);
	std::cout << displayValue << std::endl;

	dictionary.tryGetValue("Second", displayValue);
	std::cout << displayValue << std::endl;

	dictionary.remove("Third", displayValue);
	std::cout << displayValue << std::endl;
	system("pause");
	system("cls");

	dictionary.clear();
	displayValue = 0;

	dictionary.tryGetValue("First", displayValue);
	std::cout << displayValue << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
