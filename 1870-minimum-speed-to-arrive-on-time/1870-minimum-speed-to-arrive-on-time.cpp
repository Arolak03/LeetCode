class Solution {
public:
    double findTime(vector<int>& dist, int speed){
        double t = 0;
        int n =dist.size();
        for(int i=0;i<n-1;i++){
            double time = (double)dist[i]/(double)speed;
            t+=ceil(time);
        }
        // for last value;
        t+=(double)dist[n-1]/(double)speed;
        return t;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int mini = 1;
        int maxi = 1e7;
        int speed=-1;
        while(mini<=maxi){
            int mid = mini+(maxi-mini)/2;
            
            // time nikaalo
            if(findTime(dist,mid)<=hour){
                speed=mid;
                maxi=mid-1;
               
            }
            else{
                mini=mid+1;
            }
        }
        return speed;
    }
};