class Solution {
public:
  int rob(vector<int>& nums) {
    int len = nums.size();
    if (len == 0)
      return 0;
    if (len == 1)
      return nums[0];

    vector<int> dp(len);
    dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < len; ++i) {
      int take = nums[i] + dp[i - 2];
      int skip = dp[i - 1];
      dp[i] = max(take, skip);
    }

    return dp[len - 1];
  }
};
