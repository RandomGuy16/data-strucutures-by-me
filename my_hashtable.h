#include <vector>

#ifndef MY_HASHTABLE
#define MY_HASHTABLE

class my_hashtable {
private:
  std::vector<int> data;
  int items;

public:
  my_hashtable();
  my_hashtable(my_hashtable &&) = default;
  my_hashtable(const my_hashtable &) = default;
  my_hashtable &operator=(my_hashtable &&) = default;
  my_hashtable &operator=(const my_hashtable &) = default;
  ~my_hashtable();

  void add(int key);

};

my_hashtable::my_hashtable() {
}

my_hashtable::~my_hashtable() {
}

#endif // !MY_HASHTABLE
