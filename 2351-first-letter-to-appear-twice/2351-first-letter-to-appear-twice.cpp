class Solution {
public:
    char repeatedCharacter(string s) {
        char c = '\0'; // Initialize c with a default value
        vector<int> letter(26, 0);
        for (int i = 0; i < s.length(); i++) {
            letter[s[i] - 'a']++;
            if (letter[s[i] - 'a'] == 2) {
                c = s[i];
                break; // Break the loop since we found the repeated character
            }
        }
        return c;
    }
};
