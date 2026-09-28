class Solution:
    def maxArea(self, height: list[int]) -> int:
        max_area = 0
        lo, hi = 0, len(height) - 1
        while lo < hi:
            area = (hi - lo) * min(height[lo], height[hi])
            max_area = max(area, max_area)
            
            if height[lo] < height[hi]:
                lo += 1
            else:
                hi -= 1

        return max_area
