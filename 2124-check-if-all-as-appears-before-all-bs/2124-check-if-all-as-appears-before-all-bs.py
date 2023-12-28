class Solution:
    def checkString(self, s: str) -> bool:
        length=len(s)
        for i in range(length-1):
            if s[i]=='b' and s[i+1]=='a':
                return False
            
        return True