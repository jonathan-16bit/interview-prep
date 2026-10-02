class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    if (nums.size() == 0)
      return 0;

    unordered_set<int> contained;
    for (int n: nums)
      contained.insert(n);

    int best = 0;
    for (int n: contained) {
      if (contained.find(n - 1) != contained.end())
        continue;

      int count = 1, num = n;
      while (contained.find(num + 1) != contained.end()) {
        count += 1;
        num += 1;
      }
      best = max(best, count);
    }

    return best;
  }
};
