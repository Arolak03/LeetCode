class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // int findKthLargest(vector<int>& nums, int k) {
        // Create a min heap (priority queue)
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Iterate through the elements in nums
        for (int num : nums) {
            // Push the current element into the min heap
            minHeap.push(num);

            // If the size of the min heap exceeds k, pop the smallest element
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // The kth largest element is at the top of the min heap
        return minHeap.top();
}
};
