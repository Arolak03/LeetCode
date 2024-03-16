class Solution {
public:
  int findMaxLength(vector<int>& nums) {
    int maxLength = 0;
    int sum = 0;  // Keep track of the prefix sum (number of 1s minus number of 0s)
    unordered_map<int, int> map; // Map sum to the first index seen with that sum

    map[0] = -1; // Initialize with sum 0 and index -1 (no previous occurrence)

    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i] == 1 ? 1 : -1;  // Add 1 for 1s, subtract 1 for 0s

      // Check if the current sum has been seen before
      if (map.count(sum)) {
        maxLength = max(maxLength, i - map[sum]);  // Update if current subarray is longer
      } else {
        map[sum] = i;  // Add the current sum and its index to the map
      }
    }

    return maxLength;
  }
};
