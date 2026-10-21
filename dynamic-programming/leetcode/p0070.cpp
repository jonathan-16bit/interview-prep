class Solution {
public:
  int climbStairs(int n) {
    if (n == 1 || n == 2) return n;

    int step2 = 1, step1 = 2;
    int req;
    for (int i = 3; i <= n; ++i) {
      req = step2 + step1;
      step2 = step1;
      step1 = req;
    }

    return req;
  }
};
