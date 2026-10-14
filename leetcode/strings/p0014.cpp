class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    size_t bound = strs[0].size();
    for (const auto& s: strs)
      bound = min(bound, s.size());

    if (bound == 0) return "";

    // Compare each char position across all strings
    for (int i = 0; i < bound; ++i) {
      for (const auto& s: strs) {
        if (s[i] != strs[0][i])
          return s.substr(0, i);
      }
    }

    // Deals with single-word case
    // and when we run out of chars to compare before reaching mismatch
    return strs[0].substr(0, bound);
  }
};
