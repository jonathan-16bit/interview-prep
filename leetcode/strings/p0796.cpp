// O(N^2) time for bruteforce string matching
// O(N) space for (s+s) construction
class Solution {
public:
  bool rotateString(string s, string goal) {
    if (s.size() != goal.size()) return false;

    int len = s.size();
    // goal must be a substring of (s + s)
    string comb = s + s;
    for (int off = 0; off < len; ++off) {
      // Substring matching
      int i = 0;
      while (i < len && goal[i] == comb[off + i]) {
        i += 1;
      }
      if (i == len)
        return true;
    }

    return false;
  }
};
