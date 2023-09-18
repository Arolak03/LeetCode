#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Compare {
public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyMap;
        for (int num : nums) {
            frequencyMap[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        for (const auto& pair : frequencyMap) {
            pq.push(pair);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }

        reverse(ans.begin(), ans.end()); // Reverse the order to get most frequent first
        return ans;
    }
};
