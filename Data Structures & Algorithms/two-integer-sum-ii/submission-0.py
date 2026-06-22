class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left = 0
        n = len(numbers)
        right = n-1

        while left < right:
            crsm = numbers[left] + numbers[right]

            if crsm == target:
                return [left+1, right+1]

            elif crsm > target:
                right -=1
            
            else:
                left +=1
        