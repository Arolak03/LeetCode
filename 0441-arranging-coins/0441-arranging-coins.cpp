class Solution {
public:
    
    // int solve(int n, int level){
    //     if(n<0)return level-1;
    //     if(n==0)return 0;
    //     if(n-level>=0)
    //     return level;
    // }
    
    int arrangeCoins(int n) {
        // vector<vector<int>> mat(n+1);
        // int i=1;
        // while(n>0){
        //     n=n-i;
        //     if(n<0)return i-1;
        //     else if(n==0)return i;
        //     else i++;
        // }
        // return 0;
        // return solve(n,1);
        long long l=0;
        long long r=n;
        while(l<=r){
            long long m = l+(r-l)/2;
            if((m*(m+1)/2)>n)r=m-1;
            else{
                l=m+1;
            }
        }
        return (int)l-1;
    }
};