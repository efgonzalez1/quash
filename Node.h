/*
 * Node.h
 *
 *  Created on: Apr 26, 2014
 *      Author: Fernando
 */

#ifndef NODE_H_
#define NODE_H_

#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
	Node(T data_in);
	~Node();

	Node<T> * get_next();
	void set_next(Node<T> *next_in);

	Node<T> * get_prev();
	void set_prev(Node<T> *prev_in);

	T get_data();
	void set_data(T data_in);

	int get_count();
	void set_count(int count_in);

	int get_index();
	void set_index(int index_in);

	Node<T> *next;
	Node<T> *prev;

private:
	T data;
	int count;
	int index;
};

template<typename T>
Node<T>::Node(T data_in) {
	data = data_in;
	count = 1;
	index = -1;
	next = NULL;
	prev = NULL;
}

template<typename T>
Node<T>::~Node() {
	delete[] next;
	delete[] prev;
}

template<typename T>
Node<T> * Node<T>::get_next() {
	return next;
}

template<typename T>
void Node<T>::set_next(Node<T> *next_in) {
	next = next_in;
}

template<typename T>
Node<T> * Node<T>::get_prev() {
	return prev;
}

template<typename T>
void Node<T>::set_prev(Node<T> *prev_in) {
	prev = prev_in;
}

template<typename T>
T Node<T>::get_data() {
	return data;
}

template<typename T>
void Node<T>::set_data(T data_in) {
	data = data_in;
}

template<typename T>
int Node<T>::get_count() {
	return count;
}

template<typename T>
void Node<T>::set_count(int count_in) {
	count = count_in;
}

template<typename T>
int Node<T>::get_index() {
	return index;
}

template<typename T>
void Node<T>::set_index(int index_in) {
	index = index_in;
}

#endif /* NODE_H_ */
