class Solution {
public:
    //greedy
    
    int findMinArrowShots(vector<vector<int>>& points) {
        // sort(points.begin(), points.end());
         sort(points.begin(), points.end(), [](vector<int>&a, vector<int>&b){
            return a[1]<b[1];
        });
        int n = points.size();
        int cnt=1;
        int currMax=points[0][1];
        for(int i=1;i<n;i++){
            if(points[i][0]<=currMax)continue;
            else{
                cnt++;
                currMax=max(currMax, points[i][1]);
            }
        }
        return cnt;
    }
};