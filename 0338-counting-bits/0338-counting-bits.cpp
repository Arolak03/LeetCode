class Solution {
public:
    
    int solve(int x){
        int count=0;
        while(x){
            if((x & 1) == 1)count++;
            // cout<<x<<" ";;
            x>>=1;
        }
        return count;
    }
    
    
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            int x=solve(i);
            ans.push_back(x);
        }
        return ans;
    }
};