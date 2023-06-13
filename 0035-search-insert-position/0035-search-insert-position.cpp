class Solution {
public:
    
    int binary(vector<int>& nums, int target){
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        int ans=s;
        while(s<e){
            if(nums[mid]==target){
                return mid;
                // break;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else if(nums[mid]<target){
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        if(s==e && nums[s]<target){
            return s+1;
        }
        else if(s==e && nums[s]>=target){
            return s;
        }
        else if(e<s){
            return s;
        }
//         else if(arr[s]>target{
            
//         }
        return 0;
        
    }
    int searchInsert(vector<int>& nums, int target) {
        int ans=binary(nums,target);
        return ans;
    }
};