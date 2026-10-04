#include <bits/stdc++.h>
using namespace std;

// 0/1 Knapsack
long long maxProfit(int i, vector<vector<long long>> &dp, const vector<int> &weight, const vector<long long> &value, int wt) {
  // No items left to consider, or no remaining capacity
  if (i < 0 || wt <= 0)
    return 0;

  // Only 0th item left to consider (pick if capacity permits)
  if (i == 0) {
    return dp[wt][0] = (weight[0] <= wt) ? value[0] : 0;
  }

  if (dp[wt][i] != -1)
    return dp[wt][i];

  // No pick
  long long skip = maxProfit(i - 1, dp, weight, value, wt);

  // Pick
  long long take = 0;
  if (weight[i] <= wt)
    take = value[i] + maxProfit(i - 1, dp, weight, value, wt - weight[i]);

  return dp[wt][i] = max(skip, take);
}

int main(void) {
  int n, w;
  cin >> n;
  cin >> w;

  vector<int> weight(n);
  vector<long long> value(n);
  for (int i = 0; i < n; ++i) {
    cin >> weight[i];
    cin >> value[i];
  }

  vector<vector<long long>> dp (w + 1, vector<long long>(n, -1));
  long long res = maxProfit(value.size() - 1, dp, weight, value, w);
  cout << res << endl;
}

/*
 * State: (i, wt)
 * Denotes the maximum profit obtainable using items 0..i with remaining capacity wt
 */
