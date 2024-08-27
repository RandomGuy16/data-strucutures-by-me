#ifndef MY_STACK
#define MY_STACK

#include "my_linked_list.h"


class my_stack {
private:
  my_linked_list data;

public:
  my_stack();
  ~my_stack();

  int is_empty();

  void push(int value);

  int pop();
  
  int peek();
  
  void to_string();

};

#endif

