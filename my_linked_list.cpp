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
  try {
    // if we have at least 1 node in the linked list
    tail->next->next = new_node;
  }
  catch (const std::exception&) {
    // to nothing
  }
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

void my_linked_list::insert_at(int index, int value) {
  node trav1 = head;
  node trav2 = head->next;

  node * temp_ = new node(value);

  for (size_t i = 0; i < index - 1; i++) {
    trav1 = trav1->next;
    trav2 = trav2->next;
  }
  temp_->next = trav2;
  trav1->next = temp_;
}

int my_linked_list::remove_at(int index, int value) {
  node trav1 = head;
  node trav2 = head->next;

  for (size_t i = 0; i < index - 1; i++) {
    trav1 = trav1->next;
    trav2 = trav2->next;
  }
  // points to the node we want to delete
  node temp = trav2;
  // jump to the next one
  trav2 = trav2->next;
  // make temp stop pointing to the linked list
  temp->next = nullptr;
  // skip te node we want to delete
  trav1->next = trav2;

  delete temp;
}

void my_linked_list::to_string() {
  std::cout << "[";

  node trav = head->next();
  // iterates over all the nodes, if no nodes just skips the loop
  for (size_t i = 0; i < size; i++) {
    // prints current nodes value and goes to the next one
    std::cout << trav->value;
    if (trav->next != nullptr) {
      cout << ", ";
    }
    trav = trav->next;
  }
  
  std::cout << "]" << endl;
}

