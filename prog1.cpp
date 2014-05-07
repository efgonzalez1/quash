//============================================================================
// Name        : prog1.cpp
// Author      : Fernando Gonzalez
// Date    	   : April 29, 2014
// Description : Quash implementation using a separate chaining hash table and
//				 a min-heap.  HW1 for CS 130A at UCSB.
//============================================================================

#include <iostream>
#include <string>
#include "Quash.h"
using namespace std;

int main() {
	Quash<int> *q = new Quash<int>(43);

	while (!cin.eof()) {
		string command;
		cin >> command;

		if (command.compare("insert") == 0) {
			int parameter;
			cin >> parameter;
			q->insert(parameter);
		} else if (command.compare("lookup") == 0) {
			int parameter;
			cin >> parameter;
			q->lookup(parameter);
		} else if (command.compare("delete") == 0) {
			int parameter;
			cin >> parameter;
			q->remove(parameter);
		} else if (command.compare("deleteMin") == 0) {
			q->remove_min();
		} else if (command.compare("print") == 0) {
			q->print();
		} else if (cin.eof()) {
			break;
		} else {
			cout << "Invalid input. Try again." << endl;
		}
	}

	return 0;
}
