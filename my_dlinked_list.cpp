#include <iostream>
#include "my_dlinked_list.h"


my_dlinked_list::node::node() : value(0) {
}
my_dlinked_list::node::node(int value) {
  this->value = value;
}
my_dlinked_list::node::~node() = default;

my_dlinked_list::my_dlinked_list() :
  head(nullptr), tail(nullptr) {
}
my_dlinked_list::~my_dlinked_list() {
  node * trav = head;
  node * temp = nullptr;
  if (is_empty()) {
    return;
  }
  for (; trav->next != nullptr; trav = temp) {
    temp = trav->next;
    delete trav;
  }
}

int my_dlinked_list::is_empty() {
  return size == 0;
}

void my_dlinked_list::insert_first(int value) {
  if (is_empty()) {
    insert_last(value);
  }
  else {
    auto * new_node = new node(value);
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
    size++;
  }
}

int my_dlinked_list::remove_first() {
  if (is_empty()) {
    throw std::runtime_error("Deleting from empty list");
  }
  else if (size == 1) {
    return remove_last();
  }
  node * temp = head;
  int target_value = temp->value;
  head = head->next;
  head->prev = nullptr;

  delete temp;
  size--;
  return target_value;
}

void my_dlinked_list::insert_last(int value) {
  auto * new_node = new node(value);
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

int my_dlinked_list::remove_last() {
  int tail_value;
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

void my_dlinked_list::insert_at(int index, int value) {
  if (index > size) {
    throw std::out_of_range("Index out of range");
  }
  else if (index == size) {
    insert_last(value);
  }
  else if (index == 0) {
    insert_first(value);
    return;
  }
  else {
    node * trav_n;
    node * trav_p;
    auto * new_node = new node(value);

    if (size/2 < index) {
      trav_p = tail;
      trav_n = nullptr;
      for (size_t i = size; i != index; i--) {
        trav_n = trav_p;
        trav_p = trav_p->prev;
      }
    }
    else {
      trav_p = nullptr;
      trav_n = head;
      for (size_t i = 0; i != index; i++) {
        trav_p = trav_n;
        trav_n = trav_n->next;
      }
    }
    new_node->next = trav_n;
    new_node->prev = trav_p;
    trav_p->next = new_node;
    trav_n->prev = new_node;
    
    size++;
  }
}

int my_dlinked_list::remove_at(int index) {
  if (index >= size) {
    throw std::out_of_range("Index out of range");
  }
  else if (is_empty()) {
    throw std::runtime_error("Deleting from empty list");
  }
  else if (index == 0) {
    return remove_first();
  }
  
  node * trav = size/2 < index ? tail : head;
  node * target = nullptr;
  int target_value;

  if (size/2 < index) {
    for (size_t i = size - 1; i != index; i--) {
      trav = trav->prev;
    }
  }
  else {
    for (size_t i = 0; i != index; i++) {
      trav = trav->next;
    }
  }
  
  node * next_node = trav->next;
  node * prev_node = trav->prev;
  target = trav;
  target_value = target->value;

  prev_node->next = next_node;
  next_node->prev = prev_node;

  delete target;
  size--;
  return target_value;
}

void my_dlinked_list::to_string() {
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

