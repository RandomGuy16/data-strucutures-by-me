#include "my_queue.h"


my_queue::my_queue() : data(my_linked_list()) {

}
my_queue::~my_queue() = default;

int my_queue::is_empty() {
    return data.is_empty();
}

void my_queue::enqueue(int value) {
    data.insert_last(value);
}

int my_queue::dequeue() {
    return data.remove_first();
}

int my_queue::peek() {
    return data.get_at(0);
}
void my_queue::to_string() {
    data.to_string();
}
