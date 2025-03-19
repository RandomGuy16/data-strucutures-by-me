#include <utility>
#include <vector>
#include <forward_list>
#include <string>
#include <string_view>
#include <functional>


#ifndef MY_HASHTABLE
#define MY_HASHTABLE

using std::string;
using std::string_view;
using std::pair;
using std::forward_list;
using std::vector;
using std::hash;

class my_hashtable {
private:
  // static fields
  constexpr static const double DEFAULT_LOAD_FACTOR = 0.75;
  static const int DEFAULT_SIZE = 3;

  // non static fields
  vector<forward_list<pair<string, string>>> table;
  int items;
  int threshold;
  int capacity = DEFAULT_SIZE;
  hash<string> hasher;

  // functions
  void resize_table();

  int get_hash(const string & key) const;

public:
  my_hashtable();
  my_hashtable(const string & key, const string & value);
  my_hashtable(my_hashtable &&) = default;
  my_hashtable(const my_hashtable &) = default;
  my_hashtable &operator=(my_hashtable &&) = default;
  my_hashtable &operator=(const my_hashtable &) = default;
  ~my_hashtable() = default;

  int size() const;

  bool empty() const;

  void add(string key, string value);

  bool has_key(const string & key) const;

  string get(const string & key) const;

	string remove(const string & key);
};


#endif // !MY_HASHTABLE
