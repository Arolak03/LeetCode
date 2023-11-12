
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> targetFreq, currentFreq;
        for (char c : t) {
            targetFreq[c]++;
        }

        int left = 0, right = 0;
        int requiredChars = targetFreq.size();
        int formedChars = 0;
        int minLen = INT_MAX;
        int minStart = 0;  // Start index of the minimum window substring
        bool found = false;

        while (right < s.length()) {
            char currentChar = s[right];

            if (targetFreq.count(currentChar)) {
                currentFreq[currentChar]++;
                if (currentFreq[currentChar] == targetFreq[currentChar]) {
                    formedChars++;
                }
            }

            while (formedChars == requiredChars) {
                int currentLen = right - left + 1;
                if (currentLen < minLen) {
                    minLen = currentLen;
                    minStart = left;
                    found = true;
                }

                char leftChar = s[left];
                if (targetFreq.count(leftChar)) {
                    currentFreq[leftChar]--;
                    if (currentFreq[leftChar] < targetFreq[leftChar]) {
                        formedChars--;
                    }
                }

                left++;
            }

            right++;
        }

        return found ? s.substr(minStart, minLen) : "";
    }
};