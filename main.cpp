#include <iostream>
#include "my_arr.h"
#include "my_dynamic_arr.h"
#include "my_linked_list.h"
#include "my_dlinked_list.h"

using namespace std;


int main(int argc, char const *argv[])
{
  /*
  auto arr = my_arr(2);
  arr.set_at(0, 1);
  arr.set_at(1, 2);
  arr.get_at(0);
  arr.get_at(1);
  arr.to_string();
  
  auto d_arr = my_dynamic_arr();

  d_arr.get_at(5);
  d_arr.set_at(6, 1);
  d_arr.set_at(16, 28);
  d_arr.to_string();
  */

  auto l_list = my_linked_list();

  l_list.insert_last(2);
  l_list.to_string();
  l_list.insert_at(0, 1);
  l_list.to_string();
  l_list.insert_last(3);
  l_list.to_string();
  l_list.insert_last(5);
  l_list.to_string();
  l_list.insert_at(3, 4);
  l_list.to_string();
  l_list.insert_last(6);
  l_list.to_string();
  l_list.remove_last();
  l_list.to_string();
  l_list.remove_at(3);
  l_list.to_string();

  cout << "checkpoint" << endl;

  auto dl_list = my_dlinked_list();

  dl_list.insert_last(2);
  dl_list.to_string();
  dl_list.insert_at(0, 1);
  dl_list.to_string();
  dl_list.insert_last(3);
  dl_list.to_string();
  dl_list.insert_last(5);
  dl_list.to_string();
  dl_list.insert_at(3, 4);
  dl_list.to_string();
  dl_list.insert_last(6);
  dl_list.to_string();
  dl_list.remove_last();
  dl_list.to_string();
  dl_list.remove_at(3);
  dl_list.to_string();

  return 0;
}
