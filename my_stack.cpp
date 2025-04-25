#include "my_stack.h"


my_stack::my_stack() : data(my_linked_list()) {

}
my_stack::~my_stack() = default;

int my_stack::is_empty() {
    return data.is_empty();
}

void my_stack::push(int value) {
    data.insert_first(value);
}

int my_stack::pop() {
    return data.remove_first();
}

int my_stack::peek() {
    return data.get_at(0);
}
void my_stack::to_string() {
    data.to_string();
}
