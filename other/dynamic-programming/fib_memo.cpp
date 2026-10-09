#include <bits/stdc++.h>
using namespace std; 

long long fib_memo(int i, vector<long long> &fib) {
  if (i == 0 || i == 1) 
    return fib[i] = i;

  if (fib[i] != -1)
    return fib[i];

  return fib[i] = fib_memo(i - 1, fib) + fib_memo(i - 2, fib);
}

int main() {
  int num = 0;
  cout << "Enter number of Fibonacci sequence terms to print: ";
  if (!(cin >> num)) {
    cout << "Enter valid input\n";
    return -1;
  }

  constexpr int MaxTerms = 93;

  if (num <= 0) {
    cout << "Number of terms must be positive\n";
    return -1;
  }
  if (num > MaxTerms) {
    cout << "Excessive count may overflow\n";
    return -1;
  }


  vector<long long> fib(num, -1);
  fib_memo(num - 1, fib);
  cout << "Sequence: " << endl;
  for (long long f: fib)
    cout << f << " ";
  cout << endl;
}
