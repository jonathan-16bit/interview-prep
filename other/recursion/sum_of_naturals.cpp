#include <bits/stdc++.h>
using namespace std;

int natural_sum(int n) {
  if (n == 0)
    return 0;

  return n + natural_sum(n - 1);
}

int main() {
  cout << "Enter number to sum till: ";
  int num;
  cin >> num;

  cout << "Sum of naturals till " << num << ": " << natural_sum(num) << endl;
}
