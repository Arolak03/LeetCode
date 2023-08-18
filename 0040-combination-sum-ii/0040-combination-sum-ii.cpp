class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> comb;
        
        unordered_map<int, int> counter;
        for (int candidate : candidates) {
            if (counter.find(candidate) != counter.end())
                counter[candidate]++;
            else
                counter[candidate] = 1;
        }

        vector<pair<int, int>> counterList;
        for (auto entry : counter) {
            counterList.push_back(make_pair(entry.first, entry.second));
        }

        backtrack(comb, target, 0, counterList, results);
        return results;
    }

    void backtrack(vector<int>& comb,
                   int remain, int curr,
                   vector<pair<int, int>>& counter,
                   vector<vector<int>>& results) {

        if (remain <= 0) {
            if (remain == 0) {
                results.push_back(comb);
            }
            return;
        }

        for (int nextCurr = curr; nextCurr < counter.size(); ++nextCurr) {
            int candidate = counter[nextCurr].first;
            int freq = counter[nextCurr].second;

            if (freq <= 0)
                continue;

            comb.push_back(candidate);
            counter[nextCurr].second--;

            backtrack(comb, remain - candidate, nextCurr, counter, results);

            counter[nextCurr].second++;
            comb.pop_back();
        }
    }
};
