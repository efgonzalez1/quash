/*
 * Quash.h
 *
 *  Created on: Apr 28, 2014
 *      Author: Fernando
 */

#ifndef QUASH_H_
#define QUASH_H_

#include "HashTable.h"
#include "Heap.h"
using namespace std;

template<typename T>
class Quash {
public:
	Quash(int quash_size_in);
	~Quash();
	void insert(T element);
	void remove(T element);
	void remove_min();
	void lookup(T element);
	void print();
private:
	unsigned int quash_size;
	Heap<T> *heap;
	HashTable<T> *table;
};

template<typename T>
Quash<T>::Quash(int quash_size_in) {
	quash_size = quash_size_in;
	heap = new Heap<T>(quash_size);
	table = new HashTable<T>(quash_size);
}

template<typename T>
Quash<T>::~Quash() {
	delete[] heap;
	delete[] table;
}

template<typename T>
void Quash<T>::insert(T element) {
	Node<T> *node = table->insert(element);
	if (node->get_count() == 1) {
		heap->insert(node);
	} else {
		// Don't insert duplicates into the heap
	}
}

template<typename T>
void Quash<T>::remove(T element) {
	Node<T> *node = table->remove(element, false);
	if (node != NULL) {
		if (node->get_count() == 0) {
			heap->remove(node);
		}
	}
}

template<typename T>
void Quash<T>::remove_min() {
	Node<T> *node = heap->remove_min();
	if (node != NULL) {
		table->remove(node->get_data(), true);
	} else {
		cout << "min item not present since table is empty" << endl;
	}
}

template<typename T>
void Quash<T>::lookup(T element) {
	table->lookup(element);
}

template<typename T>
void Quash<T>::print() {
	heap->print();
}

#endif /* QUASH_H_ */
