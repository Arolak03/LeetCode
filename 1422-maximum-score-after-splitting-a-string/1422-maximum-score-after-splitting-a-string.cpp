class Solution {
public:
    int maxScore(std::string s) {
        int n = s.length();
        int maxScore = 0;

        for (int j = 1; j < n; j++) {
            string left = s.substr(0, j);
            string right = s.substr(j, n - j);

            int leftCount = count(left.begin(), left.end(), '0');
            int rightCount = count(right.begin(), right.end(), '1');

            int currentScore = leftCount + rightCount;
            maxScore = max(maxScore, currentScore);
        }

        return maxScore;
    }
};