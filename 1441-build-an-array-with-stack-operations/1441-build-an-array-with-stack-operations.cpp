class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int targetIndex = 0;

        for (int i = 1; i <= n && targetIndex < target.size(); i++) {
            ans.push_back("Push");
            if (target[targetIndex] == i) {
                targetIndex++;
            } else {
                ans.push_back("Pop");
            }
        }

        return ans;
    }
};
