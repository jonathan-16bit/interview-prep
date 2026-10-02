#include <bits/stdc++.h>
using namespace std;

const int MAX_LEN = 1e6;

int dp[MAX_LEN];
int least(int i, const vector<int>& h) {
  // Cost to reach stone 0 is 0
  if (i == 0) return dp[0] = 0;

  // Only possible cost is from h[0] to h[1]
  if (i == 1) return dp[1] = abs(h[1] - h[0]);

  if (dp[i] != -1) 
    return dp[i];

  return dp[i] = min(abs(h[i] - h[i-1]) + least(i-1, h), abs(h[i] - h[i-2]) + least(i-2, h));
}

int main(void) {
  int n;
  cin >> n;

  vector<int> h(n);
  for (int i = 0; i < n; ++i)
    cin >> h[i];

  // Init
  memset(dp, -1, sizeof(dp));

  cout << least(n - 1, h);
}
