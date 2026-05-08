class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        array = []
        for i in range(n):
            array.append((nums[i], i))

        array.sort()

        left = 0
        right = n-1

        while left < right:
            t = array[left][0]+array[right][0] 
            if t == target:
                if array[left][1] < array[right][1]:
                    return [array[left][1],array[right][1]]
                else :
                    return [array[right][1],array[left][1]]
            elif t < target:
                left +=1
            else:
                right -=1
    

        