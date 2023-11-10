class Solution {
public:
    
//     int solve(int i, int j,vector<int>& nums){
//         // if(index>=nums.size()){
//         //     return 0;
//         // }
//         // int incl=nums[index]+solve(nums,index+1);
//         // int excl=0+solve(nums,index+1);
//         // return max(incl, excl);
//         int ans=0;
//         for(int m=i;m<=j;m++){
//             ans+=nums[m];
//         }
//         return ans;
        
//     }
    
    int maxSubArray(vector<int>& nums) {
//         int n =nums.size();
//         int maxi=INT_MIN;
//         // for(int i=0;i<nums.size();i++){
//         //     for(int j=i;j<n;j++){
//         //         int newmax=solve(i,j,nums);
//         //         maxi=max(maxi,newmax);
//         //     }
//         // }
//         // return maxi;
//         vector<int> dum(n);
//         dum[0]=nums[0];
//         for(int i=1;i<n;i++){
//             dum[i]=dum[i-1]+nums[i];
//         }
//         for(int i=n-1;i>=0;i--){
//             int ans=dum[i];
//             for(int j=i-1;j>=0;j--){
//                 maxi=max(ans,maxi);
//                 ans -= dum[j];
                
//             }
//         }
//         return maxi;
        
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxi=max(sum,maxi);
            if(sum<0)sum=0;
        }
        return maxi;
    }
};