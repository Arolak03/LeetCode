class Solution {
public:
    
    

    
    int subarraySum(vector<int>& nums, int k) {
        int n =nums.size();
        int count=0;
        int sum=0;
        map<int,int> pref;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            
            if(sum==k)count++;
            if(pref.find(sum-k)!=pref.end()){
                count+=pref[sum-k];
            }
            pref[sum]++;
        }
        return count;
    }
};