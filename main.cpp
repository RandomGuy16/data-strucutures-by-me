#include <iostream>
#include "my_arr.h"
#include "my_dynamic_arr.h"

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
  d_arr.set_at(512, 56);
  d_arr.to_string();

  cout << "checkpoint" << endl;

  return 0;
}
