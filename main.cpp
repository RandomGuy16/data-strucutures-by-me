#include <iostream>
#include <memory>
#include <algorithm>
#include <unordered_map>
#include "my_unionfind.h"
#include "my_pqueue.h"

using namespace std;

bool is_tree() {
  // since is a tree, the nummber of edges and elements is
  // elemens - 1 = edges
  vector<string> nodes = {
    "A", "B", "C", "D", "E"
  };
  vector<vector<string>> edges = {
    {"A", "B"}, {"B", "C"}, {"C", "D"}, {"D", "E"}
  };
  // make a hashmap with nodes pointing to a certain index [0, n)
  unordered_map<basic_string<char>, int> nodes_to_index;
  for (int i = 0; i < nodes.size(); i++) {
    nodes_to_index[nodes[i]] = i;
  }

  // initialize the nodes using the array inside unionfind
  auto unionfind = make_unique<my_unionfind>(nodes.size());

  // iterate over each edge
  for (int i = 0; i < size(edges); i++) {
    string u = edges[i][0];
    string v = edges[i][1];
    if (!unionfind->unify(nodes_to_index.at(u), nodes_to_index.at(v))) {
      return false;
    }
  }

  int root = unionfind->find(nodes_to_index[nodes[0]]);
  // show the data
  unionfind->print_data();
  
  return all_of(nodes.begin(), nodes.end(), [&](string const & s) {
    return unionfind->find(nodes_to_index[s]) == root;
  });
  
}

int main(int argc, char const *argv[])
{
  cout << "union find tests section" << endl;
  cout << boolalpha;
  cout << "the given graph: A-B-C-D-E is a tree?: " << is_tree() << endl;

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

  cout << "inverted priority queue section" << endl;

  auto ipq = make_unique<my_pqueue<int>>(false);
	ipq->add(1);
	ipq->add(2);
	ipq->add(0);
	ipq->add(3);
	ipq->add(4);
	ipq->add(5);
	ipq->add(6);
	ipq->add(7);
	cout << ipq->poll() << endl;
  cout << boolalpha;
	cout << ipq->contains(8) << endl;
	cout << ipq->contains(6) << endl;
	cout << ipq->remove(6) << endl;
  cout << ipq->remove(3) << endl;
  for (size_t i = 0; ipq->get_size() > 0; i++) {
    cout << ipq->poll() << endl;
  }

  return 0;
}
