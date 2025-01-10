#ifndef MY_PQUEUE
#define MY_PQUEUE

#include <vector>
#include <functional>

template <typename T>
class my_pqueue
{
private:
	int size;
	std::vector<T> heap;
	std::function<bool(T, T)> invariant;

	int get_parent_i(int node_i) { return (node_i - 1)/2; }
	int get_lchild_i(int node_i) { return 2*node_i + 1; }
	int get_rchild_i(int node_i) { return 2*node_i + 2; }
	void swap(int node_i, int target_i);

	void set_min_heap();
	void set_max_heap();

public:
	my_pqueue(): size(0), heap() { set_min_heap(); }

	my_pqueue(bool min_heap);

	~my_pqueue();

	void add(T el);

	T poll();

	void check_to_swap(int node_i);

	bool contains(T el);

};

#endif
