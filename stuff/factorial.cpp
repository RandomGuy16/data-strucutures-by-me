#include <iostream>
#include "my_arr.h"

using namespace std;


int main(int argc, char const *argv[])
{
  int num = 0;
  cout << "Ingrese el de que número quiere tener el factorial\n> ";
  cin >> num;
  
  long result = 1;
  
  cout << "Tamaño en bytes de long: " << sizeof(long) << endl;
  cout << "Tamaño en bytes de long long: " << sizeof(long long) << endl;

  // the factorial thing
  for (size_t i = 1; i <= num; i++) {
    result *= i;
  }

  cout << "el factorial es: " << result << endl;

  return 0;
}
