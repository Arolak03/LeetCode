class Solution {
public:
    int length(vector<int>& bars){
        int i=0;
        int j=0;
        int maxS=1;
        while(j<bars.size()-1 && i<bars.size()){
            if(bars[j]+1==bars[j+1]){
                j++;
                maxS=max(maxS,j-i+1);
            }
            else{
                maxS=max(maxS,j-i+1);
                i=j+1;
                j++;
            }
            
        }
        maxS=max(maxS,j-i-1);
        return maxS;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(vBars.begin(), vBars.end());
        sort(hBars.begin(), hBars.end());
        int h=length(hBars);
        int b=length(vBars);
        int side=min(h,b);
        return (side+1)*(side+1);
    }
};