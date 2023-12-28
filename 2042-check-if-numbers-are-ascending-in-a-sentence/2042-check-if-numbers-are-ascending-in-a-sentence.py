class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        length=len(s)
        number=0
        i=0
        while i<length:
            temp=''
            if s[i]>='0' and s[i]<='9':
                while i<length and s[i]!=" ":
                    temp+=s[i]
                    i+=1
                if int(temp)<=number:
                    return False
                number=int(temp)
                
            # number=int(temp) 
            if i<length:
                i+=1
            
        return True
               