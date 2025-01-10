#include "my_pqueue.h"
#include "iostream"


template<typename T>
my_pqueue<T>::~my_pqueue()
{
}

template<typename T>
void my_pqueue<T>::swap(int node_i, int target_i) {
	heap.insert()
}

template<typename T>
void my_pqueue<T>::add(T el) {
	if (T == NULL) {
		throw std::runtime_error("null entered as an argument")
	}

	heap.at(size) = el;

}

template<typename T>
T my_pqueue<T>::poll(int index) {

}

template<typename T>
void my_pqueue<T>::check_to_swap(int node_i) {
	int parent = get_parent_index(node_i);
	int lchild = get_lchild_index(node_i);
	int rchild = get_rchild_index(node_i);

	
}

template<typename T>
bool my_pqueue<T>::contains(T el) {

}