class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    size_t bound = 201;
    for (const auto& s: strs)
      bound = min(bound, s.size());

    if (bound == 0)
      return "";

    int hi = -1;
    for (int i = bound - 1; i >= 0; i--) {
      char curr = '0';  // since only lowercase alphabet is expected
      bool isCommon = true;
      for (const auto& s: strs) {
        curr = (curr == '0') ? s[i] : curr;
        if (curr != s[i]) {
          isCommon = false;
          break;
        }
      }

      if (isCommon && hi == -1)
        hi = i;
      if (!isCommon)
        hi = -1;
    }

    if (hi == -1)
      return "";
    return strs[0].substr(0, hi + 1);
  }
};
