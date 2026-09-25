#include <iostream>
#include <vector>
using namespace std;

void printArr(const vector<int> &arr) {
  cout << "[";
  for (int elt: arr)
    cout << elt << " ";
  cout << "]";
}

void revArrInPlace(vector<int> &arr) {
  int lo = 0, hi = arr.size() - 1;
  while (lo < hi) {
    swap(arr[lo++], arr[hi--]);
  }
}

int main(void) {
  vector<vector<int>> tests = {
    {1, 2, 3, 4, 5, 6, 7, 8, 9},
    {1, 2, 4, 8, 16, 32, 64, 128}
  };

  for (vector<int>& test: tests) {
    printArr(test);
    cout << "\nReversed: ";
    revArrInPlace(test);
    printArr(test);
    cout << "\n\n";
  }
}
