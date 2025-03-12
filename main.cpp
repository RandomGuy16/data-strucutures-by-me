#include <bits/stdc++.h>
#include <functional>


using namespace std;

// datatype for practice with hash functions
struct person
{
	string name;
	int age;
	char sex;
	int hash;

	person(string_view name, int age, char sex): name(name), age(age), sex(sex) {
		
	}
};

// function to practice with hash functions
int hash_function(const person & target) {
	int hash {};

	// add ascii value of every character in the name
	for (const auto &chr : target.name) {
		hash += (int)chr;
	}

	// sum the age
	hash += target.age;

	hash = hash << 1;
	if (target.sex == 'M') hash++;
	
	// make it in the range [0,5]
	return hash % 6;
}

// Specialization of hash built-in function for person type
namespace std {
	template <>
	struct hash<person> {
		size_t operator()(const person & p) const {
			size_t res =  hash<int>{}(p.age) + hash<string>{}(p.name) + hash<char>{}(p.sex);
			return res/3;
		}
	};
}

int main(int argc, char const *argv[])
{
	person marc("Marc", 19, 'M');

	// create the hash function
	hash<person> hasher;


	cout << "Hash purely by me: " << hash_function(marc) << endl;
	cout << "Hash by c++ and me: " << hasher(marc) << endl;

	return 0;
}
