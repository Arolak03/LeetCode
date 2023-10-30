class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        int n =asteroids.size();
        for(int i=0;i<n;i++){
            while(!s.empty() && s.top()*asteroids[i]<0 && s.top()>0){
                if(abs(s.top())>abs(asteroids[i])){
                    asteroids[i]=0;
                }
                else if(abs(asteroids[i])>abs(s.top())){
                    s.pop();
                }
                else if(abs(s.top())==abs(asteroids[i])){
                    s.pop();
                    asteroids[i]=0;
                }
            }
            if(asteroids[i]!=0) s.push(asteroids[i]);
        }
        vector<int> ans;
       while(!s.empty()){
           if(s.top()!=0)ans.push_back(s.top());
           s.pop();
       }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};