class Solution {
public:
    
    //cant be binary as not monotonic
    
    
    int pivotIndex(vector<int>& nums) {
        int n= nums.size();
        int suml=0;
        int sumr=0;
        int ans=-1;
        for (int i=1;i<n;i++){
            sumr=sumr+nums[i];
        }
        if(suml==sumr){
                // ans=i;
                return 0;
                
            }
        for (int i=1;i<n;i++){
            suml=suml+nums[i-1];
            sumr=sumr-nums[i];
            if(suml==sumr){
                return i;
            }
            
        }
        return ans;
        
    }

};