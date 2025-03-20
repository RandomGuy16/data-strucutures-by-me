#include <bits/stdc++.h>
#include "hashtable_oaddr.h"


using namespace std;

int main(int argc, char const *argv[]) {
	auto ht = hashtable_oaddr();

	ht.add("apple", "red");
	ht.add("banana", "yellow");
	std::cout << "Insert Test: " << (ht.hasKey("apple") && ht.hasKey("banana") ? "PASS" : "FAIL") << "\n";
	
	ht.add("apple", "red");
	ht.add("apple", "green");
	std::cout << "Update Test: " << (ht.get("apple") == "green" ? "PASS" : "FAIL") << "\n";

	ht.add("apple", "red");
	ht.remove("apple");
	std::cout << "Remove Test: " << (!ht.hasKey("apple") ? "PASS" : "FAIL") << "\n";

	ht.add("abc", "first");
	ht.add("cba", "second"); // Assume same hash
	std::cout << "Collision Test: " << ((ht.get("abc") == "first") && (ht.get("cba") == "second") ? "PASS" : "FAIL") << "\n";

	return 0;
}
