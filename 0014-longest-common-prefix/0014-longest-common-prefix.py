class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        strs.sort()
        string=""
        length=len(strs)
        
        for i in range(min(len(strs[0]), len(strs[-1]))):
            if strs[0][i]!=strs[-1][i]:
                return string
            string+=strs[0][i]
            
        return string