#include <iostream>
#include <math.h>


using namespace std;

int main (int argc, char *argv[]) {
  double sum = 0;

  for (size_t i = 1; i <= 100; i++) {
    sum += (double)i/(i+1);
  }

  cout << "la suma de 1/2 + 2/3 + ... + 100/101 es: " << sum << endl;

  // finding euler god damn number
  
  long double euler = 0;
  for (int n = 1; n < 1000000; n++) {
    euler = pow(1 + 1/(double)n, n);
  }

  cout << "Una aproximación del número de euler es: " << euler << endl;

  return 0;
}

