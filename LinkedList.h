/*
 * LinkedList.h
 *
 *  Created on: Apr 26, 2014
 *      Author: Fernando
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
#include "Node.h"
using namespace std;

template<typename T>
class LinkedList {
public:
	LinkedList();
	~LinkedList();

	Node<T> * find_node(T data_in, bool verbose);
	Node<T> * insert_node(T data_in);
	Node<T> * remove_node(T data_in, bool min);

//	void print();
private:
	Node<T> *head;
	Node<T> *tail;
};

template<typename T>
LinkedList<T>::LinkedList() {
	head = NULL;
	tail = NULL;
}

template<typename T>
LinkedList<T>::~LinkedList() {
	if (head != NULL) {
		Node<T> *current = head;
		while (current != tail) {
			Node<T> *tmp = current;
			current = current->get_next();
			delete[] tmp;
		}
	}
}

template<typename T>
Node<T> * LinkedList<T>::find_node(T data_in, bool verbose) {
	//  Begin search at the start
	Node<T> *current = head;
	while (current != NULL) {
		T current_data = current->get_data();
		//	If we find it, check whether or not to print message
		if (data_in == current_data) {
			if (verbose) {
				int count = current->get_count();
				cout << "item found, count = " << count << endl;
			}
			return current;
		}
		//	We haven't found it yet so try the next one
		current = current->get_next();
	}
	//	Print "not found" message if we need to
	if (verbose) {
		cout << "item not found" << endl;
	}
	return NULL;
}

template<typename T>
Node<T> * LinkedList<T>::insert_node(T data_in) {
	//	Check if  node is already in the list before we insert
	Node<T> *node = find_node(data_in, false);

	if (node != NULL) {
		//	It's already in the list, so just increment the count
		int new_count = node->get_count() + 1;
		node->set_count(new_count);
		cout << "item already present, new count = " << new_count << endl;
	} else {
		// It's not in the list so we insert it by setting the next/prev pointers properly
		node = new Node<T>(data_in);
		//	If LinkedList is empty, point next to the end
		if ((head == NULL) && (tail == NULL)) {
			head = node;
			node->set_next(tail);
			node->set_prev(NULL);
		}
		//  Otherwise, the current start is our new next
		else {
			node->set_next(head);
			node->set_prev(NULL);
			head->set_prev(node);
		}
		//	Finally, we can point the Node to be at the start
		head = node;
		cout << "item successfully inserted, count = 1" << endl;
	}
	return node;
}

template<typename T>
Node<T> * LinkedList<T>::remove_node(T data_in, bool min) {
	//	Check if  node is already in the list before we insert
	Node<T> *node = find_node(data_in, false);
	if (node != NULL) {
		// Found it! Proceed to check whether we delete node or decrement counter
		int count = node->get_count();
		if (count == 1) {
			// Delete node and Decrement count for later logic
			count--;
			node->set_count(count);

			/*** Rearrange pointers so node is removed from the list  ***/

			// Case 1: We are deleting the head
			if (node == head) {
				Node<T> *next_node = node->get_next();
				// Handle case where deletion makes list empty
				if (next_node != NULL) {
					next_node->set_prev(NULL);
					head = next_node;
				} else {
					// This deletion will casue list to be empty
					head = NULL;
					tail = NULL;
				}
			}
			// Case 2: We are deleting the tail
			else if (node->get_next() == NULL) {
				Node<T> *prev_node = node->get_prev();
				prev_node->set_next(NULL);
			}
			// Case 3: We are deleting some Node in the middle of the list
			else {
				Node<T> *prev_node = node->get_prev();
				Node<T> *next_node = node->get_next();
				prev_node->set_next(next_node);
				next_node->set_prev(prev_node);
			}
			if (min) {
				cout << "min item " << node->get_data()
						<< " successfully deleted" << endl;
			} else {
				cout << "item successfully deleted" << endl;
			}
		} else {
			// Otherwise, ONLY decrement count and print message
			count--;
			node->set_count(count);
			if (min) {
				cout << "min item = " << node->get_data()
						<< ", count decremented, new count = "
						<< node->get_count() << endl;
			} else {
				cout << "item count decremented, new count = " << count << endl;
			}
		}
	} else {
		cout << "item not present in the table" << endl;
	}
	return node;
}

#endif /* LINKEDLIST_H_ */
