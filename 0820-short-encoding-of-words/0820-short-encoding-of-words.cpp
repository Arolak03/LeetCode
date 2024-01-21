#include <set>
#include <string>
#include <vector>

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> s(words.begin(), words.end());

        for (auto word : words) {
            for (int i = 1; i < word.length(); i++) {
                s.erase(word.substr(i));
            }
        }

        int ans = 0;
        for (const string& word : s) {
            ans += word.length() + 1; // Adding 1 for the '#' symbol
        }
        return ans;
    }
};
