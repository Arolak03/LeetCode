class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // int n = intervals.size();
        // intervals.push_back(newInterval);
        // vector<vector<int>> ans;
//         stack<vector<int>> s;
//         int maxEnd=0;
//         sort(intervals.begin(), intervals.end());
//         int n =intervals.size();
//         s.push(intervals[0]);
//         maxEnd=intervals[0][1];
//         int minstart=intervals[0][0];
//         for(int i=1;i<n;i++){
            
//             if(!s.empty() && intervals[i][0]<=maxEnd){
//                 maxEnd=max(maxEnd,intervals[i][1]);
//                 s.pop();
//                 s.push({minstart, maxEnd});
//                 continue;
//             }
//             minstart=intervals[i][0];
//             maxEnd=intervals[i][1];
//             s.push(intervals[i]);
//         }
//         while(!s.empty()){
//             ans.push_back(s.top());
//             s.pop();
//         }
//         reverse(ans.begin(), ans.end());
        // return ans;
        
        
        int n =intervals.size();
        vector<vector<int>> ans;
        int i=0;
        while(i<n && intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        while(i<n && newInterval[1]>=intervals[i][0]){
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
        
        
    }
};