// Longest Increasing Subsequence

class Solution {
  // O(N^2) time
private:
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


public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), -1);
    int longest = 0;
    for (int i = 0; i < nums.size(); ++i)
      longest = max(longest, lis(i, dp, nums));

    return longest;
  }
};
