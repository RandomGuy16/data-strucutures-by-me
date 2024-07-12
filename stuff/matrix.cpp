#include <iostream>
#include "my_arr.h"

using namespace std;


int main(int argc, char const *argv[])
{
  int mtx_1[3][3], mtx_2[3][3];
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      cout << "Ingrese el numero para la matriz 1: ";
      cin >> mtx_1[i][j];
    }
  }
  
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      cout << "Ingrese el número para el array 2: ";
      cin >> mtx_2[i][j];
    }
  }
  
  cout << "array suma:" << endl;
  for (size_t i = 0; i < 3; i++) {
    cout << "[";
    for (size_t j = 0; j < 3; j++) {
      cout << mtx_1[i][j] + mtx_2[i][j];
      if (j + 1 < 3) cout << ", ";
    }
    cout << "]" << endl;
  }

  return 0;
}
