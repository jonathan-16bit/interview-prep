class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 1) return 1;

    int slow = 0;
    for (int fast = 1; fast < nums.size(); ++fast) {
      if (nums[fast] == nums[fast - 1])
        continue;
      nums[++slow] = nums[fast];
    }

    return slow + 1;
  }
};
