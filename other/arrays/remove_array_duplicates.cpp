#include <iostream>
#include <vector>
using namespace std;

void printArr(const vector<int> &arr, int st, int en) {
  cout << "[";
  for (int i = st; i <= en; ++i)
    cout << arr[i] << " ";
  cout << "]";
}

// Assumes sorted, non-empty arrays as input
int removeDup(vector<int> &arr) {
  int slow = 0, fast = 0;
  while (fast != arr.size()) {
    if (arr[slow] != arr[fast]) {
      slow += 1;
      swap(arr[slow], arr[fast]);
    }

    fast += 1;
  }

  return slow;
}

int main(void) {
  vector<vector<int>> tests = {
    {1, 2, 4, 8, 16},
    {1, 1, 2, 2, 4, 4, 8, 8},
  };

  for (vector<int>& test: tests) {
    printArr(test, 0, test.size() - 1);
    int bound = removeDup(test);
    cout << "\n";
    printArr(test, 0, bound);
    cout << "\n\n";
  }
}
