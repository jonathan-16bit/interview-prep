#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

/* 
 * A single call is O(1) time, since no other computation takes place
 * So the overall complexity is proportional to the number of nodes in the recursion tree
 * Each call can branch into 2 more calls, and the tree has depth ~N, giving O(2^N) time
 */
int fib_naive(int n) {
  if (n == 0 || n == 1) return n;
  return fib_naive(n - 1) + fib_naive(n - 2);
}

int main() {
  int n;
  cin >> n;
  cout << fib(n) << endl;
}
