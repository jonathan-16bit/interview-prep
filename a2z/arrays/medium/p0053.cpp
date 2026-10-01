class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int sub = -1e9, best = -1e9;
    for (int n: nums) {
      sub = max(n, sub + n);
      best = max(best, sub);
    }

    return best;
  }
};
