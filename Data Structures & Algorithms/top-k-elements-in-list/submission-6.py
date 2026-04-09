class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        count = {}
        for i in range(n):
            count[nums[i]]= 1+count.get(nums[i],0)
        arr = []
        for num, cnt in count.items():
            arr.append([cnt,num])
            arr.sort()
        res = []
        for i in range(k):
            res.append(arr.pop()[1])
        return res



        