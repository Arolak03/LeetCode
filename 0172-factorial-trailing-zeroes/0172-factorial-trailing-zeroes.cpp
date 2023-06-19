class Solution {
public:
    int trailingZeroes(int n) {
        int x = 5;
        int count =0;
        while(x<=n){
            count+=abs(n/x);
            
            x=x*5;
        }
        return count;
    }
    
};