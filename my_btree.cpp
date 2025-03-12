#include "my_btree.h"
#include <functional>
#include <memory>
#include <vector>


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
void my_btree::_p_insert (node & trav, int value) {
	// check if we should go to the left or to the right
	if (value < trav.value) {
		// check if we can place a new node right there
		if (trav.left == nullptr) {
			// place the new node
			auto new_node = std::make_unique<my_btree::node>(value);
			trav.left = std::move(new_node);
		}
		// otherwise, keep going downwards
		else {
			_p_insert(* trav.left, value);
		}
	}
	// now check if we should go to the right
	else if (value > trav.value) {
		// same as before, check if we can place the new node there
		if (trav.right == nullptr) {
			auto new_node = std::make_unique<my_btree::node>(value);
			trav.right = std::move(new_node);
		}
		else {
			_p_insert(* trav.right, value);
		}
	}
}

void my_btree::insert(int value) {
	// if we already have the value don't do anything
	if (has_node(value)) return;

	// otherwise, insert the new value at the respective node following the BST invariant
	// If there are no nodes, make root the first with the suggested value
	if (empty()) root = std::make_unique<my_btree::node>(value);
	else _p_insert(* root.get(), value);
	
	items++;
}


// checks recursively if the binary tree has a node with the value requested
// @param value
bool my_btree::_p_has_node(node & trav, int value) const {
	if (empty()) return false;

	// check if we should go to the left or to the right
	if (value < trav.value) {
		// This clause means our value wasn't found and we get kicked out
		if (trav.left == nullptr) return false;
		// otherwise keep going downwards
		return _p_has_node(* trav.left, value);
	}
	// now check if we should go to the right
	else if (value > trav.value) {
		// same as before, this clause means we didn't find the value
		if (trav.right == nullptr) return false;

		// keep going downwards
		return _p_has_node(* trav.right, value);
	}
	// This means, we found the target, return true
	return true;
}

// check if has one item
bool my_btree::has_node(int value) const {
	return _p_has_node(* root.get(), value);
}

// finds the smallest node in the left subtree, and replaces orig value with this smallest value
int my_btree::_p_replace_with_largest_left(node & rtarget) {
	// initialize a traveler and go to the left
	my_btree::node * trav1 = rtarget.left.get();

	// if it only has one node in the left subtree, remove that node and
	// store its value in origin
	if (trav1->right == nullptr) {
		rtarget.value = trav1->value;
		// and dont forget to delete the pointer, since is a smartpointer, it's deleted automatically
		rtarget.left = nullptr;
		return rtarget.value;
	}

	// If in the left subtree there are 2 or more nodes, go all the way to the right until
	// we can't anymore, we have 2 pointers: trav1 and trav2
	// trav1 goes forward and trav2 follows trav1, when trav1 encounters the final node
	// trav2 points to trav1's left child, origin stores trav1's value and we delete trav1

	// second traveler
	my_btree::node * trav2 = trav1;
	// go to the right once in trav1
	trav1 = trav1->right.get();

	// travel until: trav1 is the rightest node and trav2 is the immediate before trav1
	for ( ; trav1->right != nullptr; trav1 = trav1->right.get(), trav2 = trav2->right.get());

	// Now check if trav1 is a leaf node or has a subtree
	if (trav1->left != nullptr) {
		// if it has a subtree in the left, we make trav2 point to the subtree root
		// and store the trav1 value
		rtarget.value = trav1->value;
		trav2->right = std::move(trav1->left);
	}
	else {
		// when there isn't a subtree in the left, just delete trav1
		rtarget.value = trav1->value;
		trav2->right = nullptr;
	}
	return rtarget.value;
}

// finds the largest node in the right subtree, and replaces orig value with this smallest value
int my_btree::_p_replace_with_smallest_right(node & orig) {
	my_btree::node * trav1 = orig.right.get();

	// if there's only one node in the subtree:
	if (trav1->left == nullptr) {
		orig.value = trav1->value;
		orig.right = nullptr;
		// finishing this fast will delete the pointer to the previous child, so no problem
		return orig.value;
	}

	// if there are more nodes
	my_btree::node * trav2 = trav1->left.get();
	// iterate over until we find the end
	for ( ; trav1->left != nullptr; trav1 = trav1->left.get(), trav2 = trav2->left.get());

	// find the right child of the leftest node and make trav2 point to it
	// if trav1 has a right child
	if (trav1->right != nullptr) {
		orig.value = trav1->value;
		trav2->left = std::move(trav1->right);
	}
	else {
		// otherwise just return the value at trav1
		orig.value = trav1->value;
		trav2->left = nullptr;
	}

	// return the value at the end
	return orig.value;
}

int my_btree::_p_remove(node & trav, int t_value) {
	// auxiliar travelers
	my_btree::node * trav1 = &trav;
	my_btree::node * trav2 = &trav;
	
	// loop while our travelers are not the target. The loop
	// stops when trav1 has the target value
	while (trav1->value != t_value) {
		trav2 = trav1;
		// if trav1 value is less than t_value, go to the right
		if (trav1->value < t_value && trav1->right != nullptr) {
			trav1 = trav1->right.get();
		}
		// and if trav1 value is greater than t_value, go to the left
		else if (trav1->value > t_value && trav1->left != nullptr) {
			trav1 = trav1->left.get();
		}
		// if the value isn't in the binary tree, do something XD
		else if (trav1->value != t_value && trav1->right == nullptr && trav1->left == nullptr) {
			return -1;
		}
	}

	// at this point, trav1 has the target value
	// check where does it have the subtree, if there's any
	if (trav1->left != nullptr) return _p_replace_with_largest_left(*trav1);  // if has a subtree at the left
	else if (trav1->right != nullptr) return _p_replace_with_smallest_right(*trav1);  // if has a subtree at the right or both
	
	// if no subtrees
	if (t_value < trav2->value) trav2->left = nullptr;  // if trav2 is less than target value, then trav1 is at its right
	else trav2->right = nullptr;  // otherwise is at the left

	return t_value;
}


int my_btree::remove(int value) {
	// if there isn't the value, just return
	if (!has_node(value)) return false;

	items--;
	// if the value is at the root:
	if (root->value == value) {
		// check where does it have children, to delete easily
		if (root->left != nullptr) return _p_replace_with_largest_left(*root.get());
		else if (root->right != nullptr) return _p_replace_with_smallest_right(*root.get());
		else {
			// if it doesn't have children, kinda sad, remove root
			root = nullptr;
			return value;
		}
	}

	return _p_remove(*root.get(), value);
}

void my_btree::print_values() const {
	// do a BFS, do this after we implement the BFS in the graph theory folder
}

// returns an array with the elements of the binary tree sorted in ascending order
std::vector<int> my_btree::get_sorted_array() const {
	// declare the array to return
	auto somearray = std::vector<int>();

	// define a traversal function, in this case is a lambda
	std::function<void(my_btree::node *trav)> inorder_traversal = [&](my_btree::node *trav) -> void {
		// since we're using pointers, we check if we are dealing with nullptr
		if (trav == nullptr) return;

		// classical inorder traversal
		inorder_traversal(trav->left.get());
		somearray.push_back(trav->value);
		inorder_traversal(trav->right.get());
	};

	// never forget to call the function =I
	inorder_traversal(root.get());
	return somearray;
}

