class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=INT_MIN;
        int n =nums.size();
        // for(int i=0;i<=n-k;i++){
        //     double avg=0;
        //     for(int j=i;j<i+k;j++){
        //         avg+=nums[j];
        //     }
        //     ans=max(ans,avg/k);
        // }
        
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