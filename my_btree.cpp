#include "my_btree.h"
#include <memory>


my_btree::my_btree(int value) {
	root = std::make_unique<node>(value);
}

int my_btree::size() const {
	return items;
}

// This function is in testing, i dont get how sonarlint and clang don't warn me bout this
std::unique_ptr<my_btree::node> my_btree::get_new_node_parent (node node, int value) {
	// if is a leaf node, return itself (to append)
	if (node.left == nullptr && node.right == nullptr) return std::make_unique<my_btree::node>(value);
	
	// otherwise, check the BST invariant and go one level deeper
	if (value < node.value) {
		// recursively go to the left
		return get_new_node_parent(* node.left, value);
	}
	else if (value > node.value) {
		// recursively go to the right
		return get_new_node_parent(* node.right, value);
	}
	else {
		// if the value is already inserted, don't repeat values
		return nullptr;
	}
};

void my_btree::insert(int value) {
	std::unique_ptr<node> new_node = std::make_unique<node>(value);

	if (!size()) { // if binary tree is empty
		root = std::make_unique<node>(value);
		return;
	}

	// get the node what would be the parent of the new node
	auto parent = get_new_node_parent(* root.get(), value);
	if (parent == nullptr) {
		return;
	}
	else if (value < parent->value) {
		parent->left = new_node.get();
	}
	else if (value > parent->value) {
		parent->right = new_node.get();
	}

	return;
}
