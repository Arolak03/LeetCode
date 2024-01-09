class Solution {
public:
    int findSum(vector<int>& nums, int x){
        long long sum=0;
        for(long long i=0;i<nums.size();i++){
            sum+=abs(x-nums[i]);
        }
        return sum;
    }
    int minMoves2(vector<int>& nums) {
       int n =nums.size();
        int l=INT_MAX;
       int r=INT_MIN;
        for(int i=0;i<n;i++){
            l=min(l,nums[i]);
            r=max(r,nums[i]);
        }
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int val1=findSum(nums,mid);
            int val2=findSum(nums,mid+1);
            if(val1>val2){
                l=mid+1;
                ans=val2;
            }
            else{
                r=mid-1;
                ans=val1;
            }
            
            
        }
        return ans;
    }
};