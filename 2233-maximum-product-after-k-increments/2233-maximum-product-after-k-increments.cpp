class Solution {
public:
    #define MOD 1000000007
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        // for(auto 
        while(k--){
            int temp=pq.top();
            pq.pop();
            temp+=1;
            pq.push(temp);
        }
        long long ans=1;
        while(!pq.empty()){
            ans=(ans*pq.top()%MOD)%MOD;
            pq.pop();
        }
        return ans%MOD;

    }
};