// O(N) time, O(1) auxiliary space
class Solution {
public:
  string reverseWords(string s) {
    int lo = 0, i = 0, hi;
    for (hi = 0; hi < s.size(); ++hi) {
      if (s[hi] == ' ')
        continue;

      // Find bounds of single word
      lo = hi;
      while (hi + 1 < s.size() && s[hi + 1] != ' ')
        hi += 1;

      // Reverse word in-place
      reverse(s.begin() + lo, s.begin() + hi + 1);

      // Add 1 space between words
      // (Also avoids overwriting null-terminator)
      if (i > 0)
        s[i++] = ' ';

      // Overwrite from i onwards with reversed word
      for (int k = lo; k <= hi; k++) {
        s[i++] = s[k];
      }
    }

    // Take only first i chars and reverse 
    s.resize(i);
    reverse(s.begin(), s.end());
    return s;
  }
};
