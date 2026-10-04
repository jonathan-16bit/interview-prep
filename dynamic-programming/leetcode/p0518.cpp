// Coin Change 2
class Solution {
private:
  int ways(int i, vector<vector<int>> &dp, int amount, const vector<int> &coins) {
    // Valid combination found
    if (amount == 0)
      return 1;

    // No more denominations left for a non-zero remaining amount
    if (i < 0)
      return 0;

    if (dp[amount][i] != -1)
      return dp[amount][i];

    int num_ways = 0;
    for (int diff = 0; diff <= amount; diff += coins[i]) {
      num_ways += ways(i - 1, dp, amount - diff, coins);
    }

    return dp[amount][i] = num_ways;
  }

public:
  int change(int amount, vector<int>& coins) {
    vector<vector<int>> dp(amount + 1, vector<int>(coins.size(), -1));
    return ways(coins.size() - 1, dp, amount, coins);
  }
};

/*
 * Try all possible multiples of each denomination (before moving onto the next one)
 * This helps avoid counting duplicates (by processing in fixed order)
 *
 * State: (i, amount) = number of ways to form amount using coins[0..i]
 */

/* -------- IMPROVED CODE -------- */
class Solution {
private:
  int ways(int i, vector<vector<int>> &dp, int amount, const vector<int> &coins) {
    // Valid combination found
    if (amount == 0)
      return 1;

    // No more denominations left for a non-zero remaining amount
    // Negative amounts imply the choice of coin is invalid
    if (i < 0 || amount < 0)
      return 0;

    if (dp[amount][i] != -1)
      return dp[amount][i];

    int num_ways = ways(i - 1, dp, amount, coins) + ways(i, dp, amount - coins[i], coins);
    return dp[amount][i] = num_ways;
  }

public:
  int change(int amount, vector<int>& coins) {
    vector<vector<int>> dp(amount + 1, vector<int>(coins.size(), -1));
    return ways(coins.size() - 1, dp, amount, coins);
  }
};

/*
 * Improvement over explicitly trying every multiples of coins[i] in the for-loop:
 * Make the logic skip/take, giving 2 branches from a given node (as opposed to O(A) branches)
 */
