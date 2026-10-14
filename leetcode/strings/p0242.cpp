class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    // Track character-count differences
    // Anagrams leave all differences at 0
    vector<int> freq(26, 0);
    for (int i = 0; i < s.size(); ++i) {
      freq[s[i] - 'a'] += 1;
      freq[t[i] - 'a'] -= 1;
    }

    for (int f: freq)
      if (f != 0) return false;
    return true;
  }
};
