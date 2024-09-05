class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(); // Number of rows (and columns) in the matrix

        vector<int> prev(n, 0); // Represents the previous row's minimum path sums
        vector<int> cur(n, 0);  // Represents the current row's minimum path sums

        // Initialize the first row (base condition)
        for (int j = 0; j < n; j++) {
            prev[j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Calculate the minimum path sum for the current cell considering three possible directions: up, left diagonal, and right diagonal

                // Up direction
                int up = matrix[i][j] + prev[j];

                // Left diagonal direction (if it's a valid move)
                int leftDiagonal = matrix[i][j];
                if (j - 1 >= 0) {
                    leftDiagonal += prev[j - 1];
                } else {
                    leftDiagonal = INT_MAX; // An invalid move represented by infinity for min calculation
                }

                // Right diagonal direction (if it's a valid move)
                int rightDiagonal = matrix[i][j];
                if (j + 1 < n) {
                    rightDiagonal += prev[j + 1];
                } else {
                    rightDiagonal = INT_MAX; // An invalid move represented by infinity for min calculation
                }

                // Store the minimum of the three paths in the current row
                cur[j] = min(up, min(leftDiagonal, rightDiagonal));
            }

            // Update the 'prev' array with the values from the 'cur' array for the next iteration
            prev = cur;
        }

        // Find the minimum value in the last row of 'prev', which represents the minimum path sums ending at each cell
        int mini = INT_MAX;
        for (int j = 0; j < n; j++) {
            mini = min(mini, prev[j]);
        }

        // The minimum path sum is the minimum value in the last row of 'prev'
        return mini;
    }
};
