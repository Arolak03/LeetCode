class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int, int> dp;
        int ans = 0;
        for(int i=0;i<n;i++){
            int temp = arr[i] - difference;
            int tempAns=0;
            
            // agr left m temp hai to uska ans mera tempAns ho jayega
            if(dp.count(temp)){
                tempAns = dp[temp];
            }
            //aur arr[i] m wo tempAns +1 ho jayega
            dp[arr[i]] = 1+tempAns;
            ans = max(ans,dp[arr[i]]);
        }
        return ans;
        
    }
};