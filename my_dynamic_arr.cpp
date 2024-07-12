#include <iostream>
#include "my_dynamic_arr.h"


my_dynamic_arr::my_dynamic_arr() : capacity(8) {
  this->data = new my_arr(8);
}
my_dynamic_arr::~my_dynamic_arr() {
  delete this->data;
}

int my_dynamic_arr::length() {
  return this->items;
}

int my_dynamic_arr::get_at(int index) {
  return this->data->get_at(index);
}

void my_dynamic_arr::set_at(int index, int value) {
  if (index >= this->capacity) {
    // double the capacity until is greater than the index requested
    int new_capacity = 8;
    while (new_capacity <= index) {
      new_capacity *= 2;
    }
    this->capacity = new_capacity;  // re asign with new capacity
    
    // creates new array to put the content of the old array
    auto new_arr = new my_arr(this->capacity);
    for (int i = 0; i < this->data->length(); i++) {  // it returns data's length for safety
      new_arr->set_at(i, this->data->get_at(i));
    }
    // once deleted reasign the pointer
    delete this->data;
    this->data = new_arr;
  }
  data->set_at(index, value);
}

void my_dynamic_arr::to_string() {
  this->data->to_string();
}
