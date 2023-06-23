class Solution {
public:
    int seq(vector<int>& nums,int ind){
        int n = nums.size();
         if(n<=2){
            return n;
        }
        int longest=2;
        vector<unordered_map<int,int>>dp (n,unordered_map<int,int>());
       
        
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = nums[i]-nums[j];
                if(dp[j].count(diff)){
                    dp[i][diff]= dp[j][diff]+1;
                }
                else{
                    dp[i][diff]=2;
                }
             longest = max(longest,dp[i][diff]);  
            }
             
            
        }
        return longest;
        
    }
    
    int longestArithSeqLength(vector<int>& nums) {
        int n =nums.size();
        
        return seq(nums,0);
    }
};