#ifndef MY_PQUEUE
#define MY_PQUEUE

#include <stdexcept>
#include <vector>
#include <functional>

template <typename T>
class my_pqueue
{
private:
	int size = 0;
	std::vector<T> heap;
	std::function<bool(T, T)> invariant;

	int get_parent_i(int node_i) const {
		if (node_i == 0) {
			return 0;
		} else {
			return (node_i - 1)/2;
		}
	}
	int get_lchild_i(int node_i) const { return 2*node_i + 1; }
	int get_rchild_i(int node_i) const { return 2*node_i + 2; }
	
	void swap(int node_i, int target_i) {
		// save origin node value
		T node_v = heap.at(node_i);
		//swap values
		heap.at(node_i) = heap.at(target_i);
		heap.at(target_i) = node_v;
	}

	void set_min_heap() {
		invariant = [](T parent, T child) -> bool {
			return parent <= child;
		};
	}
	void set_max_heap() {
		invariant = [](T parent, T child) -> bool {
			return parent >= child;
		};
	}

public:
	my_pqueue() { set_min_heap(); }

	explicit my_pqueue(bool min_heap) {
		if (min_heap) set_min_heap();
		else set_max_heap();
	}

	~my_pqueue() = default;

	void add(T el) {
		heap.push_back(el);
		size++;

		check_to_swap(size - 1);
	}

	T poll() {
		if (heap.empty()) {
			throw std::runtime_error("removing from empty queue");
		}
		swap(0, size - 1);
		T target_v = heap.at(0);
		heap.pop_back();
		size--;

		if (heap.empty()) return target_v;

		check_to_swap(0);
		return target_v;
	}

	void check_to_swap(int node_i) {
		int parent_i = get_parent_i(node_i);
		int lchild_i = get_lchild_i(node_i);
		int rchild_i = get_rchild_i(node_i);

		if (!invariant(heap.at(parent_i), heap.at(node_i))) {
			// case 1: adding elements: bubble up and check if at the parent node are problems
			swap(node_i, parent_i);
			check_to_swap(parent_i);

		} else if (size > lchild_i && !invariant(heap.at(node_i), heap.at(lchild_i))) {
			// case 2: when polling elements: bubble down and check if problems remain
			swap(node_i, lchild_i);
			check_to_swap(lchild_i);
			check_to_swap(rchild_i);

		} else if (size > rchild_i && !invariant(heap.at(node_i), heap.at(rchild_i))) {
			swap(node_i, rchild_i);
			check_to_swap(rchild_i);
			check_to_swap(lchild_i);
		}
	}

	T remove(T target) {
		if (heap.empty()) {
				throw std::runtime_error("removing from empty queue");
		}
		int index = -1;
		std::any_of(heap.begin(), heap.end(), [target, &index](T trav) -> bool {
			index++;
			return trav == target;
		});

		swap(index, size - 1);
		heap.pop_back();
		size--;

		if (heap.empty()) return target;

		if (index == size) {
			check_to_swap(size - 1);
		}
		else {
			check_to_swap(index);
		}
		return target;
	}

	bool contains(T el) {
		return std::any_of(heap.begin(), heap.end(), [el](T trav) -> bool {
			return trav == el;
		});
	}

	int get_size() const {
		return size;
	}

};

#endif
