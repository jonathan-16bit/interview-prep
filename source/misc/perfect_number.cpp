#include <iostream>
#include <vector>
using namespace std;

bool isPerfect(int num) {
  int divisor_sum = 0;
  for (int i = 1; i < num; ++i) {
    if (num % i == 0)
      divisor_sum += i;
  }

  if (divisor_sum == num)
    return true;
  return false;
}

int main(void) {
  vector<int> tests = {3, 6, 17, 28, 262, 496};
  for (int test: tests) {
    if (isPerfect(test))
      cout << test << " is a perfect number" << endl;
    else
      cout << test << " is not a perfect number" << endl;
  }
}
