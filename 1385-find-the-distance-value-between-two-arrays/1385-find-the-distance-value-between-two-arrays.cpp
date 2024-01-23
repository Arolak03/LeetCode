class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n =arr1.size();
        int ans=0;
        for(int i=0;i<n;i++){
            bool flag=true;
            for(int j=0;j<arr2.size();j++){
                if(abs(arr1[i]-arr2[j])<=d)flag=false;;
            }
            if(flag)ans++;
        }
        return ans;
    }
};