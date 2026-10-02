#include <bits/stdc++.h>
using namespace std;

const int MAX_NUM = 1e9;
const int MAX_LEN = 1e6;
int dp[MAX_LEN];

// O(N*K) time, O(N) space
int least(int i, int k, const vector<int>& h) {
  if (i == 0)
    return dp[i] = 0;

  if (dp[i] != -1) 
    return dp[i];

  int best = MAX_NUM;
  for (int off = 1; off <= min(i, k); ++off)
    best = min(best, abs(h[i] - h[i - off]) + least(i - off, k, h));

  return dp[i] = best;
}

int main(void) {
  int n, k;
  cin >> n;
  cin >> k;

  vector<int> h(n);
  for (int i = 0; i < n; ++i)
    cin >> h[i];

  // Init
  memset(dp, -1, sizeof(dp));

  cout << least(n - 1, k, h);
}
