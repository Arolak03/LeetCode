class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> asteroidStack;
        
        for(int asteroid: asteroids){
            while(!asteroidStack.empty() && asteroid<0 && asteroidStack.top()>0){
                int diff = asteroid + asteroidStack.top();
                // if positive then asteroid bada
                if(diff <0){
                    asteroidStack.pop();
                    // break;
                    // asteroidStack.push(asteroid);
                }
                else if(diff >0){
                    asteroid =0;
                    break;
                }
                else{
                    asteroid=0;
                    asteroidStack.pop();
                }
            }
            if(asteroid!=0){
                asteroidStack.push(asteroid);
            }
        }
            // asteroid left daalege
            vector<int> arr(asteroidStack.size());
            int n = asteroidStack.size()-1;
            while(!asteroidStack.empty()){
                arr[n--]=asteroidStack.top();
                asteroidStack.pop();
            }
            
            
        
        return arr;
    }
};