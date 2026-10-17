class Solution {
public:
  int maxScore(vector<int>& cardPoints, int k) {
    if (cardPoints.size() == k)
      return accumulate(cardPoints.begin(), cardPoints.end(), 0);

    int win_len = cardPoints.size() - k;
    int win_sum  = accumulate(cardPoints.begin(), cardPoints.begin() + win_len, 0);
    int min_win = win_sum;
    for (int i = win_len; i < cardPoints.size(); ++i) {
      win_sum += cardPoints[i];
      win_sum -= cardPoints[i - win_len];
      min_win = min(min_win, win_sum);
    }

    return accumulate(cardPoints.begin(), cardPoints.end(), 0) - min_win;
  }
};

/*
 * The idea:
 * Instead of choosing and skipping, we can look at the elements NOT picked
 * These elements would form a contiguous subarray
 *
 * We need to minimize that subarray, so we use a sliding window of size: len(cardPoints) - k,
 * and iterate over the whole array to find the smallest such subarray
 *
 * Finally return the difference of sum(cardPoints) and this smallest subarray
 */
