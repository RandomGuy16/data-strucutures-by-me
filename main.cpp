#include <bits/stdc++.h>
#include "my_hashtable.h"


using namespace std;

int main(int argc, char const *argv[])
{
	auto hashmap = my_hashtable("key", "value");
	hashmap.add("2", "dos");
	hashmap.add("3", "tres");

	cout << "Hashmap capacity is: " << hashmap.size() << endl;

	return 0;
}
