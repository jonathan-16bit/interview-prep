#include <iostream>
#include <vector>
using namespace std;

bool isPerfectv1(int num) {
  if (num <= 1)
    return false;

  int divisor_sum = 0;
  for (int i = 1; i < num; ++i) {
    if (num % i == 0)
      divisor_sum += i;
  }

  if (divisor_sum == num)
    return true;
  return false;
}

bool isPerfectv2(int num) {
  if (num <= 1)
    return false;

  int div_sum = 1;  // Since 1 is a divisor, initial sum is 1
  int i = 2;
  while (i <= num / i) {
    if (num % i == 0) {
      div_sum += i;

      if (i != num / i)
        div_sum += num / i;
    }

    i += 1;
  }

  return div_sum == num;
}

int main(void) {
  vector<int> tests = {3, 6, 17, 28, 262, 496};
  for (int test: tests) {
    if (isPerfectv2(test))
      cout << test << " is a perfect number" << endl;
    else
      cout << test << " is not a perfect number" << endl;
  }
}
