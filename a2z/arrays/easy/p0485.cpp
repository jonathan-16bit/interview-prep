class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int best = 0, count = 0;
    for (int n: nums) {
      if (n == 0) {
        count = 0;
      } else {
        count += 1;
        best = max(best, count);
      }
    }

    return best;
  }
};
