#include <iostream>
#include "my_linked_list.h"


my_linked_list::node::node() : value(0) {
}
my_linked_list::node::node(int value) {
  this->value = value;
}
my_linked_list::node::~node() = default;

my_linked_list::my_linked_list() :
  head(nullptr), tail(nullptr) {
}
my_linked_list::~my_linked_list() {
  node * trav = head;
  node * temp = nullptr;
  for (trav; trav.next != nullptr; trav = trav.next) {
    temp = trav.next;
    delete trav;
    trav = temp;
  }
}

int my_linked_list::is_empty() {
  return size == 0;
}

void my_linked_list::push(int value) {
  node * new_node = new node(value);
  if (is_empty()) {
    head = tail = new_node;
  }
  else {
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
  }

  size++;
}

int my_linked_list::pop() {
  int tail_value = 0;
  if (is_empty()) {
    throw std::runtime_error("Deleting from empty list");
  }
  else if (size == 1) {
    tail_value = tail->value;
    delete tail;
    head = tail = nullptr;
  }
  else {
    node * temp = tail->prev;
    tail_value = tail->value;
    delete tail;
    temp->next = nullptr;
    tail = temp;
  }

  size--;
  return tail_value;
}

void my_linked_list::insert_at(int index, int value) {
  if (index > size) {
    throw std::out_of_range("Index out of range");
  }
  else if (is_empty() && index == 0) {
    head = tail = new node(value);
  }
  else {
    node * trav1;
    node * trav2;
    auto * new_node = new node(value);

    if (index > size/2) {
      trav1 = tail;
      trav2 = nullptr;
      for (size_t i = size; i != index; i--) {
        trav2 = trav1;
        trav1 = trav1->prev;
      }
      new_node->next = trav2;
      new_node->prev = trav1;
      trav1->next = new_node;
      trav2->prev = new_node;
    }
    else {
      trav1 = head;
      trav2 = nullptr;
      for (size_t i = 0; i != index; i++) {
        trav2 = trav1;
        trav1 = trav1->next;
      }
      new_node->next = trav1;
      new_node->prev = trav2;
      trav1->prev = new_node;
      trav2->next = new_node;
    }
  }
  size++;
}

int my_linked_list::remove_at(int index) {
  if (index >= size) {
    throw std::out_of_range("Index out of range");
  }
  else if (size == 0) {
    throw std::runtime_error("Deleting from empty list")
  }
  else {
    node * trav1 = head;
    node * trav2 = nullptr;
    for (size_t i = 0; i < index; i++) {
      trav2 = trav1;
      trav1 = trav1->next;
    }
    // points to the node we want to delete
    node * target = trav1;
    int target_value = target->value;
    // jump to the next one
    trav1 = trav1->next;
    // skip the node we want to delete
    trav2->next = trav1;

    delete target;
    size--;
    return target_value;
  }
}

void my_linked_list::to_string() {
  std::cout << "[";

  node * trav = head->next;
  // iterates over all the nodes, if no nodes just skips the loop
  for (size_t i = 0; i < size; i++) {
    // prints current nodes value and goes to the next one
    std::cout << trav->value;
    if (trav->next != nullptr) {
      std::cout << ", ";
    }
    trav = trav->next;
  }
  
  std::cout << "]" << std::endl;
}

