class Solution {
public:
    
    
    void solve(vector<int>& arr, int target, vector<vector<int>>& ans, int index, vector<int>& op){
        if(target==0){
            // for(auto it: op)cout<<it<<" ";
            // sort(op.begin(), op.end());
            ans.push_back(op);
            return;
        }
        if(target<0 || index>=arr.size())return;
        for(int i=index;i<arr.size();i++){    
            if(i>index && arr[i]==arr[i-1])continue;
            if(arr[i]>target)break;
            op.push_back(arr[i]);
            solve(arr,target-arr[i],ans,i+1,op);
            op.pop_back();     
        }
        // solve(arr,target,ans,index+1,op);
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> opp;
        solve(candidates,target,ans,0,opp);
        // vector<vector<int>> op;
        // for(auto it: ans){
        //     op.push_back(it);
        // }
        return ans;
    }
};