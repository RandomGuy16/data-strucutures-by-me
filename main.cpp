#include <iostream>
#include <memory>
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

	auto pq = make_unique<my_pqueue<int>>();
	pq->add(1);
	pq->add(2);
	pq->add(0);
	pq->add(3);
	pq->add(4);
	pq->add(5);
	pq->add(6);
	pq->add(7);
	cout << pq->poll() << endl;
  cout << boolalpha;
	cout << pq->contains(8) << endl;
	cout << pq->contains(6) << endl;
	cout << pq->remove(6) << endl;
  cout << pq->remove(3) << endl;
  for (size_t i = 0; pq->get_size() > 0; i++) {
    cout << pq->poll() << endl;
  }

  return 0;
}
