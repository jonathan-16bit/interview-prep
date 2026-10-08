#include <bits/stdc++.h>
using namespace std; 

void print_ascending(int n) {
  if (n == 0) {
    return;
  }

  print_ascending(n - 1);
  cout << n << " ";
}

int main() {
  int num;
  cout << "Enter number to print sequence till: ";
  cin >> num;

  cout << "Sequence: " << endl;
  print_ascending(num);
  cout << endl;
}
