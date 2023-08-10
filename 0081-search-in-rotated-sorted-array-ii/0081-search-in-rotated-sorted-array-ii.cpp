class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n =nums.size();
        int l=0;
        int r=n-1;
        while(l<=r){
            //duplicate handdling
            int mid = l+(r-l)/2;
            if(nums[mid]==target){
                return true;
            }
            if(nums[l]==nums[mid] && nums[r]==nums[mid]){
                l++;
                r--;
                continue;
            }
            if(nums[mid]>=nums[l]){
                if(nums[l]<=target && nums[mid]>=target){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else{
                if(nums[mid]<=target && nums[r]>=target){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
        }
        return false;
    }
};

// class Solution {
// public:
//     bool search(vector<int>& v, int target) {
//         int i=0,j=v.size()-1;
//         while(i<=j){
//             int m = (i+j)/2;
//             if(v[m]==target)return true;
//             if(v[i]==v[m] && v[m]==v[j]){
//                 i++;
//                 j--;
//                 continue;
//             }
//             if(v[m]>=v[i]){
//                 if(v[i]<= target && target<=v[m])j=m-1;
//                 else i = m+1;
//             }
//             else {
//                  if(v[j]>= target && target >= v[m])i=m+1;
//                 else j = m-1;
//             }
//         }
//         return false;
//     }
// };