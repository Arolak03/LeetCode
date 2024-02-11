class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        // int j=1;
        // int ans=INT_MAX;
        int n=a.size();
        // int k=n;
        for(int i=0;i<n;i++){
            // if(nums[i]<=0)continue;
            //max n can be missing
            while(a[i]>0 && a[i]<=n && a[a[i]-1]!=a[i]){
                swap(a[i],a[a[i]-1]);
            }
        }
        for(int i=0;i<n;i++){
            if(a[i]!=i+1)return i+1;
        }
        return n+1;
    }
};