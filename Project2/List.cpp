#include <iostream>
#include <cstdlib>
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

List::List()
{
	head = NULL;
	current = NULL;
	tail = NULL;
};

List::~List()
{
	//Free all nodes
}

//add node to the end of the list
void List::Append(int add) //add on the end of the list
{
	nPointer n = new node;
	n->next = NULL;
	n->data = add;

	if (head != NULL) 
	{
		current = head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = n;
	}
	else {
		head = n;
	}
}
//add node at the beggining of the list
void List::AddBg(int add) //add on the end of the list
{
	nPointer n = new node;
	n->next = NULL;
	n->data = add;

	if (head != NULL)
	{
		n->next = head;
		head = n;
	}
	else {
		//If we dont have a node yet, create one and make it the head and the tail
		head = n;
		tail = n;
	}
}

//delete specific node by data

void List::DeleteNode(int del) 
{
	nPointer delPointer = NULL;
	temp = head;
	current = head;
	while (current != NULL && current->data != del)
	{
		temp = current;
		current = current->next;
	}
	if (current == NULL)
	{
		cout << del << "Not found\n" << endl; 
		delete delPointer;
	}
	else
	{
		if (current == head)
		{
			current = current->next;
			head = current;
		}
		else
		{
			delPointer = current;
			current = current->next;
			temp->next = current;
			delete delPointer;
			cout << "The value: " << del << " Was Deleted\n";
		}
	}
}
//Delete specific node by position
void List::SpecificDel(int pos)
{
	int counter = 0;
	nPointer delSpecific = NULL;
	temp = head;
	current = head;
	if (pos == 0)
	{
		if (current->next == NULL)
		{
			head = NULL;
		}
		if (current->next != NULL)
		{
			current = current->next;
			head = current;
		}		
	}
	else
	{
		while (counter != pos)
		{
			temp = current;
			current = current->next;
			counter++;
		}
		if (current == NULL)
		{
			cout << pos << "Not found\n" << endl;
			delete delSpecific;
		}
		else
		{
			delSpecific = current;
			current = current->next;
			temp->next = current;
			cout << "The node on the position: " << pos << " has been Deleted\n";
		}
	}
}
// Add specific node at the position
void List::SpecificAdd(int pos, int data)
{
	int counter = 0;
	nPointer n = new node;
	n->next = NULL;
	n->data = data;

	temp = head;
	current = head;

	if (pos == 0)
	{
		if (current->next == NULL)
		{
			head = n;
			tail = n;
		}
		if (current->next != NULL)
		{
			n->next = head;
			head = n;
		}
	}
	else
	{
		while (counter != pos)
		{
			temp = current;
			current = current->next;
			counter++;
		}
		if (current == NULL)
		{
			cout << pos << "Not found\n" << endl;
		}
		else
		{
			temp->next = n;
			n->next = current;
		}		
	}
}

//Search for a specific data displaying the position of the item and its value
void List::Search(int search)
{
	int counter = 0;
	nPointer ptrSearch = NULL;
	temp = head;
	current = head;
	while (current != NULL && current->data != search)
	{
		temp = current;
		current = current->next;
		counter++;
	}
	if (current == NULL)
	{
		cout << search << "Not found\n" << endl;
		delete ptrSearch;
	}
	else
	{
		cout << "The value " << search << " was found at the position: " << counter << " The data is: " << current->data << endl;
		delete ptrSearch;
	}
}

//Display elements
void List::Display() 
{
	if (head != NULL)
	{
		current = head;
		while (current != NULL)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}
	else
	{
		cout << "No Elements";
	}
}
