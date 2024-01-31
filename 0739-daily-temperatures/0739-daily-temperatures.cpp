class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> s;
        int n = t.size();
        vector<int> right(n,0);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && t[s.top()]<=t[i]){
                s.pop();
            }
            if(!s.empty())right[i]=s.top();
            s.push(i);
        }
        for(int i=0;i<n;i++){
            if(right[i]>0)right[i]=right[i]-i;
        }
        return right;
        
    }
};