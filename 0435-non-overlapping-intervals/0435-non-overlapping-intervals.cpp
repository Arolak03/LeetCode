class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
         int ans=0;
        int prev=0;
        // int curr=0;
        sort(intervals.begin(), intervals.end());
        int n =intervals.size();
        for(int curr=1;curr<n;curr++){
            // overlapping
            if(intervals[curr][0]<intervals[prev][1]){
                ans++;
                if(intervals[curr][1]<=intervals[prev][1]){
                    prev=curr;
                    //delete prev
                }
            }
            else {
                prev=curr;
            }
            
        }
        return ans;
    }
};