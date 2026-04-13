class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        n = len(strs)
        strs.sort()
        m = len(strs[0])
        com = ""
        flag = True
        if m == 0:
            return ""
        for i in range(m):
            for word in strs:
                if word[i]!=strs[0][i]:
                    flag = False
                    break
            if flag == True:
                    com = com + word[i]
            else: break
        return com    

        