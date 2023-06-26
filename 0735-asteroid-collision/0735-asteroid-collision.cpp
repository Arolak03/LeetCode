class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> asteroidstack;
        for(int asteroid : asteroids){
        while (!asteroidstack.empty() && asteroid<0 && asteroidstack.top()>0){
            int diff = asteroid + asteroidstack.top();
            if(diff<0){
                asteroidstack.pop();
            }
            else if(diff>0){
                asteroid=0;
                break;
            }
            else{
                asteroid=0;
                asteroidstack.pop();
            }
        }
        if(asteroid!=0){
            asteroidstack.push(asteroid);
        }
        }
        vector<int>arr(asteroidstack.size());
        int i = asteroidstack.size()-1;
        while(!asteroidstack.empty()){
            arr[i--]= asteroidstack.top();
            asteroidstack.pop();
        }
        return arr;
    }
};