#ifndef MY_QUEUE
#define MY_QUEUE

#include "my_linked_list.h"


class my_queue {
private:
  my_linked_list data;

public:
  my_queue();
  ~my_queue();

  int is_empty();

  void enqueue(int value);

  int dequeue();
  
  int peek();
  
  void to_string();

};

#endif

