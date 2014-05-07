/*
 * Heap.h
 *
 *  Created on: Apr 30, 2014
 *      Author: Fernando
 */

#ifndef HEAP_H_
#define HEAP_H_

#include <vector>
#include "Node.h"
using namespace std;

template<typename T>
class Heap {
public:
	Heap(int heap_size_in);
	~Heap();

	void print();
	Node<T> * insert(Node<T> *node);
	Node<T> * remove(Node<T> *node);
	Node<T> * remove_min();

private:
	vector<Node<T> *> *heap;
	unsigned int heap_count;
	void percolate_up(Node<T> *node);
	void percolate_down(unsigned int hole);
};

template<typename T>
Heap<T>::Heap(int heap_size_in) {
	heap_count = 0;
	heap = new vector<Node<T> *>(heap_size_in);
}

template<typename T>
Heap<T>::~Heap() {
	delete[] heap;
}

template<typename T>
void Heap<T>::print() {
	for (unsigned int k = 1; k <= heap_count; k++) {
		cout << heap->at(k)->get_data() << " ";
	}
	cout << endl;
}

template<typename T>
Node<T> * Heap<T>::insert(Node<T> *node) {
	//	Resize if the heap gets too full
	if (heap_count == (heap->size() - 1)) {
		heap->resize(heap->size() * 2);
	}
	percolate_up(node);
	return node;
}

template<typename T>
Node<T> * Heap<T>::remove(Node<T> *node) {
//	Node<T> *node = heap->at(1);
	int index = node->get_index();

	if (node != NULL) {
		heap->at(index) = NULL;
		heap->at(index) = heap->at(heap_count);
		heap_count--;
		if (heap->at(index) != NULL) {
			heap->at(index)->set_index(index);
		} else {
			return node;
		}
		percolate_down(index);
	}
	return node;
}

template<typename T>
Node<T> * Heap<T>::remove_min() {
	Node<T> *min = heap->at(1);

	if (min != NULL) {
		//	Check if we need to decrement counter or fully delete
		if (min->get_count() == 1) {
			// Min count == 1 so we proceed to delete
			heap->at(1) = NULL;
			heap->at(1) = heap->at(heap_count);
			heap_count--;
			if (heap->at(1) != NULL) {
				heap->at(1)->set_index(1);
			} else {
				return min;
			}
			percolate_down(1);
		} else {
			// Just return the node so another function can handle the counter
		}
	}
	return min;
}

template<typename T>
void Heap<T>::percolate_up(Node<T> *node) {
	heap_count++;
	int hole = heap_count;

	heap->at(0) = node;
	for (; node->get_data() < heap->at(hole / 2)->get_data(); hole /= 2) {
		Node<T> *tmp = heap->at(hole / 2);
		heap->at(hole) = tmp;
		heap->at(hole)->set_index(hole);
		tmp = NULL;
	}
	heap->at(hole) = heap->at(0);
	heap->at(hole)->set_index(hole);
	heap->at(0) = NULL;
}

template<typename T>
void Heap<T>::percolate_down(unsigned int hole) {
	unsigned int child;
	Node<T> *tmp = heap->at(hole);
	heap->at(hole) = NULL;

	for (; hole * 2 <= heap_count; hole = child) {
		child = hole * 2;
		if ((child != heap_count)
				&& (heap->at(child + 1)->get_data()
						< heap->at(child)->get_data())) {
			child++;
		}
		if (heap->at(child)->get_data() < tmp->get_data()) {
			heap->at(hole) = heap->at(child);
			heap->at(hole)->set_index(hole);
			heap->at(child) = NULL;
		} else {
			break;
		}
	}
	heap->at(hole) = tmp;
	heap->at(hole)->set_index(hole);
}

#endif /* HEAP_H_ */
