class Solution {
private:
    int findMax(int number){
        int maxDigit = INT_MIN;
        while(number > 0){
            maxDigit = max(maxDigit, number % 10);
            number /= 10;
        }
        return maxDigit;
    }
    
public:
    int maxSum(vector<int>& nums) {
        // Intution
        // The idea in here is really very simple. We will find the maximum digit of a number and then add it to the map
        unordered_map<int, vector<int>> mp;
        for(auto &num : nums){
            int digit = findMax(num);
            if(mp.find(digit) == mp.end()){
                mp[digit] = {num};
            }
            else{
                mp[digit].push_back(num);
            }
        }
        int answer = -1;
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            vector<int> curr = itr->second;
            sort(curr.begin(), curr.end());
            if(curr.size() == 1) continue;
            answer = max(answer, curr[curr.size() - 1] + curr[curr.size() - 2]);
        }
        return answer;
    }
};