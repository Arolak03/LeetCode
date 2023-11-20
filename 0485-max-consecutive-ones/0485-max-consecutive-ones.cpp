class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int n =nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            
            if(nums[i]!=1)continue;
            int count=0;
            // int temp=i;
            while (i<n && nums[i]==1){
                count++;
                i++;
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }
};