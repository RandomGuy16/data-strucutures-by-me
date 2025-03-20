#include <bits/stdc++.h>
#include "hashtable_sch.h"


int main(int argc, char const *argv[]) {
	hashtable_sch ht;

	// Test empty hashtable
	std::cout << "Is empty: " << ht.empty() << "\n"; // Expected: 1 (true)

	// Adding values
	ht.add("apple", "red");
	ht.add("banana", "yellow");
	ht.add("grape", "purple");

	// Retrieving values
	std::cout << "Apple color: " << ht.get("apple") << "\n"; // Expected: red
	std::cout << "Banana color: " << ht.get("banana") << "\n"; // Expected: yellow

	// Checking keys
	std::cout << "Has apple: " << ht.has_key("apple") << "\n"; // Expected: 1 (true)
	std::cout << "Has mango: " << ht.has_key("mango") << "\n"; // Expected: 0 (false)

	// Removing values
	std::cout << "Removing apple: " << ht.remove("apple") << "\n"; // Expected: red
	std::cout << "Has apple after removal: " << ht.has_key("apple") << "\n"; // Expected: 0 (false)

	// Test collision handling (forcing same hash)
	ht.add("dog", "bark");
	ht.add("god", "divine");  // If the hash function is poor, this could collide

	std::cout << "Dog sound: " << ht.get("dog") << "\n"; // Expected: bark
	std::cout << "God meaning: " << ht.get("god") << "\n"; // Expected: divine

	// Test resizing (adding more than threshold)
	ht.add("orange", "orange");
	ht.add("blueberry", "blue");
	ht.add("strawberry", "red");

	std::cout << "Size after insertions: " << ht.size() << "\n"; // Shouldn't be greater than threshold

	return 0;
}
