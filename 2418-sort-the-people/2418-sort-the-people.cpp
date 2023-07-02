class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string, int>> helper;
        for(int i=0; i<names.size(); i++){
            helper.push_back({names[i], heights[i]});
        }

        sort(helper.begin(), helper.end(), [](pair<string, int> &a, pair<string, int> &b){
            return a.second > b.second;
        });

        vector<string> ans;
        for(int i=0; i<helper.size(); i++){
            ans.push_back(helper[i].first);
        }
        return ans;
    }
};