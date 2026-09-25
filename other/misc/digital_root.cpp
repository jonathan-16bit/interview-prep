#include <iostream>
#include <vector>

using namespace std;

int digitSum(int num) {
  int sum = 0;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }

  return sum;
}

int digitalRoot(int num) {
  while (num / 10 != 0) {
    num = digitSum(num);
  }

  return num;
}

int main(void) {
  vector<int> tests = {12345, 67890, 13579, 24680};
  for (int test: tests) {
    cout << "Digital root of " << test << " is: " << digitalRoot(test) << endl;
  }
}
