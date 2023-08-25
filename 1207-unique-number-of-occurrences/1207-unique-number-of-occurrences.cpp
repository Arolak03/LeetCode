class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> freq;
        int i = 0;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        while (i < n) {
            int count = 1; // Initialize count to 1 for the current element.
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                }
            }
            cout<<count<<endl;
            freq.push_back(count);
            i+=count;
        }

        sort(freq.begin(), freq.end());
        cout<<freq.size();
        for (int i = 1; i < freq.size(); i++) {
            cout<<freq[i];
            if (freq[i] == freq[i - 1]) {
                return false;
            }
        }
        return true;
    }
};
