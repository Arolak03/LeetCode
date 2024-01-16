class Solution {
   public: 
    
//     int solve(vector<int>& nums1, vector<int>& nums2, int i, int j){
//         if(j>=nums2.size()){
//             return 0;
//         }
//         int ans=0;
//         for(int k=0;k<nums2.size();k++){
//             if(nums1[i]!=nums2[k])continue;
//             int x=i;
//             int y=k;
//             while(x<nums1.size() && k<nums2.size() && nums1[x]==nums2[k]){
//                 k++;
//                 x++;
//             }
//             ans=max(ans,k-y);
//             k=y;
//         }
//         return ans;
//     }
    
//     int findLength(vector<int>& nums1, vector<int>& nums2) 
//     {
//         int ans=0;
//         int n1=nums1.size();
//         int n2=nums2.size();
//         for(int i=0;i<n1;i++){
//             int count=solve(nums1,nums2,i,0);
//             ans=max(ans,count);
//         }
//         return ans;
//     }
// };



















































// // int n = nums1.size();
// //         int m = nums2.size();
// //         vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        
// //         int len=0;
// //         for(int i=1;i<=n;i++)
// //         {
// //             for(int j=1;j<=m;j++)
// //             {
// //                 if(nums1[i-1]==nums2[j-1])
// //                 {
// //                     dp[i][j] = 1+dp[i-1][j-1];
// //                     len = max(len,dp[i][j]);
// //                 }
// //                 else
// //                 {
// //                     dp[i][j] = 0;
// //                 }
// //             }
// //         }
// //         return len;


int solve(vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>>& memo) {
        if (i == 0 || j == 0) {
            return 0;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int len = 0;
        if (nums1[i - 1] == nums2[j - 1]) {
            len = 1 + solve(nums1, nums2, i - 1, j - 1, memo);
        }

        memo[i][j] = len;
        return len;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));

        int maxLen = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                maxLen = max(maxLen, solve(nums1, nums2, i, j, memo));
            }
        }

        return maxLen;
    }
};