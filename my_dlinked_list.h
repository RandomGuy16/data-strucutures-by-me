#ifndef MY_DLINKED_LIST
#define MY_DLINKED_LIST

#include <iostream>

class my_dlinked_list {
private:
  class node {
  public:
    node * next = nullptr;
    node * prev = nullptr;
    int value;

    node();
    node(int value);
    ~node();
  };
  node * head = nullptr;
  node * tail = nullptr;
  int size = 0;

public:
  my_linked_list();
  ~my_linked_list();

  int is_empty();

  void push(int value);
  
  int pop();
  
  void insert_at(int index, int value);
  
  int remove_at(int index);

  void to_string();

};

#endif

