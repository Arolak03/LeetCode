class Solution {
public:
    vector<int> lexicalOrder(int n) {
       
        vector<int> result;
        int current = 1;
        
        for (int i = 1; i <= n; ++i) {
            result.push_back(current);
            
            if (current * 10 <= n) {
                current *= 10;
            } else if (current % 10 != 9 && current + 1 <= n) {
                current++;
            } else {
                while ((current / 10) % 10 == 9) {
                    current /= 10;
                }
                current = current / 10 + 1;
            }
        }
        
        return result;
    }
};
