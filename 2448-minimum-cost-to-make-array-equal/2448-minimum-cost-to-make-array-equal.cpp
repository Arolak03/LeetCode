class Solution {
public:
    long long totalcost(vector<int>& nums, vector<int>& cost,int nn) {
      long long ans=0;
      for(int i=0;i<nums.size();i++)
          ans+=(long long)((long long)abs((long long)nums[i]-(long long)nn)*(long long)cost[i]);
        //abs(nums[i]-nn)*cost[i]
      return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {

            int i=nums[0],j=nums[0];
            for(auto it:nums) {
                i=min(i,it);
                j=max(j,it);
            }
            long long ans=0;
            while(i<=j){
                int m=(i+j)/2;
                auto it1=totalcost(nums,cost,m);
                auto it2=totalcost(nums,cost,m+1);
                if(it1>it2){
                    ans=it2;
                    i=m+1;
                }
                else{
                    j=m-1;
                    ans=it1;
                }
            }
            return ans;

    }
};