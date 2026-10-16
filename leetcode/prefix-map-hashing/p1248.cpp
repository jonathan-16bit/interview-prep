// O(N) time and space
class Solution {
public:
  int numberOfSubarrays(vector<int>& nums, int k) {
    // k_count[i] = count of prev prefixes containing i odd nums
    unordered_map<int, int> k_count = {{0, 1}};
    int nice = 0, pref = 0;
    for (int n: nums) {
      pref += n % 2;

      if (pref >= k)
        nice += k_count[pref - k];

      k_count[pref] += 1;
    }

    return nice;
  }
};
