#include <vector>
#include <cmath>

class Solution {
public:
//     int alternate(vector<int>& nums, int index) {
//         int currLen =0;
//         int len=0;
//         if (index >= nums.size()) {
//             return 0;
//         }
//         int include=0;
//         if(index % 2 ==0 && nums[index +1] - nums[index]==1){
//             include = 1+alternate(nums,index+1);
//             currLen++;
//             len=max(currLen,len);
//         }
//         else if(index % 2 !=0 && nums[index +1] - nums[index]==-1){
//             include = 1+alternate(nums,index+1);
//             currLen++;
//             len=max(len,currLen);
//         }
//         else{
//             currLen=0;
//         }
//         len=max(len,currLen);
        
//         return len;
//     }
    
//     int alternatingSubarray(vector<int>& nums) {
//         int n = nums.size();
//         if (n < 2) {
//             return -1; // No alternating subarray possible
//         }
       
//         return alternate(nums,0);
//     }
// };
    int alternatingSubarray(vector<int>& nums) {
    int front = 1, back = 0, state = INT_MAX, ans = 0;
    while(front < nums.size()){
        int diff = nums[front] - nums[front-1];
        if(diff == state*(-1)){
            state = state * (-1);
            ans = max(ans, front - back + 1);
        }else{
            if(diff == 1){
                state = diff;
                back = front - 1;
                ans = max(ans, front - back + 1);
            }else state = INT_MAX;
        }
        front++;
    }
    return ans?ans: -1;
}
};