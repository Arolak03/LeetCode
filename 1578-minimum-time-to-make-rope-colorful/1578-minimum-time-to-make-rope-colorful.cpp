class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n =colors.size();
        int count=0;
        int next=0;
        int i=0;
        int j=0;
        while(i<n && j<n){
            int maxi=INT_MIN;
            int sum=0;
            int j=i;
            while(colors[i]==colors[j]){
                sum+=neededTime[j];
                maxi=max(maxi,neededTime[j]);
                j++;
            }
            count+=(sum-maxi);
            i=j;
        }
        return count;    
    }
};