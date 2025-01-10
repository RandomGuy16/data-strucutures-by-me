#include <iostream>
#include <memory>
#include "my_arr.h"
#include "my_dynamic_arr.h"
#include "my_linked_list.h"
#include "my_dlinked_list.h"
#include "my_stack.h"
#include "my_queue.h"
#include "my_pqueue.h"

using namespace std;


int main(int argc, char const *argv[])
{
  cout << "stack test section" << endl;

  auto mstack = my_stack();

  mstack.to_string();
  mstack.push(1);
  mstack.to_string();
  mstack.push(3);
  mstack.to_string();
  mstack.pop();
  mstack.to_string();
  mstack.push(2);
  mstack.to_string();
  mstack.push(3);
  mstack.to_string();
  mstack.push(4);
  mstack.to_string();
  mstack.pop();
  mstack.to_string();
  
  cout << "<-- queue implementation test -->" << endl;
  auto mqueue = my_queue();

  mqueue.to_string();
  mqueue.enqueue(1);
  mqueue.to_string();
  mqueue.enqueue(2);
  mqueue.to_string();
  mqueue.enqueue(3);
  mqueue.to_string();
  mqueue.dequeue();
  mqueue.to_string();
  cout << mqueue.peek() << endl;

	cout << "<-- priority queue implementation test -->" << endl;

	unique_ptr<my_pqueue<string>> pq = make_unique<my_pqueue<string>>();

  return 0;
}
