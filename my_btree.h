#include <memory>
#include <vector>

#if !defined(MY_BTREE)
#define MY_BTREE

class my_btree
{
private:
	class node
	{
	public:
		std::unique_ptr<node> left = nullptr;
		std::unique_ptr<node> right = nullptr;
		int value;

		explicit node(int value): value(value) {
		};
		~node() = default;
	};

	int items = 0;
	std::unique_ptr<node> root;
	std::vector<int> sorted_array = std::vector<int>();

	void _p_insert(node & node, int value);

	int _p_replace_with_smallest_right(node & orig);
	
	int _p_replace_with_largest_left(node & orig);

	int _p_remove(node & trav, int value);

	bool _p_has_node(node & trav, int value) const;

public:
	my_btree() = default;
	explicit my_btree(int value);
	explicit my_btree(const std::vector<int> & values);
	~my_btree() = default;

	int size() const;

	bool empty() const;

	void insert(int value);

	int remove(int value);

	bool has_node(int value) const;

	void print_values() const;

	std::vector<int> get_sorted_array() const;

};

#endif