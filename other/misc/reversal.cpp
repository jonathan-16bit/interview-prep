#include <iostream>
using namespace std;

int reverse(int num) {
  int rev = 0, digit;
  while (num > 0) {
    digit = num % 10;
    rev = rev * 10 + digit;
    num /= 10;
  }

  return rev;
}

int main(void) {
  int input = 123456789;
  int rev = reverse(input);
  cout << "Reverse of " << input << " is " << rev << endl;
}
