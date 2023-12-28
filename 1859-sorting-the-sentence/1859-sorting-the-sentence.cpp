#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        vector<string> mpp(10);
        int n = s.length();
        for (int i = n - 1; i >= 0; i--) {
            int temp = i;
            if ('0' <= s[i] && s[i] <= '9') {
                while (temp >= 0 && '0' <= s[temp] && s[temp] <= '9') {
                    temp--;
                }
                int place = stoi(s.substr(temp + 1, i - temp));  // Corrected substring indices
                string word = "";
                while (temp >= 0 && s[temp] != ' ') {
                    word += s[temp];
                    temp--;
                }
                reverse(word.begin(), word.end());
                mpp[place] = word;
            }
        }
        string ans = "";
        for (int i = 1; i < mpp.size(); i++) {  // Start from index 1
            ans += mpp[i];
            if (i < mpp.size() - 1 && !mpp[i + 1].empty()) {
                ans += ' ';
            }
        }
        return ans;
    }
};
