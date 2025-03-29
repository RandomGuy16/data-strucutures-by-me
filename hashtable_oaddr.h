#include <utility>
#include <vector>
#include <string>
#include <string_view>
#include <functional>


#ifndef HASHTABLE_OADDR
#define HASHTABLE_OADDR

using std::string;
using std::string_view;
using std::pair;
using std::vector;
using std::hash;

/**
 * @class hashtable_oaddr
 * @brief A hash table implementation using open addressing with quadratic probing.
 */
class hashtable_oaddr {
private:
  // static fields
  constexpr static const double LOAD_FACTOR = 0.333;
  static const int DEFAULT_SIZE = 8;

  enum class Status {
    FREE, OCCUPIED, TOMBSTONE
  };

  // non static fields
  vector<string> keys;
  vector<string> values;
  vector<Status> statuses;

  int items;
  int threshold;
  double load_factor;
  int capacity = DEFAULT_SIZE;
  /**
   * @brief don't use this.
   * use the function mGetHash(string s) which is based on the capacity
   * 
   */
  hash<string> hasher;
  
  // functions

  
  /**
   * @brief Computes a hash value for the given key based on the current capacity.
   * 
   * @param key The key to hash.
   * @return int The hash value.
   */
  int mGetHash(const string & key) const;

  /**
   * @brief Computes the probing offset for quadratic probing.
   * 
   * @param x The current probing attempt number.
   * @return int The offset for the probing attempt.
   */
  int mProbingFunction(int x) const;

  /**
   * @brief Resizes the hash table when the load factor exceeds the threshold.
   */
  void mResizeTable();


public:
  /**
  * @brief Default constructor. Initializes an empty hash table.
  */
  hashtable_oaddr();
  /**
   * @brief Constructor that initializes the hash table with a single key-value pair.
   * 
   * @param key The key to insert.
   * @param value The value associated with the key.
   */
  hashtable_oaddr(const string & key, const string & value);
  hashtable_oaddr(hashtable_oaddr &&) = default;
  hashtable_oaddr(const hashtable_oaddr &) = default;
  hashtable_oaddr &operator=(hashtable_oaddr &&) = default;
  hashtable_oaddr &operator=(const hashtable_oaddr &) = default;
  ~hashtable_oaddr() = default;

  /**
   * @brief Returns the number of items in the hash table.
   * 
   * @return int The number of items.
   */
  int getSize() const;

  /**
   * @brief Checks if the hash table is empty.
   * 
   * @return true If the hash table is empty.
   * @return false If the hash table is not empty.
   */
  bool isEmpty() const;

  /**
   * @brief Checks if the given key exists in the hash table.
   * 
   * @param key The key to search for.
   * @return true If the key exists in the hash table.
   * @return false If the key does not exist in the hash table.
   */
  bool hasKey(const string & key) const;

  /**
   * @brief Adds a key-value pair to the hash table or updates the value if the key already exists.
   * 
   * @param rKey The key to insert or update.
   * @param rValue The value to associate with the key.
   * @return true If the key-value pair was added or updated successfully.
   * @return false If the operation failed.
   */
  bool add(const string &rKey, string_view rValue);

  /**
   * @brief Retrieves the value associated with the given key.
   * 
   * @param key The key to search for.
   * @return string The value associated with the key, or an empty string if the key does not exist.
   */
  string get(const string & key);

  /**
   * @brief Removes the key-value pair associated with the given key.
   * 
   * @param rKey The key to remove.
   * @return string The value associated with the removed key, or an empty string if the key does not exist.
   */
	string remove(const string &rKey);
};


#endif // !MY_HASHTABLE
