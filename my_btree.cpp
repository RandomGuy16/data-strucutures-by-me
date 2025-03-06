#include "my_btree.h"
#include <memory>


my_btree::my_btree(int value) {
	root = std::make_unique<node>(value);
	items++;
}
my_btree::my_btree(const std::vector<int> & values) {
	for (int i : values) {
		insert(i);
	}
}

int my_btree::size() const {
	return items;
}

bool my_btree::empty() const {
	return items == 0;
}

// This function is in testing, i dont get how sonarlint and clang don't warn me bout this
void my_btree::insert_new_node (node & trav, int value) {
	// check if we should go to the left or to the right
	if (value < trav.value) {
		// check if we can place a new node right there
		if (trav.left == nullptr) {
			// place the new node
			auto new_node = std::make_unique<my_btree::node>(value);
			trav.left = std::move(new_node);
			items++;
		}
		// otherwise, keep going downwards
		else {
			insert_new_node(* trav.left, value);
		}
	}
	// now check if we should go to the right
	else if (value > trav.value) {
		// same as before, check if we can place the new node there
		if (trav.right == nullptr) {
			auto new_node = std::make_unique<my_btree::node>(value);
			trav.right = std::move(new_node);
			items++;
		}
		else {
			insert_new_node(* trav.right, value);
		}
	}
	else {
		// this clause is reached when the value and the current node's value are the same
		// then don't add the value
		return;
	}

};

void my_btree::insert(int value) {
	// If there are no nodes, make root the first with the suggested value
	if (empty()) {
		root = std::make_unique<my_btree::node>(value);
		items++;
	}
	// otherwise, insert the new value at the respective node following the BST invariant
	else {
		insert_new_node(* root.get(), value);
	}

	return;
}
