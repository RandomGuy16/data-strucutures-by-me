#include "hashtable_sch.h"
#include <cmath>
#include <string_view>
#include <utility>
#include <vector>
#include <forward_list>
#include <string>


using std::vector;
using std::forward_list;
using std::string;
using std::pair;
using std::string_view;
using hashing_table = std::vector<std::forward_list<std::pair<std::string, std::string>>>;


hashtable_sch::hashtable_sch() :
table(DEFAULT_SIZE), items(0), threshold(static_cast<int>(DEFAULT_SIZE*DEFAULT_LOAD_FACTOR)),
capacity(DEFAULT_SIZE), hasher()
{
}

hashtable_sch::hashtable_sch(const string & key, const string & value) :
table(DEFAULT_SIZE), items(0), threshold(static_cast<int>(DEFAULT_SIZE*DEFAULT_LOAD_FACTOR)),
capacity(DEFAULT_SIZE), hasher()
{
	add(key, value);
}


int hashtable_sch::size() const { return items; }

bool hashtable_sch::empty() const {
	return size() == 0;
}

// return hash based on the size of the table
int hashtable_sch::get_hash(const string & key) const {
	return hasher(key)%capacity;
}


// check if the key provided is inside the hashmap
bool hashtable_sch::has_key(const string & key) const {
	// iterate over the proper bucket
	const auto & bucket = table.at(get_hash(key));
	return std::any_of(
		bucket.begin(),
		bucket.end(),
		[&key](const pair<string, string> & _pair) -> bool {
			return key == _pair.first;
		}
	);
}


// create a new table with extended capacity
void hashtable_sch::resize_table() {
	capacity *= 2;
	threshold = static_cast<int>(capacity*DEFAULT_LOAD_FACTOR);
	auto new_table = hashing_table(capacity);

	// add elements by iterating over all of them
	for (const auto & ll : table) {
		if (ll.empty()) continue;  // skip empty buckets

		for (auto _pair : ll) {
			int key_hash = get_hash(_pair.first);
			new_table.at(key_hash).emplace_front(_pair);
		}
	}
	table = std::move(new_table);
}


void hashtable_sch::add(string key, string value) {
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


string hashtable_sch::get(const string & key) const {
	// check inside the hashtable
	for (auto const& [pair_key, pair_value] : table.at(get_hash(key))) {
		if (pair_key == key) return pair_value;
	}

	// if there isn't the key, return empty string
	return "";
}


string hashtable_sch::remove(const string & key) {
	if (empty() || !has_key(key)) return "";

	auto & bucket = table.at(get_hash(key));
	string target_value;

	// iterate over all elements in the bucket to delete the adequate one
	bucket.remove_if(
		[&target_value, &key](const pair<string, string> & p) mutable {
			if (p.first == key) {
				target_value = p.second;
				return true;
			}
			return false;
		}
	);

	// reduce the item count and return target
	items--;
	return target_value;
}