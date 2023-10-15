#include <vector>
#include <algorithm>

class Solution {
public:
//     int solve(vector<pair<int, int>>& arr, int n, int index, vector<pair<int, bool>>& vis) {
//         if (index >= arr.size())
//             return 0;

//         // Try including the current tap.
//         for (int i = arr[index].first; i <= arr[index].second; i++) {
//             vis[i] = make_pair(i, true);
//         }
//         int include = 1 + solve(arr, n, index + 1, vis);

//         // Try excluding the current tap.
//         for (int i = arr[index].first; i <= arr[index].second; i++) {
//             vis[i] = make_pair(i, false);
//         }
//         int exclude = solve(arr, n, index + 1, vis);

//         return min(include, exclude);
//     }

    int minTaps(int n, vector<int>& ranges) {
//         vector<pair<int, int>> arr;
//         vector<pair<int, bool>> vis(n + 1, make_pair(0, false));

//         for (int i = 0; i < ranges.size(); i++) {
//             int left = max(0, i - ranges[i]);
//             int right = min(n, i + ranges[i]);
//             arr.push_back({left, right});
//         }

//         sort(arr.begin(), arr.end());

//         int result = solve(arr, n, 0, vis);

//         return (result == INT_MAX) ? -1 : result;
        vector<int> arr(n+1,0);
        // index is start and value is endpoint
        for(int i=0;i<ranges.size();i++){
            if(ranges[i]==0)continue;
            int left = max(0,i-ranges[i]);
            arr[left]=max(arr[left],ranges[i]+i);
        }
        int ans=0;
        int end=0;
        int maxFarR=0;
        for(int i=0;end<n && i<arr.size(); end=maxFarR){
            //tap includes
            ans++;
            //sec wala first k end s km hona chahiye and max range
            while(i<arr.size() && i<=end){
                maxFarR=max(maxFarR,arr[i++]);
            }
            if(end==maxFarR)return -1;
        }
        return ans;

    }
};
