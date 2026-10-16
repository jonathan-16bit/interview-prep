// O(26*N) = O(N) time, O(26) = O(1) space
class Solution {
public:
  int characterReplacement(string s, int k) {
    // Count of letters in current window
    vector<int> freq(26, 0);
    int lo = 0, best = 0;
    int max_freq = 0;
    for (int hi = 0; hi < s.size(); ++hi) {
      int ch = s[hi] - 'A';
      freq[ch] += 1;
      max_freq = max(max_freq, freq[ch]);

      // Shrink until the window needs at most k replacements
      while ((hi - lo + 1) - max_freq > k) {
        freq[s[lo] - 'A'] -= 1;
        lo += 1;

        // Recompute maximum frequency (since letter removal may modify it)
        max_freq = 0;
        for (int i = 0; i < 26; ++i)
          max_freq = max(max_freq, freq[i]);
      }

      best = max(best, hi - lo + 1);
    }

    return best;
  }
};
