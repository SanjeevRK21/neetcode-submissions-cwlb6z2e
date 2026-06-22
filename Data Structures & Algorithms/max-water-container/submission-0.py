class Solution:
    def maxArea(self, heights: List[int]) -> int:
        left = 0
        right = len(heights)-1

        ans = 0

        while right > left:
            wid = right - left

            h = min(heights[left], heights[right])

            ans = max(ans, wid*h)

            if heights[right] > heights[left]:
                left +=1
            else:
                right -=1

        return ans
        