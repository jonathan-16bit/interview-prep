class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int len = nums.size();
    vector<vector<int>> res;

    sort(nums.begin(), nums.end());

    for (int st = 0; st < len; ++st) {
      if (st > 0 && nums[st] == nums[st - 1])
        continue;

      int lo = st + 1, hi = len - 1;
      while (lo < hi) {
        int sum = nums[st] + nums[lo] + nums[hi];
        
        if (sum < 0)
          lo += 1;
        else if (sum > 0)
          hi -= 1;
        else {
          res.push_back({nums[st], nums[lo], nums[hi]});
          lo += 1;
          hi -= 1;

          while (lo < hi && nums[lo] == nums[lo - 1])
            lo += 1;
          while (lo < hi && nums[hi] == nums[hi + 1])
            hi -= 1;
        }
      }
    }

    return res;
  }
};
