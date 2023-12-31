class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n =s.length();
        int maxi=INT_MIN;
        
        for(int i=0;i<n;i++){
            char temp=s[i];
            int count=i;
            for(int j=i+1;j<n;j++){
                if(temp==s[j])count=j;
            }
            maxi=max(maxi,count-i-1);
        }
        return maxi==INT_MIN?-1:maxi;
    }
};