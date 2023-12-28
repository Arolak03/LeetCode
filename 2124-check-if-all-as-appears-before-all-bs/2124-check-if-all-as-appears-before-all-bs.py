class Solution:
    def checkString(self, s: str) -> bool:
        length=len(s)
        st="".join(sorted(s))
        for i in range(length):
            if s[i]!=st[i]:
                return False
            
        return True