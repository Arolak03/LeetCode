class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=INT_MIN;
        int n = nums.size();
        int i=0;
        int j=i;
        double avg=0;
        int m=k;
        
        while(m--){
            avg+=nums[j];
            j++;
        }
        ans=max(ans,avg/k);
        while(i<n-k && j<n){
           avg=avg-nums[i]+nums[j];
           i++;
           j++;
           ans=max(ans,avg/k);
        }
        return ans;
    }
};