// O(N) time, O(1) space
class Solution {
private:
  int atMost(const vector<int>& nums, int goal) {
    // When original goal == 0, goal - 1 == -1
    if (goal < 0)
      return 0;

    int lo = 0, count = 0, sub = 0;
    for (int hi = 0; hi < nums.size(); ++hi) {
      sub += nums[hi];

      while (sub > goal)
        sub -= nums[lo++];

      // All suffixes ending at hi will have sum <= goal
      count += (hi - lo + 1);
    }

    return count;
  }

public:
  int numSubarraysWithSum(vector<int>& nums, int goal) {
    return atMost(nums, goal) - atMost(nums, goal - 1);
  }
};
