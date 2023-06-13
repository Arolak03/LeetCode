class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int suml=0;
        int sumr=0;
        int n = nums.size();
        int ans=-1;
        for(int i=1;i<n;i++){
            sumr+=nums[i];
        }
        if(suml==sumr){
            return 0;
        }
        
        for(int i=1;i<n;i++){
            sumr-=nums[i];
            suml+=nums[i-1];
            if(suml==sumr){
                return i;
            }
        }
    return ans;   
    }
    
};