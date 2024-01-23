class Solution {
public:
    
    // double solve(int n, int i){
    //     // if(i==0)return 0;
    //     if(i==0)return 0;
    //     if(i==1)return 1;
    //     // if(i==0)return 0;
    //     return 1+solve(n,i-1);
    // }
    
    double nthPersonGetsNthSeat(int n) {
        // long fact=1;
        // for(int i=1;i<=n;i++){
        //     fact*=i;
        // }
        // double num=solve(n,n-1);
        // return num;
        if(n==1)return 1.00;
        return 0.50;
    }
};