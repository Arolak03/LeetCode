class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);

        for (int i = 2; i <= rowIndex; i++) {
            int prev = 1; // Store the previous value of the row
            for (int j = 1; j < i; j++) {
                int temp = row[j]; // Store the current value of the row
                row[j] += prev; // Update the current value using the previous value
                prev = temp; // Update the previous value for the next iteration
            }
        }

        return row;
    }
};
