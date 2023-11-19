class Solution {
public:
    int maximumSwap(int n) {
        
    string str = to_string(n);
    int l = str.length();
    int maxi;

    for (int i = 0; i < l; i++) {
        maxi = i;
        for (int j = i + 1; j < l; j++) {
            if (str[j] >= str[maxi]) {
                maxi = j;
            }
        }
        if (str[maxi] != str[i]) {
            swap(str[i], str[maxi]);
            // Check if the swapped number is greater than the original number
            if (stoi(str) > n) {
                return stoi(str);
            } else {
                // If not, revert the swap and continue searching
                swap(str[i], str[maxi]);
            }
        }
    }

    return n; // If no valid swap is found, return the original number

    }
};