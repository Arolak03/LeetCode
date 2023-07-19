bool compareSecondElement(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

class Solution {
public:
    int solve(vector<vector<int>>& arr){
                int ans = 0;
        int k = INT_MIN;
        
        for (int i = 0; i < arr.size(); i++) {
            int x = arr[i][0];
            int y = arr[i][1];
            
            if (x >= k) {
                // Case 1
                k = y;
            } else {
                // Case 2
                ans++;
            }
        }
        return ans;
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compareSecondElement);
        int ans = 0;
        int k = INT_MIN;
        
       
        
        return solve(intervals);
    }
};