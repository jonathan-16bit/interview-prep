#include <bits/stdc++.h>
using namespace std; 

// 0-indexed
vector<long long> fib_tab(int n) {
  vector<long long> fib(n + 1);

  fib[0] = 0;
  if (n >= 1)
    fib[1] = 1;

  for (int i = 2; i <= n; ++i)
    fib[i] = fib[i - 1] + fib[i - 2];

  return fib;
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


  vector<long long> fib = fib_tab(num - 1);
  cout << "Sequence: " << endl;
  for (long long f: fib)
    cout << f << " ";
  cout << endl;
}
