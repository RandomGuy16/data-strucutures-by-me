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
statuses(DEFAULT_SIZE),
items(0),
threshold(static_cast<int>(DEFAULT_SIZE*LOAD_FACTOR)),
capacity(DEFAULT_SIZE),
hasher()
{
}

hashtable_oaddr::hashtable_oaddr(const string & key, const string & value) :
keys(DEFAULT_SIZE),
values(DEFAULT_SIZE),
statuses(DEFAULT_SIZE),
items(0),
threshold(static_cast<int>(DEFAULT_SIZE*LOAD_FACTOR)),
capacity(DEFAULT_SIZE),
hasher()
{
	add(key, value);
}


int hashtable_oaddr::getSize() const { return items; }

bool hashtable_oaddr::isEmpty() const { return items == 0; }

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
	int keyHash = mGetHash(key);
	int index = keyHash;

	// use probing until we find the element
	while (statuses[index] != Status::FREE && keys[index] != key) {
		index = (keyHash + mProbingFunction(x))%capacity;
		x++;
	}

	// returns true if we found the value
	return keys[index] == key;
}


void hashtable_oaddr::mResizeTable() {
	capacity *= 2;
	threshold *= 2;  // since threshold = capacity*loaffactor and capacity = 2*capacity

	auto newKeys = vector<string>(capacity);
	auto newValues = vector<string>(capacity);
	auto newStatuses = vector<Status>(capacity);

	for (size_t i {}; i < keys.capacity(); i++) {
		// skip empty slots and tombstones
		if (statuses[i] == Status::FREE) continue;

		// relocate into the new vectors
		const string & currKey = keys[i];
		int newIndex = mGetHash(currKey);
		newKeys[newIndex] = currKey;
		newValues[newIndex] = values[i];
		newStatuses[newIndex] = Status::OCCUPIED;
	}
	// replace with the new tables
	keys = std::move(newKeys);
	values = std::move(newValues);
	statuses = std::move(newStatuses);
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
	// initialize for probing
	int x {};
	int keyHash = mGetHash(rKey);
	int index = mGetHash(rKey);
	
	// Iterate while the slot is occupied and is not a tombstone
	while (statuses[index] == Status::OCCUPIED && keys[index] != rKey) {
		index = (keyHash + mProbingFunction(x))%capacity;
		x++;
	}
	
	values[index] = rValue;  // update the value
	// if the slot is empty add the key
	if (statuses[index] == Status::FREE) {
		items++;
		keys[index] = rKey;
	}

	statuses[index] = Status::OCCUPIED;

	if (items >= threshold) mResizeTable();
	return true;
}


string hashtable_oaddr::get(const string & rKey) {
	if (!hasKey(rKey)) return "";

	int keyHash = mGetHash(rKey);
	int index = keyHash;

	// take advantage of lazy deletion
	int firstTombstoneIndex {};
	bool encounteredTombstone = false;

	// iterate
	for (int x {}; keys[index] != rKey; x++) {
		// if is the first tombstone
		if (!encounteredTombstone && statuses[index] == Status::TOMBSTONE) {
			firstTombstoneIndex = index;
			encounteredTombstone = true;
		}
		index = (keyHash + mProbingFunction(x))%capacity;
	}

	// if encountered a tombstone in the path, do the lazy removing
	if (encounteredTombstone) {
		keys[firstTombstoneIndex] = keys[index];
		values[firstTombstoneIndex] = values[index];
		statuses[firstTombstoneIndex] = Status::OCCUPIED;
		keys[index] = "";
		values[index] = "";
		statuses[index] = Status::TOMBSTONE;
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
	int x {};
	int keyHash = mGetHash(rKey);
	int index = keyHash;

	// iterate until we find the key
	while (keys[index] != rKey) {
		index = (keyHash + mProbingFunction(x))%capacity;
		x++;
	}

	string target = values[index];
	keys[index] = "";
	values[index] = "";
	statuses[index] = Status::TOMBSTONE;
	// we dont update its occupiedSlots place: lazy removing

	items--;
	return target;
}