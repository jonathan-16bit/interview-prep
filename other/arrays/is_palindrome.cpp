#include <iostream>
#include <vector>
using namespace std;

void printArr(const vector<int> &arr) {
  cout << "[";
  for (int elt: arr)
    cout << elt << " ";
  cout << "]";
}

bool isPalindrome(vector<int> &arr) {
  int lo = 0, hi = arr.size() - 1;
  while (lo < hi) {
    if (arr[lo] != arr[hi]) 
      return false;
    lo += 1;
    hi -= 1;
  }

  return true;
}

int main(void) {
  vector<vector<int>> tests = {
    {1, 2, 4, 8, 4, 2, 1},
    {1, 2, 4, 4, 2, 1},
    {1, 2, 3, 4, 2, 1}
  };

  for (vector<int>& test: tests) {
    printArr(test);
    cout << "\nIs palindrome: " << (isPalindrome(test) ? "Yes" : "No");
    cout << "\n\n";
  }
}
