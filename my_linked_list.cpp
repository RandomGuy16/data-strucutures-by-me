#include <iostream>
#include "my_linked_list.h"


my_linked_list::node::node() : value(0) {
}
my_linked_list::node::node(int value) {
  this->value = value;
}
my_linked_list::node::~node() {
  delete this->next;
}

my_linked_list::my_linked_list() :
  head(new node()), tail(new node()) {

}
my_linked_list::~my_linked_list() {
  delete head;
  delete tail;
}

void my_linked_list::push(int value) {
  node * new_node = new node(value);
  tail->next = new_node;
  if (size == 0) {
    head->next = new_node;
  }
}

int my_linked_list::pop() {
  node trav1 = head->next;
  while (trav1->next != tail) {
    trav1 = trav1->next;
  }
  tail_value = tail->value;
  
  delete tail;
  tail = trav1;
  tail->next = nullptr;

  return tail_value;
}

