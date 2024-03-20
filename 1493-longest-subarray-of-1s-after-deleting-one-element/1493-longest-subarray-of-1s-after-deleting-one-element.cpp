class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n =nums.size();
        int start=0;
        int ans=0;
        while(start<n){
            int count=0;
            while(start<n && nums[start]==0)start++;
            int end=start;
            while(end<n && nums[end]==1){
                end++;
            }
            int temp=end;
            while(end<n && nums[end]==0){
                count++;
                end++;
            }
            if(count==1){
                
                while(end<n && nums[end]==1){
                    end++;
                }
                ans=max(ans,end-start-1);
            }
            else if(count>1){
                ans=max(ans,temp-start);
            }
            else{
                //if count==0
                if(start!=0 || end!=n){
                    ans=max(ans,end-start);
                }
                else{
                    ans=max(ans,end-start-1);
                }
            }
            while(start<end && nums[start]!=0){
                start++;
            }
            // start=end;
        }
        return ans;
    }
};