class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftm=0;
        int rightm=0;
        int count=0;
        int l=0;
        int r=n-1;
        while(l<=r){
            //right m badi ho building plus m left m just badi to ho
            if(height[l]<=height[r]){
                if(leftm<height[l])leftm=height[l];
                else{
                    count+=leftm-height[l];
                }
                l++;
            }
            else{
                if(rightm<height[r])rightm=height[r];
                else{
                    count+=rightm-height[r];
                }
                r--;
            }
                
        }
        return count;
    }
};