#include <bits/stdc++.h>
using namespace std;

// O(N^2) time
int lis(int ix, vector<int> &dp, const vector<int> &nums) {
  if (ix == 0) 
    return dp[0] = 1;

  if (dp[ix] != -1)
    return dp[ix];

  // At minimum, LIS length is 1 for any element  
  int best = 1;
  for (int k = ix - 1; k >= 0; k--) {
    // An LIS ending at k can be extended by nums[ix]
    if (nums[k] < nums[ix])
      best = max(best, lis(k, dp, nums) + 1);
  }

  return dp[ix] = best;
}

int main() {
  int n;
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; ++i)
    cin >> nums[i];

  vector<int> dp(n, -1);
  int lis_length = 1;
  for (int i = 0; i < nums.size(); ++i) {
    lis_length = max(lis_length, lis(i, dp, nums));
  }

  cout << lis_length << endl;
}
