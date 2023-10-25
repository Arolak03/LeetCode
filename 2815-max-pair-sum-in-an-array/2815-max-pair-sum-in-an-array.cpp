class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n  =nums.size();
        int ans=INT_MIN;
        
        for(int i=0;i<n-1;i++){
            string s1=to_string(nums[i]);
            sort(s1.begin(), s1.end());
            for (int j=i+1;j<n;j++){
                string s2=to_string(nums[j]);
                sort(s2.begin(), s2.end());
                if(s1[s1.length()-1]==s2[s2.length()-1])ans=max(ans,nums[i]+nums[j]);
            }
            
        }
        return ans==INT_MIN?-1:ans;
    }
};