#include <iostream>
#include <vector>
#include <algorithm> // For std::min

using namespace std;

// Function to calculate the minimum path sum using dynamic programming (tabulation)
int minPathSum(const vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    
    // Create a DP table to store the minimum path sum for each cell
    vector<vector<int>> dp(m, vector<int>(n, 0));
    
    // Initialize the DP table with the value of the grid's top-left corner
    dp[0][0] = grid[0][0];
    
    // Fill the first row (can only come from the left)
    for (int j = 1; j < n; ++j) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    
    // Fill the first column (can only come from the top)
    for (int i = 1; i < m; ++i) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    
    // Fill the rest of the DP table
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    
    return dp[m - 1][n - 1]; // Return the minimum path sum to reach the bottom-right corner
}

int main() {
    // Example grid
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    int minSum = minPathSum(grid);

    cout << "Minimum path sum is: " << minSum << endl;

    return 0;
}
