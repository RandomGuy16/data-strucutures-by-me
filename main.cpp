#include <iostream>
#include <memory>
#include "my_unionfind.h"
#include "my_btree.h"

using namespace std;

int main(int argc, char const *argv[])
{
	
	cout << "<-- binary tree implementation test -->" << endl;

	my_btree tree;

	// Insertion
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);
	tree.insert(3);
	tree.insert(7);
	tree.insert(12);
	tree.insert(18);
	tree.insert(10); // Duplicate

	// Check size and emptiness
	std::cout << "Size of tree: " << tree.size() << std::endl; // Expected: 7
	std::cout << "Is tree empty? " << (tree.empty() ? "Yes" : "No") << std::endl; // Expected: No

	// Search for nodes
	std::cout << "Does tree have 7? " << (tree.has_node(7) ? "Yes" : "No") << std::endl; // Expected: Yes
	std::cout << "Does tree have 20? " << (tree.has_node(20) ? "Yes" : "No") << std::endl; // Expected: No

	// Get sorted array
	std::vector<int> sorted_values = tree.get_sorted_array();
	std::cout << "Sorted values: ";
	for (int value : sorted_values) {
			std::cout << value << " "; // Expected: 3 5 7 10 12 15 18
	}
	std::cout << std::endl;

	// Removal of nodes
	tree.remove(3);  // Remove leaf node
	tree.remove(5);  // Remove node with one child
	tree.remove(10); // Remove node with two children

	// Check size after removals
	std::cout << "Size of tree after removals: " << tree.size() << std::endl; // Expected: 4

	// Final sorted array
	sorted_values = tree.get_sorted_array();
	std::cout << "Sorted values after removals: ";
	for (int value : sorted_values) {
			std::cout << value << " "; // Expected: 7 12 15 18
	}
	std::cout << std::endl;

	std::cout << "height: " << tree.height() << std::endl;  // Expected: 3
	
	return 0;
}
