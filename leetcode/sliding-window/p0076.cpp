// O(N+M) time
class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> need;
    for (char ch: t) {
      need[ch] += 1;
    }
    int req_sat = need.size();

    unordered_map<char, int> window;
    int lo = 0, satisfied = 0, best = s.size() + 1;
    string res = "";
    for (int hi = 0; hi < s.size(); ++hi) {
      if (need.find(s[hi]) == need.end())
        continue;

      window[s[hi]] += 1;
      if (window[s[hi]] == need[s[hi]])
        satisfied += 1;

      while (satisfied == req_sat) {
        if (need.find(s[lo]) == need.end()) {
          lo += 1;
          continue;
        }

        if (hi - lo + 1 < best) {
          best = hi - lo + 1;
          res = s.substr(lo, hi - lo + 1);
        }

        window[s[lo]] -= 1;
        if (window[s[lo]] < need[s[lo]])
          satisfied -= 1;

        lo += 1;
      }

    }

    return res;
  }
};
