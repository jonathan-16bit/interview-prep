// O(N) time, O(1) space
class Solution {
public:
  int numberOfSubstrings(string s) {
    vector<int> freq(3, 0);
    int hi = 0, lo = 0, count = 0;

    while (lo < s.size()) {
      // If the product of all freqs = 0, then at least one is 0
      while (hi < s.size() && (freq[0] * freq[1] * freq[2] == 0)) {
        freq[s[hi] - 'a'] += 1;
        hi += 1;
      }
      
      if (freq[0] * freq[1] * freq[2] == 0)
        break;

      count += (s.size() - hi + 1);
      freq[s[lo++] - 'a'] -= 1;
    }

    return count;
  }
};

/*
 * Invariant: 
 * For a fixed lo, find the smallest hi such that [lo, hi) contains at least 1 of each of a,b,c
 * Then every substring ending at hi-1 to len-1 is valid (and we add all these to the count)
 */
