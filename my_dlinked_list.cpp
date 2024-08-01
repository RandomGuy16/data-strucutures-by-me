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
  for (trav; trav->next != nullptr; trav = trav->next) {
    temp = trav->next;
    delete trav;
    trav = temp;
  }
}

int my_dlinked_list::is_empty() {
  return size == 0;
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

void my_dlinked_list::insert_at(int index, int value) {
  if (index > size) {
    throw std::out_of_range("Index out of range");
  }
  else if (is_empty() && index == 0) {
    head = tail = new node(value);
  }
  else if (index == size) insert_last(value);
  else {
    node * trav_n;
    node * trav_p;
    auto * new_node = new node(value);

    if (size/2 < index) {
      trav_p = tail;
      trav_n = nullptr;
      for (size_t i = size - 1; i != index; i--) {
        trav_n = trav_p;
        trav_p = trav_p->prev;
      }
      trav_p = trav_p->prev;
    }
    else {
      trav_n = head;
      trav_p = nullptr;
      for (size_t i = 0; i != index; i++) {
        trav_p = trav_n;
        trav_n = trav_n->next;
      }
      trav_n = trav_n->next;
    }
    new_node->next = trav_n;
    new_node->prev = trav_p;
    trav_p->next = new_node;
    trav_n->prev = new_node;
  }
  size++;
}

int my_dlinked_list::remove_at(int index) {
  if (index >= size) {
    throw std::out_of_range("Index out of range");
  }
  else if (size == 0) {
    throw std::runtime_error("Deleting from empty list");
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
  
  target = trav;
  target_value = target->value;
  trav = trav->prev;

  trav->next = target->next;
  target->next->prev = trav;

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

