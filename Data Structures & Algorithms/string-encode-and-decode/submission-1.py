class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ""
        for s in strs:
            res += str(len(s))+"#"+s
        
        return res

    def decode(self, s: str) -> List[str]:
        result = []
        j = 0
        
        while j < len(s):
            i = j
            while s[i] != "#":
                i+=1

            length = int(s[j:i])

            word = s[i+1: i+1+length]

            result.append(word)
                
            j = i+1+length
        
        return result 

            


