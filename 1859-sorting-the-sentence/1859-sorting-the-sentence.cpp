#include <string>
#include <sstream>
#include <vector>

class Solution {
public:
    std::string sortSentence(std::string s) {
        std::vector<std::string> words(10); // Assuming there are at most 10 words

        std::istringstream iss(s);
        std::string word;
        while (iss >> word) {
            int index = word.back() - '0';
            words[index] = word.substr(0, word.size() - 1);
        }

        std::string ans = "";
        for (const auto& w : words) {
            if (!w.empty()) {
                ans += w + ' ';
            }
        }

        ans.pop_back(); // Remove the trailing space
        return ans;
    }
};
