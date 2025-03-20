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

class hashtable_oaddr {
private:
  // static fields
  constexpr static const double LOAD_FACTOR = 0.333;
  static const int DEFAULT_SIZE = 12;

  // non static fields
  vector<string> keys;
  vector<string> values;
  vector<bool> occupiedSlots;

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
   * @brief get a hash based on the capacity
   * 
   * @param key 
   * @return int 
   */
  int mGetHash(const string & key) const;

  /**
   * @brief Returns an offset for open addressing
   * 
   * @param x 
   * @return offset 
   */
  int mProbingFunction(int x) const;

  // resize
  void resize_table();


public:
  hashtable_oaddr();
  hashtable_oaddr(const string & key, const string & value);
  hashtable_oaddr(hashtable_oaddr &&) = default;
  hashtable_oaddr(const hashtable_oaddr &) = default;
  hashtable_oaddr &operator=(hashtable_oaddr &&) = default;
  hashtable_oaddr &operator=(const hashtable_oaddr &) = default;
  ~hashtable_oaddr() = default;

  int size() const;

  bool empty() const;

  bool hasKey(const string & key) const;

  bool add(const string &rKey, string_view rValue);

  string get(const string & key) const;

	string remove(const string &rKey);
};


#endif // !MY_HASHTABLE
