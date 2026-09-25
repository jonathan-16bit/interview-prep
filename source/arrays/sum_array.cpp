#include <iostream>
#include <vector>
using namespace std;

int arraySum(vector<int> arr) {
  int sum = 0;
  for (int i = 0; i < arr.size(); ++i)
    sum += arr[i];
  return sum;
}

void printArr(vector<int> arr) {
  cout << "[";
  for (int elt: arr)
    cout << elt << " ";
  cout << "]";
}

int main(void) {
  vector<vector<int>> tests = {
    {1, 2, 3, 4, 5, 6, 7, 8, 9},
    {1, 2, 4, 8, 16, 32, 64, 128}
  };

  for (vector<int> test: tests) {
    printArr(test);
    cout << " of sum: " << arraySum(test) << endl;
  }
}
