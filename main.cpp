#include <iostream>
#include <memory>
#include <algorithm>
#include <unordered_map>
#include "my_unionfind.h"

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

  return 0;
}
