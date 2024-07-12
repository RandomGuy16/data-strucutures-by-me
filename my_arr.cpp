#include "my_arr.h"
#include <iostream>


my_arr::my_arr(int capacity) : capacity(capacity) {
    this->data = (int*) malloc(sizeof(int)*capacity);
}

my_arr::~my_arr() {
    free(this->data);
}

int my_arr::length() { return this->items; }

int my_arr::get_at(int index) {
    if (capacity <= index || index < 0) {
        std::cout << "Index out of bounds!" << std::endl;
        exit(1);
    }
    return this->data[index];
}

void my_arr::set_at(int index, int value) {
    if (capacity <= index || index < 0) {
        std::cout << "Index out of bounds!" << std::endl;
        exit(1);
    }
    this->data[index] = value;
    this->items = std::max(this->items, index + 1);
}

void my_arr::to_string() {
    std::cout << "[";
    for (size_t i = 0; i < this->capacity; i++) {
        std::cout << this->data[i];
        if (i < this->capacity - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}
