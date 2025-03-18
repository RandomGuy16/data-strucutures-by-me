#include "my_hashtable.h"
#include <utility>
#include <vector>
#include <forward_list>
#include <string>


using std::vector;
using std::forward_list;
using std::string;
using std::pair;
using hashing_table = std::vector<std::forward_list<std::pair<std::string, std::string>>>;


my_hashtable::my_hashtable() :
table(DEFAULT_SIZE), capacity(DEFAULT_SIZE), items(0),
threshold(DEFAULT_SIZE*DEFAULT_LOAD_FACTOR), hasher()
{
}

my_hashtable::my_hashtable(string key, string value) :
table(DEFAULT_SIZE), capacity(DEFAULT_SIZE), items(0),
threshold(DEFAULT_SIZE*DEFAULT_LOAD_FACTOR), hasher()
{
	my_hashtable::add(key, value);
}


int my_hashtable::size() { return items; }

// return hash based on the size of the table
int my_hashtable::get_hash(string key) const {
	return hasher(key)%capacity;
}

bool my_hashtable::has_key(string key) const {
	// if the bucket the key should go is empty, return false
	if (table.at(get_hash(key)).empty()) return false;
	// otherwise, iterate over the bucket until we find it
	for (auto el : table.at(get_hash(key))) {
		if (key == el.first) return true;
	}
	return false;
}

// create a new table with extended capacity
void my_hashtable::resize_table() {
	capacity *= 2;
	// table field is: std::array<std::forward_list<std::pair<std::string, std::string>>, 3UL> my_hashtable::table
	auto new_table = hashing_table(capacity);

	// add elements by iterating over all of them
	for (auto el : table) {
		if (el.empty()) continue;  // skip empty elements

		for (auto _pair : el) {
			int key_hash = get_hash(_pair.first);
			new_table.at(key_hash).emplace_front(_pair);
		}
	}
	table = new_table;
}


void my_hashtable::add(string key, string value) {
	// if key already added, dont to anything
	if (has_key(key)) return;

	// otherwise add the key
	// check if it's time to resize the hashtable
	if (++items > threshold) resize_table();
	// continue adding the key
	int key_hash = get_hash(key);

	auto new_pair = pair<string, string>(key, value);
	// insert at the last position
	table.at(key_hash).push_front(new_pair);
	// and that should be enough
}