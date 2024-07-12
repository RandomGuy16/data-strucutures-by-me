#ifndef MY_DYNAMIC_ARR
#define MY_DYNAMIC_ARR

#include "my_arr.h"


class my_dynamic_arr {
  private:
  int capacity;
  my_arr * data;
  int items = 0;

  public:
  my_dynamic_arr();
  ~my_dynamic_arr();

  int length();

  int get_at(int index);

  void set_at(int index, int value);

  void to_string();

};

#endif
