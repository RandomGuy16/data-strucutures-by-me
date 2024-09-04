#include <iostream>
#include "my_linked_list.h"


my_linked_list::node::node() : value(0) {
}
my_linked_list::node::node(int value) : value(value) {
}
my_linked_list::node::~node() = default;

my_linked_list::my_linked_list() :
  head(nullptr), tail(nullptr) {
}
my_linked_list::~my_linked_list() {
  node * temp = nullptr;
  if (is_empty()) exit(0);
  for (node * trav = head; trav->next != nullptr; trav = temp) {
    temp = trav->next;
    delete trav;
  }
}

int my_linked_list::is_empty() {
  return size == 0;
}

int my_linked_list::get_size() {
  return size;
}

int my_linked_list::get_at(int index) {
  if (is_empty()) {
    throw std::runtime_error("Access empty list");
  }
  else if (index >= size) {
    throw std::runtime_error("Index out of bounds");
  }
  node * trav = head;
  for (size_t i = 0; i < index; i++) {
    trav = trav->next;
  }
  return trav->value;
}

void my_linked_list::insert_last(int value) {
  auto * new_node = new node(value);
  if (is_empty()) {
    head = tail = new_node;
  }
  else {
    tail->next = new_node;
    tail = new_node;
  }

  size++;
}

int my_linked_list::remove_last() {
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
    // start iterating from head
    node * trav = head;
    // until we are one node before tail
    for ( ; trav->next != tail; trav = trav->next);

    // then save tail value and set previous node's pointer to nullptr
    tail_value = tail->value;
    delete tail;
    tail = trav;
    tail->next = nullptr;
  }

  size--;
  return tail_value;
}

void my_linked_list::insert_first(int value) {
  if (is_empty()) {
    insert_last(value);
  }
  else {
    auto * new_node = new node(value);
    new_node->next = head;
    head = new_node;
    size++;
  }
}

int my_linked_list::remove_first() {
  if (is_empty()) {
    throw std::runtime_error("Deleting from empty list");
  }
  else if (size == 1) {
    return remove_last();
  }
  auto * temp = head;
  int target_value = temp->value;
  head = head->next;
  
  delete temp;
  size--;
  return target_value;
}

// look at this
// trav_n = traveler next
// trav_p = traveler previous
// trav_n is ahead of trav_p
void my_linked_list::insert_at(int index, int value) {
  if (size < index) {
    throw std::out_of_range("Index out of range");
  }
  else if (size == index) {
    insert_last(value);
    return;
  }
  else if (index == 0) {
    insert_first(value);
    return;
  }
  node * trav_n = head;
  node * trav_p = nullptr;
  auto * new_node = new node(value);

  // iterate all the way such that trav_p is previous to our new node
  // and trav_n is the next node to our new node
  for (size_t i = 0; i < index; i++) {
    trav_p = trav_n;
    trav_n = trav_n->next;
  }
  trav_p->next = new_node;
  new_node->next = trav_n;
  size++;
}

int my_linked_list::remove_at(int index) {
  if (index >= size) {
    throw std::out_of_range("Index out of range");
  }
  else if (size == 0) {
    throw std::runtime_error("Deleting from empty list");
  }
  else if (index == 0) {
    return remove_first();
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

  node * trav = head;
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

