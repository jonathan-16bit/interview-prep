class Solution {
public:
  int longestOnes(vector<int>& nums, int k) {
    int count_1 = 0, best = 0, lo = 0;
    for (int hi = 0; hi < nums.size(); ++hi) {
      count_1 += nums[hi];

      while ((hi - lo + 1) - count_1 > k) {
        count_1 -= nums[lo];
        lo += 1;
      }

      best = max(best, hi - lo + 1);
    }

    return best;
  }
};
