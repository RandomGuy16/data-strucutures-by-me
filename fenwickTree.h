#ifndef FENWICKTREE

#define FENWICKTREE


class fenwickTree {
private:
  int items {};


public:
  fenwickTree();
  fenwickTree(fenwickTree &&) = default;
  fenwickTree(const fenwickTree &) = default;
  fenwickTree &operator=(fenwickTree &&) = default;
  fenwickTree &operator=(const fenwickTree &) = default;
  ~fenwickTree();
  
};



#endif

