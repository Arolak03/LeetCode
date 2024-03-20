class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n =nums.size();
        // int i=0;
        // int j=0;
        int ans=0;
        
//         while(j<n){
//             i=j;
            
           
            
//         }
        for(int i=0;i<n-ans;i++){
            // int count=0;
            int j=i;
            int temp=k;
            // bool flag=false;
            while(j<n){
                // int jx=j;
                while(j<n && nums[j]==0 && temp>0){
                    j++;
                    // flag=true;
                    temp--;
                }
                while(j<n && nums[j]==1)j++;
                // cout<<temp<<" ";
                if(temp==0)break;
                // if(!flag)j++;
               // j=jx+1;
                // cout<<j<<" ";
            }
            // cout<<i<<"*"<<j<<" ";  
            ans=max(ans,j-i);
        }
        cout<<endl;
        return ans;
        
    }
};