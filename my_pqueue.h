#ifndef MY_PQUEUE
#define MY_PQUEUE

#include <vector>

template <typename T>
class my_pqueue
{
private:
	int size;
	std::vector<T> heap;
	/*
	keep some formulas in mind
	if node i
	parent = (i - 1)/2
	left child = 2i + 1
	right child = 2i + 2 = 2(i + 1)
	*/

	int get_parent_index(int node_i) { return (node_i - 1)/2 };
	int get_lchild_index(int node_i) { return 2*node_i + 1 };
	int get_rchild_index(int node_i) { return 2*node_i + 2 };
	void swap(int node_i, int target_i);

public:
	my_pqueue(): size(0), heap() {};

	~my_pqueue();

	void add(T el);

	T poll(int index);

	void check_to_swap(int node_i);

	bool contains(T el);

};



#endif
