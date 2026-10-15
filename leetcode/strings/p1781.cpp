// O(26 * N^2) = O(N^2) time
// O(26) = O(1) auxiliary space
class Solution {
public:
  int beautySum(string s) {
    int beauty = 0;
    // Extend each substring while maintaining character frequencies
    for (int st = 0; st < s.size(); ++st) {
      vector<int> freq(26, 0);
      int maxFreq = 0;

      for (int i = st; i < s.size(); ++i) {
        freq[s[i] - 'a'] += 1;

        // Only the added char's count increases, so we update maxFreq directly
        maxFreq = max(maxFreq, freq[s[i] - 'a']);

        // Recompute the minimum (nonzero) freq, since it may inc or dec as we extend
        int minFreq = 501;
        for (int alpha = 0; alpha < 26; ++alpha) {
          if (freq[alpha] == 0) continue;
          minFreq = min(minFreq, freq[alpha]);
        }

        beauty += maxFreq - minFreq;
      }
    }

    return beauty;
  }
};
