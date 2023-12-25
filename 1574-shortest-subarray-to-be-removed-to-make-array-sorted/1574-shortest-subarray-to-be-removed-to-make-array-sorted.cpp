class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int count=INT_MAX;
        int i=0;
        int j=n-1;
        while(i<n-1 && arr[i]<=arr[i+1])i++;
        if(i==n-1)return 0;
        while(j>=i && arr[j]>=arr[j-1])j--;
        if(j==0)return 0;
        count=min(n-i-1,j);
        int s=0;
        int e=j;
        while(s<=i && e<n){
            if(arr[s]<=arr[e]){
                count=min(e-s-1,count);
                s++;
            }
            else e++;
        }
        return count;
    }
};