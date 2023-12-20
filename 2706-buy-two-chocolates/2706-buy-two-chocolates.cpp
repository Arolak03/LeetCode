class Solution {
public:
    int miniIdx(vector<int>& nums){
        int idx=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<nums[idx])idx=i;
        }
        return idx;
    }
    
    int buyChoco(vector<int>& prices, int money) {
        int mini=0;
        int minI=miniIdx(prices);
        mini+=prices[minI];
        prices[minI]=INT_MAX;
        int miniII=miniIdx(prices);
        mini+=prices[miniII];
        cout<<minI<<" "<<miniII<<" ";  
        if(mini>money)return money;
        return money-mini;
        
    }
};