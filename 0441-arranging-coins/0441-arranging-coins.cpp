class Solution {
public:
    int arrangeCoins(int n) {
        // vector<vector<int>> mat(n+1);
        int i=1;
        while(n>0){
            n=n-i;
            if(n<0)return i-1;
            else if(n==0)return i;
            else i++;
        }
        return 0;
    }
};