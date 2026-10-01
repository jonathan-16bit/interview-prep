class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int best = 0, lowest = 1e4;
    for (int n: prices) {
      lowest = min(lowest, n);
      best = max(best, n - lowest);
    }

    return best;
  }
};
