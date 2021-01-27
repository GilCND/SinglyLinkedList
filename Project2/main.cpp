#include <cstdlib>
#include <iostream>
#include <fstream>
#include "List.h" 

/*
Programmer: Felipe SG.
Date: 25/01/2021
Details:
Write a C++ program to implement a singly linked list and implement the following functionality:
note, the data type the list stores may be chosen to store a data type of your choosing
(int, decimal, another class, etc….) .
A method to add an element (Front)
A method to append an element (End)
A method to insert an element at a specific position.
A method to remove an element from a specific position.
A method to remove an item based on a supplied value.
A method to search for an item by its value and return the index of that item.
Implement the class destructor which should delete all of the nodes.
Once implemented, create a reference to the new object, add some data from a file and demonstrate the use of each implemented operation.
*/
using namespace std;

int main(int argc, char** argv)
{
	int option, data;
	List First;
	List NotFirst;

	//Load from file
	int singleD[5];
	ifstream file("simpleData.txt");
	if (file.is_open())
	{
		for (int i = 0; i < 5; i++)
		{
			file >> singleD[i];
			NotFirst.Append(singleD[i]);
		}
	}
	file.close();
	First.Append(15);
	First.Append(6);
	First.Append(8);
	First.Append(2);
	First.Append(7);
	First.Display();

	//A method to add an element (Front)
	cout << "---------------------------------------------------------" << endl;
	cout << "Please inform the DATA that you want ADD (FRONT): ";
	cin >> option;
	First.AddBg(option);
	First.Display();
	

	//A method to append an element (End)
	cout << "---------------------------------------------------------" << endl;
	cout << "Please inform the DATA that you want ADD at the END: ";
	cin >> option;
	First.Append(option);
	system("CLS");
	First.Display();

	//A method to insert an element at a specific position.
	cout << "---------------------------------------------------------" << endl;
	cout << "Please inform the Position that you want to ADD:";
	cin >> option;
	cout << "Please inform the number that you want to ADD:";
	cin >> data;
	First.SpecificAdd(option, data);
	First.Display();

	//A method to remove an element from a specific position.
	cout << "---------------------------------------------------------" << endl;
	cout << "Type the POSITION that you want to delete (starting by 0)" << endl;
	cin >> option;
	First.SpecificDel(option);
	cout << "---------------------------------------------------------" << endl;
	First.Display();

	//A method to remove an item based on a supplied value.
	cout << "---------------------------------------------------------" << endl;
	cout << "Please inform the DATA that you want to delete:";
	cin >> option;
	First.DeleteNode(option);
	First.Display();

	//A method to search for an item by its value and return the index of that item.
	cout << "---------------------------------------------------------" << endl;
	cout << "The list below was LOADED FROM FILE\n";
	NotFirst.Display();
	cout << "Please inform the DATA that you want to search: ";
	cin >> option;
	NotFirst.Search(option);
	NotFirst.Display();




	return 0;
}