class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        res = nums[0]
        for s in range(n):
            cur = 0
            for i in range(s,n):
                cur = cur+nums[i]
                res = max(res, cur)
        return res


        