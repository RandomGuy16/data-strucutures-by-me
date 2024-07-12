#include <iostream>
#include <algorithm>

using namespace std;


int main(int argc, char const *argv[])
{
  int num_arr[10] {};

  for (size_t i = 0; i < sizeof(num_arr)/sizeof(int); i++) {
    cin >> num_arr[i];
  }

  sort(num_arr, num_arr + 10);

  cout << "sorted array: [";
  for (size_t i = 0; i < sizeof(num_arr)/sizeof(int); i++) {
    cout << num_arr[i];
    if (i + 1 < sizeof(num_arr)/sizeof(int)) {
      cout << ", ";
    }
  }
  cout << "]" << endl;

  return 0;
}
