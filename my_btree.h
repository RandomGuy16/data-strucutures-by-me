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

	void _p_insert_node(node & node, int value);

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

};

#endif