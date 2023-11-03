class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(int i=1;i<=k;i++){
            mpp[i]=i;
        }
        int count=0;
        int n =nums.size();
        int index=n-1;
        while(!mpp.empty() && index>=0){
            if(mpp.count(nums[index])){
                mpp.erase(nums[index]);
                index--;
                count++;
            }
            else{
                index--;
                count++;
            }
        }
        return count;
    }
};