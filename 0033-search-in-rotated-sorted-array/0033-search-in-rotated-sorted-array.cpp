class Solution {
private:
    int bs(vector<int> nums, int left, int right, int target) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int n = nums.size();
        int right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[n-1]) {
                // Right part is rotated, move to the right
                left = mid + 1;
            } else {
                right = mid-1;
            }
        }
        // Now 'left' is the pivot point

        int ans = bs(nums, 0, left - 1, target);
        if (ans != -1) {
            return ans;
        }

        // Return the result of the second binary search directly
        return bs(nums, left, n - 1, target);
    }
};
