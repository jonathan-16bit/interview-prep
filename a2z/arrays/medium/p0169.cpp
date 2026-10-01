class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int maj_count = 0, candidate = nums[0];
    for (int n: nums) {
      if (maj_count == 0) {
        candidate = n;
      }

      if (n == candidate) maj_count += 1;
      else maj_count -= 1;
    }

    return candidate;
  }
};
