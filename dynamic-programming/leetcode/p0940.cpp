// O(N) time and space
class Solution {
public:
  int distinctSubseqII(string s) {
    // dp[i] = num of distinct non-empty subseq formed using s[0..i-1]
    vector<int> dp(s.size() + 1, 0);

    // last[ch] = most recent 0-based index of character ch
    vector<int> last(26, -1);
    constexpr int MOD = 1'000'000'007;

    // dp[0] = 0
    for (int i = 1; i <= s.size(); ++i) {
      int ch = s[i - 1] - 'a';

      // If ch appeared before at index j, appending ch to subseq formed
      // before j creates duplicates. So we subtract those, including the one
      // formed by appending ch to the empty subseq
      int off = last[ch] == -1 ? 0 : dp[last[ch]] + 1;

      // Keep existing subseqs, append ch to each, add ch alone, and subtract duplicates
      dp[i] = (2LL * dp[i - 1] + 1 - off + MOD) % MOD;
      last[ch] = i - 1;
    }

    return dp[s.size()];
  }
};
