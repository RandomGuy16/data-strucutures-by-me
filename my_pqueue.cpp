#include "my_pqueue.h"
#include "iostream"


template<typename T>
my_pqueue<T>::my_pqueue(bool min_heap): size(0), heap() {
	if (min_heap) set_min_heap();
	else set_max_heap();
}

template<typename T>
my_pqueue<T>::~my_pqueue()
{
}

template<typename T>
void my_pqueue<T>::swap(int node_i, int target_i) {
	// save origin node value
	T node_v = heap.at(node_i);
	//swap values
	heap.at(node_i) = heap.at(target_i);
	heap.at(target_i) = node_v;
}

template<typename T>
void my_pqueue<T>::set_min_heap() {
	invariant = [](T parent, T child) -> bool {
		return parent <= child;
	};
}
template<typename T>
void my_pqueue<T>::set_max_heap() {
	invariant = [](T parent, T child) -> bool {
		return parent >= child;
	};
}

template<typename T>
void my_pqueue<T>::add(T el) {
	heap.emplace_back(el);
	check_to_swap(size);

	size++;
}

template<typename T>
T my_pqueue<T>::poll() {
	if (heap.empty()) {
		throw std::runtime_error("removing from empty queue");
	}
	swap(0, size - 1);
	heap.pop_back();

	check_to_swap(0);

	size--;
}

template<typename T>
void my_pqueue<T>::check_to_swap(int node_i) {
	int parent_i = get_parent_i(node_i);
	int lchild_i = get_lchild_i(node_i);
	int rchild_i = get_rchild_i(node_i);

	if (!invariant(heap.at(parent_i), heap.at(node_i))) {
		// case 1: adding elements
		// bubble up and check if at the parent node are problems
		swap(node_i, parent_i);
		check_to_swap(parent_i);
	} else if (!invariant(heap.at(node_i), heap.at(lchild_i))) {
		// case 2: when polling elements
		// bubble down and check if problems remain
		swap(node_i, lchild_i);
		check_to_swap(lchild_i);
	} else if (!invariant(heap.at(node_i), heap.at(rchild_i))) {
		swap(node_i, rchild_i);
		check_to_swap(rchild_i);
	}
}

template<typename T>
bool my_pqueue<T>::contains(T el) {
	return std::any_of(heap.begin(), heap.end(), [el](T trav) -> bool {
		return trav == el;
	});
}

