#include <memory>

#if !defined(MY_BTREE)
#define MY_BTREE

class my_btree
{
private:
	class node
	{
	private:
	// fields
	public:
		node * left;
		node * right;
		int value;

		node(int value): left(), right() {
			this->value = value;
			this->left = nullptr;
			this->right = nullptr;
		};
		~node() = default;
	};

	int items = 0;
	std::unique_ptr<node> root;

	std::unique_ptr<node> get_new_node_parent(node node, int value);
	
public:
	my_btree() = default;
	my_btree(int value);
	~my_btree() = default;

	int size() const;

	bool empty() const;

	void insert(int value);

	int remove(int value);

	int has(int value);

};

#endif