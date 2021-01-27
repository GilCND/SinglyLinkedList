#ifndef LIST_H
#define LIST_H
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

class List {
private:
	struct node {
		int data;
		node* next;
	};
	typedef struct node* nPointer; //going to allow me to type nPointer instead of struct node*...
	nPointer head;
	nPointer current;
	nPointer temp;
	nPointer tail;

public: //functions
	List();
	~List();
	//Add on the front
	void AddBg(int add);
	//Add to an end
	void Append(int add);
	//Add to a specifit position
	void SpecificAdd(int pos, int data);
	//Delete by data
	void DeleteNode(int del);
	//Delete by poosition
	void SpecificDel(int pos);
	//search specific
	void Search(int search);
	//Display function
	void Display();
};
#endif //LIST_H