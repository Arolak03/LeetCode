class Solution {
public:
    
    void solve(string& s, vector<vector<string>>& ans, vector<string>& op, int index) {
        int n = s.length();
        if (index >= n) {
            ans.push_back(op);
            return;
        }
        
        for (int i = index; i < n; ++i) {
            string sub = s.substr(index, i - index + 1);
            if (isPalindrome(sub)) {
                op.push_back(sub);
                solve(s, ans, op, i + 1);
                op.pop_back();
            }
        }
    } 
    
    bool isPalindrome(const string& s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> op;
        solve(s, ans, op, 0);
        return ans;
    }
};
