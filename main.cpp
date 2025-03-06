#include <iostream>
#include <memory>
#include "my_unionfind.h"
#include "my_btree.h"

using namespace std;

int main(int argc, char const *argv[])
{
	cout << "<-- binary tree implementation test -->" << endl;

	auto btree = make_unique<my_btree>(10);

	btree->insert(2);
	btree->insert(3);
	btree->insert(15);
	btree->insert(5);
	btree->insert(20);
	btree->insert(12);

	return 0;
}
