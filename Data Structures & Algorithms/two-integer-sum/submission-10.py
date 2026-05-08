class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        limo = {}
        for i, n in enumerate(nums):
            difference = target - nums[i]
            if difference in limo:
                if limo[difference] < i:
                    return [limo[difference],i]
                else :
                    return [i, limo[difference]]
            limo[nums[i]] = i

        