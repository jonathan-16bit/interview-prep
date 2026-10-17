// O(N) time and space
class Solution {
private:
  int atMost(vector<int>& nums, int k) {
    if (k == 0)
      return 0;

    unordered_map<int, int> freq;
    int lo = 0, distinct = 0, count = 0;
    for (int hi = 0; hi < nums.size(); ++hi) {
      if (freq[nums[hi]] == 0)
        distinct += 1;
      freq[nums[hi]] += 1;

      while (distinct > k) {
        freq[nums[lo]] -= 1;
        if (freq[nums[lo]] == 0)
          distinct -= 1;
        lo += 1;
      }

      count += (hi - lo + 1);
    }

     return count;
  }

public:
  int subarraysWithKDistinct(vector<int>& nums, int k) {
    return atMost(nums, k) - atMost(nums, k - 1);
  }
};
