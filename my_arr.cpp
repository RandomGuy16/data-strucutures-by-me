#include "my_arr.h"
#include <iostream>


my_arr::my_arr(int capacity) : capacity(capacity) {
  this->data = (int*) malloc(sizeof(int)*capacity);
}

my_arr::~my_arr() {
  free(this->data);
}

int my_arr::length() { return items; }

int my_arr::get_at(int index) {
  if (capacity <= index || index < 0) {
    std::cout << "Index out of bounds!" << std::endl;
    exit(1);
  }
  return data[index];
}

void my_arr::set_at(int index, int value) {
  if (capacity <= index || index < 0) {
    std::cout << "Index out of bounds!" << std::endl;
    exit(1);
  }
  data[index] = value;
  items = std::max(items, index + 1);
}

void my_arr::to_string() {
  std::cout << "[";
  for (size_t i = 0; i < capacity; i++) {
    std::cout << data[i];
    if (i < capacity - 1) std::cout << ", ";
  }
  std::cout << "]" << std::endl;
}

