class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            s.push_back(to_string(nums[i]));
        }
        
        // Custom comparison function to compare two strings
        auto compare = [](const string& a, const string& b) {
            return a + b > b + a;
        };
        
        // Sort using the custom comparison function
        sort(s.begin(), s.end(), compare);
        
        // Concatenate the sorted strings
        string str;
        for (int i = 0; i < n; i++) {
            str += s[i];
        }
        
        // Check if the result should be "0"
        if (str[0] == '0') {
            return "0";
        }
        
        return str;
    }
};
