class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    int len = nums.size();
    int closest = nums[0] + nums[1] + nums[2];
    sort(nums.begin(), nums.end());

    for (int st = 0; st < len; ++st) {
      int lo = st + 1, hi = len - 1;

      while (lo < hi) {
        int curr = nums[st] + nums[lo] + nums[hi];
        if (abs(curr - target) < abs(closest - target))
          closest = curr;

        if (curr == target)
          return curr;
        if (curr < target)
          lo += 1;
        else
          hi -= 1;
      }
    }

    return closest;
  }
};
