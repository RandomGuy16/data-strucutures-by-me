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
// get the # of nodes in binary tree
int my_btree::size() const {
	return items;
}
// check if binary tree has no nodes
bool my_btree::empty() const {
	return items == 0;
}

// This function is in testing, i dont get how sonarlint and clang don't warn me bout this
// Also, the _p stands for private, so the accesible method is insert =D
void my_btree::_p_insert_node (node & trav, int value) {
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
			_p_insert_node(* trav.left, value);
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
			_p_insert_node(* trav.right, value);
		}
	}
	else {
		// this clause is reached when the value and the current node's value are the same
		// then don't add the value
		return;
	}
}

void my_btree::insert(int value) {
	// If there are no nodes, make root the first with the suggested value
	if (empty()) {
		root = std::make_unique<my_btree::node>(value);
		items++;
	}
	// otherwise, insert the new value at the respective node following the BST invariant
	else {
		_p_insert_node(* root.get(), value);
	}
	return;
}

bool my_btree::_p_has_node(node & trav, int value) const {
	// check if we should go to the left or to the right
	if (value < trav.value) {
		if (trav.left == nullptr) {
			// This clause means our value wasn't found and we get kicked out
			return false;
		}
		// otherwise keep going downwards
		_p_has_node(* trav.left, value);
	}
	// now check if we should go to the right
	else if (value > trav.value) {
		if (trav.right == nullptr) {
			// same as before, this clause means we didn't find the value
			return false;
		}
		// keep going downwards
		_p_has_node(* trav.right, value);
	}
	else {
		// This means, we found the target, return true
		return true;
	}
	return false;
}

// check if has one item
bool my_btree::has_node(int value) const {
	return _p_has_node(* root.get(), value);
}

int my_btree::_p_remove(node & trav, int value) {
	// check if we should go to the left or to the right
	if (value < trav.value) {
		// if our value is at the left
		if (trav.left->value == value) {
			// delete()
			// This clause means our value wasn't found and we get kicked out
			return false;
		}
		// otherwise keep going downwards
		_p_remove(* trav.left, value);
	}
	// now check if we should go to the right
	else if (value > trav.value) {
		if (trav.right->value == value) {
			// same as before, if our target is at the right
			// delete()
			return false;
		}
		// keep going downwards to the right
		_p_has_node(* trav.right, value);
	}
	else {
		// This means, we found the target, return true

		return value;
	}
	return false;
}

int my_btree::remove(int value) {
	if (root->value == value) {
		// delete_root()
		return value;
	}
	return _p_remove(*root.get(), value);
}
