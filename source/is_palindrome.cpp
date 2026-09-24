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

bool is_palindrome(int num) {
  int reversed = reverse(num);
  if (num == reversed) {
    return true;
  }

  return false;
}

int main(void) {
  int input1 = 123456789;
  int input2 = 123454321;

  cout << input1 << " is a palindrome: " << is_palindrome(input1) << endl;
  cout << input2 << " is a palindrome: " << is_palindrome(input2) << endl;
}
