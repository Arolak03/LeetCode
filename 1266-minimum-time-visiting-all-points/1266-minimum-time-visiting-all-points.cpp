class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int m=points.size();
        int n =points[0].size();
        int time=0;
        //start
        int row=points[0][0];
        int col=points[0][1];
        for(int i=1;i<m;i++){
            int rowd=abs(row-points[i][0]);
            int cold=abs(col-points[i][1]);
            if (rowd==cold)time+=cold;
            else{
                time+=min(rowd,cold);
                time+=abs(cold-rowd);
            }
            row=points[i][0];col=points[i][1];
        }
        return time;
    }
};