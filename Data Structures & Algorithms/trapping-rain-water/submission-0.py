class Solution:
    def trap(self, height: List[int]) -> int:
        ans = 0
        left = 0
        right = len(height)-1

        maxl = height[left]
        maxr = height[right]

        while left < right:
            if maxl < maxr:
                left +=1
                maxl = max(maxl, height[left])
                ans+= maxl - height[left]

            else:
                right -=1
                maxr = max(maxr, height[right])
                ans+= maxr - height[right]

        return ans        