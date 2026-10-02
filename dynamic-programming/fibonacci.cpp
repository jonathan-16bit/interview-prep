#include <bits/stdc++.h>
using namespace std;

/* 
 * A single call is O(1) time, since no other computation takes place
 * So the overall complexity is proportional to the number of nodes in the recursion tree
 * Each call can branch into 2 more calls, and the tree has depth ~N, giving O(2^N) time
 */
int fib_naive(int n) {
  if (n == 0 || n == 1) return n;
  return fib_naive(n - 1) + fib_naive(n - 2);
}

// Memoisation
const int N = 100;
int fib[N];
int fib_memo(int n) {
  if (n == 0 || n == 1) return fib[n] = n;

  // If already computed
  if (fib[n] != -1) 
    return fib[n];

  // Compute and store
  return fib[n] = fib_memo(n - 2) + fib_memo(n - 1);
}

int main() {
  // -1 means "not computed" (it is also an impossible fib value)
  memset(fib, -1, sizeof(fib));

  int n;
  cin >> n;
  cout << fib_naive(n) << endl;
  cout << fib_memo(n) << endl;
}
