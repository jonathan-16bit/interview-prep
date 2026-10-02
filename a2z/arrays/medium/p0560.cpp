class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> pref_map = {{0, 1}};
    int pref_sum = 0, count = 0;
    for (int n: nums) {
      pref_sum += n;

      int need = pref_sum - k;
      if (pref_map.find(need) != pref_map.end()) {
        count += pref_map[need];
      }

      pref_map[pref_sum] += 1;
    }

    return count;
  }
};
