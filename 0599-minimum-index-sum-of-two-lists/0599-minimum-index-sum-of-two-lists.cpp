class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        int index1 = INT_MAX; // Initialize with a large value
        for (int i = 0; i < list1.size(); i++) {
            for (int j = 0; j < list2.size(); j++) {
                if (list1[i] == list2[j]) {
                    int indexSum = i + j;
                    if (indexSum < index1) {
                        ans.clear();
                        ans.push_back(list1[i]);
                        index1 = indexSum;
                    } else if (indexSum == index1) {
                        ans.push_back(list1[i]);
                    }
                }
            }
        }

        // Sort the result lexicographically
        sort(ans.begin(), ans.end());
        return ans;
    }
};
