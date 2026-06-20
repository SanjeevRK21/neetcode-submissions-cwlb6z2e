class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}

        for i in nums:
            count[i] = count.get(i,0)+1

        freq = [[] for _ in range(len(nums)+1)]

        for num, cout in count.items():
            freq[cout].append(num)

        res = []

        for i in range(len(freq)-1,0,-1):
             for n in freq[i]:
                res.append(n)
                if len(res) == k:
                    return res
        