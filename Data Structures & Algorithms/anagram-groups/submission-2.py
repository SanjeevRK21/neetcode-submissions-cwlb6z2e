class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        r = defaultdict(list)
        for s in strs:
            sorteds = ''.join(sorted(s))
            r[sorteds].append(s)
        return list(r.values())