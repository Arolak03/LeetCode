// class Solution {
// public:
    
//     long long int average(vector<int>& a, int start, int end){
//         long long int ans = 0;
//         for(int i = start;i<=end;i++){
//             ans+=a[i];
//         }
//         int x =end - start +1;
        
//         ans = (ans/x);
        
//         return ans;
        
//     }
    
//     vector<int> avg(vector<int>& nums, int k, int index){
        
//         int n =nums.size();
//         vector<int> array(n,0);
         
        
//         if(k!=0){
//         // start from index - k till index + k
//         while(index<n){
//         for(int  i =0;i<n;i++){
//             if((index-k) < 0 || (index + k) >=n){
//              array[i]=-1;
//                 index+=1;
//         }else{
//             array[i] = average(nums,index-k,index+k);
//             index++;
//             }
//         }
//         }
//         return array;}
//         else{
//             return nums;
//         }
//     }    
    
//     vector<int> getAverages(vector<int>& nums, int k) {
//         return avg(nums,k,0);
        
//     }
// };
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int windowSize = 2 * k + 1;
        vector<int> ans(n, -1);

        if (n < windowSize) {
            return ans;
        }

        vector<long long> prefixSum(n + 1);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        for (int i = k; i + k < n; ++i) {
            ans[i] = (prefixSum[i + k + 1] - prefixSum[i - k]) / windowSize;
        }

        return ans;
    }
};