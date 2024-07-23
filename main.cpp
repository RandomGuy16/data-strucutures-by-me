#include <iostream>
#include "my_arr.h"
#include "my_dynamic_arr.h"
#include "my_linked_list.h"

using namespace std;


int main(int argc, char const *argv[])
{
  
  auto arr = my_arr(2);
  arr.set_at(0, 1);
  arr.set_at(1, 2);
  arr.get_at(0);
  arr.get_at(1);
  arr.to_string();
  
  auto d_arr = my_dynamic_arr();

  d_arr.get_at(5);
  d_arr.set_at(6, 1);
  d_arr.set_at(16, 56);
  d_arr.to_string();

  auto l_list = my_linked_list();

  l_list.push(1);
  l_list.push(2);
  l_list.push(3);
  l_list.push(5);
  l_list.insert_at(3, 4);
  l_list.push(6);
  l_list.pop();

  l_list.remove_at(3);

  cout << "checkpoint" << endl;

  return 0;
}
