#include "hashtable_oaddr.h"
#include <string_view>
#include <vector>
#include <string>


using std::vector;
using std::string;
using std::string_view;


hashtable_oaddr::hashtable_oaddr() :
keys(DEFAULT_SIZE),
values(DEFAULT_SIZE),
occupiedSlots(DEFAULT_SIZE),
items(0),
threshold(static_cast<int>(DEFAULT_SIZE*LOAD_FACTOR)),
capacity(DEFAULT_SIZE),
hasher()
{
}

hashtable_oaddr::hashtable_oaddr(const string & key, const string & value) :
keys(DEFAULT_SIZE),
values(DEFAULT_SIZE),
occupiedSlots(DEFAULT_SIZE),
items(0),
threshold(static_cast<int>(DEFAULT_SIZE*LOAD_FACTOR)),
capacity(DEFAULT_SIZE),
hasher()
{
	add(key, value);
}


int hashtable_oaddr::size() const { return items; }

bool hashtable_oaddr::empty() const { return size() == 0; }

// return hash based on the size of the table
int hashtable_oaddr::mGetHash(const string & key) const {
	return hasher(key)%capacity;
}

int hashtable_oaddr::mProbingFunction(int x) const {
	return x*(x + 1)/2;
}

// check if the key provided is inside the hashtable
bool hashtable_oaddr::hasKey(const string & key) const {
	// initialize the counter for probing
	int x {};
	int k_hash = mGetHash(key);
	int index = k_hash;

	// use probing until we find the element
	while (occupiedSlots[index] && keys[index] != key) {
		index = k_hash + mProbingFunction(x);
		x++;
	}

	// returns true if we found the value
	return keys[index] == key;
}

void hashtable_oaddr::resize_table() {
	capacity *= 2;
	threshold *= 2;  // since threshold = capacity*loaffactor and capacity = 2*capacity

	auto newKeys = vector<string>(capacity);
	auto newValues = vector<string>(capacity);
	auto newIsOccupied = vector<bool>(capacity);

	for (size_t i {}; i < keys.capacity(); i++) {
		// skip empty slots and tombstones
		if (!occupiedSlots[i]) continue;

		// relocate into the new vectors
		const string & currKey = keys[i];
		int newIndex = mGetHash(currKey);
		newKeys[newIndex] = currKey;
		newValues[newIndex] = values[i];
		newIsOccupied[newIndex] = true;
	}
	// replace with the new tables
	keys = std::move(newKeys);
	values = std::move(newValues);
	occupiedSlots = std::move(newIsOccupied);
}


/**
 * @brief Adds a (key, value) pair or updates a value
 * 
 * @param rKey key
 * @param rValue value to update
 * @return true if added succesfully
 * @return false if not
 */
bool hashtable_oaddr::add(const string & rKey, string_view rValue) {
	if (hasKey(rKey)) return false;

	// initialize for probing
	int index = mGetHash(rKey);
	// save the first tombstone found
	int firstTombstoneIdx;
	bool foundTombstone = false;

	// Iterate while the slot is occupied and is not our key. Used for just for simplicity
	for (int x {}; occupiedSlots[index]; x++) {
		if (!foundTombstone && keys[index] == "" && "" == values[index]) {
			firstTombstoneIdx = index;
			foundTombstone = true;
		}
		index += mProbingFunction(x);
	}

	// take the slot of the first tombsone encoutered
	if (foundTombstone) index = firstTombstoneIdx;
	// if the slot is empty create a new (key,value) pair
	if (keys[index].empty()) keys[index] = rKey;
	values[index] = rValue;  // otherwise just update the value

	return true;
}


string hashtable_oaddr::get(const string & rKey) const {
	if (!hasKey(rKey)) return "";

	int index = mGetHash(rKey);

	for (int x {}; keys[index] != rKey; x++) {
		index += mProbingFunction(x);
	}

	return values[index];
}



/**
 * @brief this does what you think it does
 * 
 * @param rKey 
 * @return string 
 */
string hashtable_oaddr::remove(const string &rKey) {
	if (!hasKey(rKey)) return "";

	// otherwise the key is inside the table and start probing
	int index = mGetHash(rKey);

	// iterate until we find the key
	for (int x {}; keys[index] != rKey; x++) {
		if (!occupiedSlots[index]) break;
		index += mProbingFunction(x);
	}

	string target = values[index];
	keys[index] = "";
	values[index] = "";
	// we dont update its occupiedSlots place: lazy removing

	return target;
}