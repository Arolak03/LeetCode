class Solution {
public:
    map<pair<int, int>, int>dp;
    int solve(int n, vector<pair<int, int>>& arr, int index, int maxEnd){
        if(index>=arr.size()){
            if(maxEnd>=n)return 0;
            else return 1e9;
        }
        if(maxEnd<arr[index].first)return 1e9;
        if(dp.find({index,maxEnd})!=dp.end())return dp[{index,maxEnd}];
        int take=1+solve(n,arr,index+1,max(maxEnd,arr[index].second));
        int notTake=solve(n,arr,index+1,maxEnd);
        return dp[{index,maxEnd}]=min(take, notTake);
    }
    
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int , int>> arr;;
        // vector<vector<int>> dp(n+2, vector<int>(n+2,-1));
        
        for(int i=0;i<ranges.size();i++){
            int start=max(0,i-ranges[i]);
            int end=min(n,ranges[i]+i);
            arr.push_back({start,end});
        }
        sort(arr.begin(), arr.end());
        int ans=solve(n,arr, 0, 0);
        return ans==1e9? -1:ans;
    }
};