class Solution {
public:
//     void solve(vector<int>& nums, int k, int p, int index, vector<int>& op, set<vector<int>>& ans){
//         if(k>=0 || index>=nums.size()){
//             ans.insert(op);
//             return;
//         }
       
//         //inc
        
//         if(nums[index]%p==0 && k>0){
//             op.push_back(nums[index]);
//             solve(nums,k-1,p,index+1,op,ans);
//             op.pop_back();
//         }
//         op.push_back(nums[index]);
//         solve(nums,k,p,index+1,op,ans);
//         op.pop_back();
//         solve(nums,k,p,index+1,op,ans);
//     }
    
    int countDistinct(vector<int>& nums, int k, int p) {
        int i;int j;
        set<vector<int>> s;
        int n =nums.size();
        for(i=0;i<n;i++){
            vector<int> tt;
            int cnt=0;
            for(j=i;j<n;j++){
                tt.push_back(nums[j]);
                if(nums[j]%p==0)cnt++;
                if(cnt>k)break;
                s.insert(tt);
            }
            
        }
        return s.size();
    }
};

















//  int countDistinct(vector<int>& nums, int k, int p) {
        
//         int n=nums.size();
//         set<vector<int>>ans;
        
//         int i,j;
//         for(i=0;i<n;i++)
//         {
//             vector<int>tt;
//             int ct=0;
//             for(j=i;j<n;j++)
//             {
//                 tt.push_back(nums[j]);
//                 if(nums[j]%p==0)
//                     ++ct;
//                 if(ct>k)
//                     break;
//                 ans.insert(tt);
                    
//             }
//         }
//         return ans.size();
//     }
    
// };