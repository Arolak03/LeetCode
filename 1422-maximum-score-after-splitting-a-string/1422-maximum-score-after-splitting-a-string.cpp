class Solution {
public:
    int maxScore(std::string s) {
        int n = s.length();
        int maxScore = 0;

        for (int j = 1; j < n; j++) {
            std::string left = s.substr(0, j);
            std::string right = s.substr(j, n - j);

            int leftCount = std::count(left.begin(), left.end(), '0');
            int rightCount = std::count(right.begin(), right.end(), '1');

            int currentScore = leftCount + rightCount;
            maxScore = std::max(maxScore, currentScore);
        }

        return maxScore;
    }
};