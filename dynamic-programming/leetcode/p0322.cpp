class Solution {
private:
  int minCoins(int i, vector<int> &dp, const vector<int> &coins) {
    if (i == 0)
      return dp[0] = 0;

    if (dp[i] != -1)
      return dp[i];

    int best = 1e4 + 1;
    for (int c: coins) {
      if (i - c < 0) continue;
      best = min(best, minCoins(i - c, dp, coins) + 1);
    }

    return dp[i] = best;
  }

public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, -1);

    int res = minCoins(amount, dp, coins);
    return (res == 1e4 + 1) ? -1 : res;
  }
};
