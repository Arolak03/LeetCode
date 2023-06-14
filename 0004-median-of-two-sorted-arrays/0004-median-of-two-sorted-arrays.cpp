class Solution {
public:
    
    double min(vector<int>& nums1, vector<int>& nums2){
        int m = nums1.size();
        int n =nums2.size();
        int k =m+n;
        vector<int> ans(k);
        int p=0;
        int q=0;
        
        for(int i=0;i<k;i++){
        if(p<m  && q<n){
            if(nums1[p]<=nums2[q]){
                ans[i]=nums1[p];
                p++; 
            }
            else if(nums1[p]>nums2[q]){
                ans[i]=nums2[q];
                q++; 
            }
        }
        else if(p<m){
            ans[i]=nums1[p];
            p++;
        }
        else if(q<n){
            ans[i]=nums2[q];
            q++;
        }
            
        
    }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
        }
        double median = 0.00000;
        if(k==2){
            median=(ans[1]+ans[0])/2.0;
        }
        else if(k%2==0 && k!=2){
            median = (ans[(k/2)-1] + ans[(k/2)]) / 2.0;

            }
        else if(k%2!=0 && k!=2) {
            median = ans[(k-1)/2.0];
        }
        return median;
    }
    
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
       
        double median=min(nums1, nums2);
        return median;
        
        
        
    }
};