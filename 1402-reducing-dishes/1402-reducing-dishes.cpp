class Solution {
public:
    // vector<int> sort1(vector<int>& array){
    //     for(int i=0;i<array.size()-1;i++){
    //         for(int j=i+1;j<array.size();j++){
    //             if(array[i]>array[j]){
    //                 int temp = array[i];
    //                 array[i]=array[j];
    //                 array[j]=temp;
    //             }
    //         }
    //     }
    //     // for(int i=0;i<array.size();i++){
    //     //     cout<<array[i];
    //     // }
    //     return array;
    // }
    
    int sat(vector<int>& arr, int index, int time,vector<vector<int>>& dp){
        int n = arr.size();
        if(index==n){
            return 0;
        }
        if(dp[index][time]!=-1)
           {
               return dp[index][time];
           }        
        int incl = arr[index]*(time+1) + sat(arr, index+1, time+1,dp);
        int excl = 0 + sat(arr,index+1,time,dp);
        
        dp[index][time]=max(incl,excl);
        return dp[index][time];
 }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n = satisfaction.size();
        // return sort(satisfaction);
        vector<vector<int>>dp (n+1,vector<int>(n+1,-1));
        
        return sat(satisfaction,0,0,dp);
        
    }
};