#include <iostream>
#include <vector>
using namespace std;

bool isSpyNumber(int num) {
  int sum = 0, product = 1, last;
  while (num > 0) {
    last = num % 10;
    sum += last;
    product *= last;
    num /= 10;
  }

  return sum == product;
}

int main(void) {
  vector<int> tests = {123, 456, 789, 1124, 1214, 1234, 5678};

  for (int test: tests) {
    if (isSpyNumber(test))
      cout << test << " is a spy number\n";
    else
      cout << test << " is not a spy number\n";
  }
}
