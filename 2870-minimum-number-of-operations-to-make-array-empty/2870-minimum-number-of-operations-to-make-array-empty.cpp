class Solution {
public:
    int minOperations(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        unordered_map<int, int> mpp;
        int start=0;
        int count=0;
        int n =nums.size();
        
        // for(int i=0;i<nums.size();i++){
        //     int y=i;
        //     while(i<n && nums[start]==nums[i]){
        //         i++;
        //     }
        //     if(i-start==1)return -1;
        //     if((i-start)%3==0){
        //         count+=(i-start)/3;
        //     }
        //     else{
        //         count+=(i-start)/3;
        //         count++;
        //     }
        //     start=i;
        //     i--;
        // }
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto it: mpp){
            if(it.second==1)return -1;
            if(it.second%3==0){
                count+=it.second/3;
            }
            else {
                count+=it.second/3;
                count++;
            }
        }
        return count;
    }
};