#define MOD 1000000007; 
class Solution {
public:
    
    long long myPow(long long base, long long expo){
        long long ans=1;
        while(expo>0){
            // ans=(ans*base)%MOD;
            if(expo%2==1){
                ans=(ans*base)%MOD;
            }
            // else{
                base=(base*base)%MOD;
                expo/=2;
            // }
        }
        return ans;
    }
    
    int countGoodNumbers(long long n) {
        long long odd, even;
        if(n%2){
            odd=(n-1)/2;
            even=(n-1)/2+1;
        }
        else {
            odd=n/2;
            even=n/2;
        }
        long long ans =1;
        ans=(ans*(myPow(5,even)))%MOD;
        ans=(ans*(myPow(4,odd)))%MOD;
        return ans;
        
    }
};