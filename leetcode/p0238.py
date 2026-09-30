class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        res = [1] * len(nums)

        left = 1
        for i in range(len(res)):
            res[i] = left
            left *= nums[i]

        right = 1
        for i in range(len(res) - 1, -1, -1):
            res[i] *= right
            right *= nums[i]

        return res
