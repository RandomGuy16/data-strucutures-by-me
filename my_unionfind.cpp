#include "my_unionfind.h"
#include <numeric>
#include <vector>
#include <iostream>


my_unionfind::my_unionfind(int n): parents(n), ranks(n, 1) {
	std::iota(parents.begin(), parents.end(), 0);
}

int my_unionfind::find(int x) {
	if (parents.at(x) != x) {
		parents.at(x) = find(parents.at(x));
	}
	return parents.at(x);
}

bool my_unionfind::unify(int x, int y) {
	int rootX = find(x);

	if (int rootY = find(y); rootX != rootY) {
		if (ranks.at(rootX) > ranks.at(rootY)) {
			parents.at(rootY) = rootX;
		}
		else if (ranks.at(rootX) < ranks.at(rootY)) {
			parents.at(rootX) = rootY;
		}
		else {
			parents.at(rootY) = rootX;
			ranks.at(rootX) += 1;
		}
		return true;
	}
	return false;
}

void my_unionfind::print_data() const {
	std::cout << "\nparents: [ ";
	for (int i : parents) {
		std::cout << i << " ";
	}
	std::cout << "]\nranks: [ ";
	for (int i : ranks) {
		std::cout << i << " ";
	}
	std::cout << "]" << std::endl;
}