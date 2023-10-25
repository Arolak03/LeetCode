class Solution {
public:
    int maxDigit(int dig){
        int digi=-1;
        while(dig>0){
            digi=max(digi,dig%10);
            dig/=10;
        }
        return digi;
    }
    
    int maxSum(vector<int>& nums) {
        
        int n =nums.size();
        int ans=INT_MIN;
        vector<int> v(10,INT_MIN);
        for(int i=0;i<n;i++){
            // int num=nums[i];
            int digit=maxDigit(nums[i]);
            ans=max(ans,nums[i]+v[digit]);
            v[digit]=max(v[digit],nums[i]);
        }
        cout<<INT_MIN;
        if(ans<0)return -1;
        else return ans;
    }
};