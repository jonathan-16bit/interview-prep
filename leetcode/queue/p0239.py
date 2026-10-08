class Solution:
    def maxSlidingWindow(self, nums: list[int], k: int) -> list[int]:
        dq = deque()
        res = []

        for i in range(len(nums)):
            # outside current k-size window
            while dq and dq[0] <= i - k:
                dq.popleft()

            # if older and smaller than nums[i], wont matter again
            while dq and nums[dq[-1]] < nums[i]:
                dq.pop()

            dq.append(i)

            # once a full window is complete, start appending
            if i >= k - 1:
                res.append(nums[dq[0]])

        return res
