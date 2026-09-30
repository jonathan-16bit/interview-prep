class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> last_occ;

    int lo = 0, best = 0;
    for (int hi = 0; hi < s.size(); ++hi) {
      char c = s[hi];
      if (last_occ.find(c) == last_occ.end()) {
        last_occ[c] = -1;
      }

      if (last_occ[c] >= lo) {
        lo = last_occ[c] + 1;
      }

      best = max(best, hi - lo + 1);
      last_occ[c] = hi;
    }

    return best;
  }
};
