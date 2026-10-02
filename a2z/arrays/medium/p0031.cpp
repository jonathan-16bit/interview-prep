class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    int piv = -1;

    for (int i = nums.size() - 2; i >=0; i--) {
      if (nums[i] < nums[i + 1]) {
        piv = i;
        break;
      }
    }

    if (piv == -1) {
      reverse(nums.begin(), nums.end());
      return;
    }

    for (int i = nums.size() - 1; i > piv; i--) {
      if (nums[i] > nums[piv]) {
        swap(nums[i], nums[piv]);
        break;
      }
    }

    reverse(nums.begin() + piv + 1, nums.end());
  }
};
