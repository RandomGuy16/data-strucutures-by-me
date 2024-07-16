#ifndef MY_LINKED_LIST
#define MY_LINKED_LIST

#include <iostream>

class my_linked_list {
private:
  class node {
  public:
    node * next = nullptr;
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

  void push(int value);
  
  int pop();
  
  void insert_at(int index);
  
  void to_string();

};

#endif

