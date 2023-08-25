class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(auto nums: arr){
            freq[nums]++;
        }
        unordered_set<int> unique;
        for(auto &num: freq){
            if(unique.count(num.second)>0){
                return false;
            }
            unique.insert(num.second);
        }
        return true;
    }
};