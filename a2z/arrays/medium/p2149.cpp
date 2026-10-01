// O(N) space and time
class Solution {
public:
  vector<int> rearrangeArray(vector<int>& nums) {
    int pos = -2, neg = -1;
    vector<int> res(nums.size());
    for (int n: nums) {
      if (n > 0)
        res[pos = pos + 2] = n;
      else
        res[neg = neg + 2] = n;
    }

    return res;
  }
};
